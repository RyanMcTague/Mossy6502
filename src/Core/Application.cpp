
#include "Mossy6502/Core/Application.h"
#include "Mossy6502/Core/Constants.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

Application *Application::m_instance = nullptr;

Application::Application()
{
    m_imguiWindowFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    m_isRunning = true;
    m_renderer = nullptr;
    m_window = nullptr;
}

Application *Application::Get()
{
    if (!m_instance)
    {
        m_instance = new Application();
    }
    return m_instance;
}

void Application::Destroy()
{
    delete m_instance;
}

ImGuiIO *Application::GetIO() const
{
    return m_io;
}

void Application::Run()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        spdlog::critical("Could not initialize SDL");
        std::cout << SDL_GetError() << std::endl;
        m_isRunning = false;
        return;
    }

    m_window = SDL_CreateWindow(Constants::WINDOW_TITLE,
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT,
                                SDL_WINDOW_ALLOW_HIGHDPI);

    if (!m_window)
    {
        spdlog::critical("Could not create window");
        std::cout << SDL_GetError() << std::endl;
        m_isRunning = false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    if (!m_renderer)
    {
        spdlog::critical("Could not create renderer");
        std::cout << SDL_GetError() << std::endl;
        m_isRunning = false;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    m_io = &io;
    m_io->IniFilename = nullptr;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    ImGui::StyleColorsDark();

    m_io->Fonts->AddFontFromFileTTF("resources/fonts/PixeloidSans.ttf", 15.0f);

    ImGui_ImplSDL2_InitForSDLRenderer(m_window, m_renderer);
    ImGui_ImplSDLRenderer2_Init(m_renderer);

    while (m_isRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                m_isRunning = false;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE &&
                event.window.windowID == SDL_GetWindowID(m_window))
                m_isRunning = false;
        }

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        DrawGUI();
        ImGui::Render();
        SDL_RenderSetScale(m_renderer, m_io->DisplayFramebufferScale.x, m_io->DisplayFramebufferScale.y);
        SDL_RenderClear(m_renderer);
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
        SDL_RenderPresent(m_renderer);
    }

    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    if (m_renderer)
        SDL_DestroyRenderer(m_renderer);
    if (m_window)
        SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Application::DrawGUI()
{
    ImVec2 windowSize = m_io->DisplaySize;
    ImGui::SetNextWindowSize(windowSize);
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::Begin("Window", nullptr, m_imguiWindowFlags);
    ImGui::Button("Hello World");
    ImGui::End();
}

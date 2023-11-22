#pragma once

#include "Mossy6502/Core/Base.h"
#include "Mossy6502/Core/Application.h"
#include "imgui.h"

class Application
{
private:
    bool m_isRunning;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    ImGuiWindowFlags m_imguiWindowFlags;
    static Application *m_instance;
    Application();
    ImGuiIO *m_io;

    void DrawGUI();

public:
    static Application *Get();
    static void Destroy();
    void Run();
    ImGuiIO *GetIO() const;
};
//
// Created by Ryan on 11/22/23.
//

#ifndef MOSSY6502_APPLICATION_H
#define MOSSY6502_APPLICATION_H

#include "Base.h"
#include "imgui.h"

class Application {
private:
    bool m_isRunning;

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    static Application* m_instance;
    Application() noexcept;
    ImGuiIO* m_io;
public:
    static Application* Get();
    static void Destroy();
    void Run();
    ImGuiIO* GetIO() const;
};


#endif //MOSSY6502_APPLICATION_H

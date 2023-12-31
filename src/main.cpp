#include "Mossy6502/Core/Base.h"
#include "Mossy6502/Core/Application.h"

int main(int argc, char **argv)
{
    spdlog::set_level(spdlog::level::debug);
    spdlog::set_pattern("[%H:%M:%S] %^%l%$ %v");
    auto *app = Application::Get();
    app->Run();
    Application::Destroy();
    return 0;
}
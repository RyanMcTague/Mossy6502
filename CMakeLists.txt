cmake_minimum_required(VERSION 3.26)

project(Mossy6502)

set(CMAKE_CXX_STANDARD 17)

find_package(spdlog REQUIRED)

find_package(SDL2 REQUIRED)

file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

add_executable(Mossy6502
        ./src/main.cpp
        ./src/Core/Application.cpp
        ./src/Core/Utility.cpp

        ./vendor/imgui/imgui_demo.cpp
        ./vendor/imgui/imgui_draw.cpp
        ./vendor/imgui/imgui_tables.cpp
        ./vendor/imgui/imgui_widgets.cpp
        ./vendor/imgui/imgui.cpp
        ./vendor/imgui/backends/imgui_impl_sdl2.cpp
        ./vendor/imgui/backends/imgui_impl_sdlrenderer2.cpp
)

target_include_directories(Mossy6502 PRIVATE 
        ./include 
        ./vendor/imgui 
        ./vendor/imgui/backends
        ./vendor/imgui_club/imgui_memory_editor
        ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(Mossy6502 spdlog::spdlog ${SDL2_LIBRARIES})
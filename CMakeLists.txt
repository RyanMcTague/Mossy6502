cmake_minimum_required(VERSION 3.26)

project(Mossy6502)

set(CMAKE_CXX_STANDARD 17)

find_package(spdlog REQUIRED)

find_package(SDL2 REQUIRED)

set(IMGUI_SOURCE_FILES
        ./vendor/imgui/imgui_demo.cpp
        ./vendor/imgui/imgui_draw.cpp
        ./vendor/imgui/imgui_tables.cpp
        ./vendor/imgui/imgui_widgets.cpp
        ./vendor/imgui/imgui.cpp
        ./vendor/imgui/backends/imgui_impl_sdl2.cpp
        ./vendor/imgui/backends/imgui_impl_sdlrenderer2.cpp
        src/Core/Base.h
        src/Core/Application.cpp
        src/Core/Application.h
        src/Core/Constants.h
)

set(IMGUI_HEADER_FILES ./vendor/imgui  ./vendor/imgui/backends)

add_executable(Mossy6502
        src/main.cpp
        ${IMGUI_SOURCE_FILES}
)

target_include_directories(Mossy6502 PRIVATE ${SDL2_INCLUDE_DIRS} ${IMGUI_HEADER_FILES})

target_link_libraries(Mossy6502 spdlog::spdlog ${SDL2_LIBRARIES})
cmake_minimum_required(VERSION 3.17)
project(satireFSUTIL)

set(CMAKE_CXX_STANDARD 17)

file(GLOB sources
        "src/dx11/imgui/*.cpp"
        "src/dx11/imgui/*.h"
        "src/dx11/gui/*.cpp"
        "src/dx11/gui/*.h"
        "src/entry/*.cpp"
        "src/entry/*.h"
        "src/modules/*.cpp"
        "src/modules/*.h")


add_executable(satireFSUTIL ${sources} src/dx11/render/render.cpp src/dx11/render/render.h src/entry/main.h src/dx11/gui/gui.cpp src/dx11/gui/gui.h)
target_link_libraries(satireFSUTIL d3d11)
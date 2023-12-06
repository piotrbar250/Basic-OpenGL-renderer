cmake_minimum_required(VERSION 3.0.0)
project(app VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)
find_package(OpenGL REQUIRED)

add_executable(app
    src/Application.cpp
    src/glad.c
    src/Renderer.h
    src/Renderer.cpp    
    
    src/VertexBuffer.h
    src/VertexBuffer.cpp    
    src/ElementBuffer.h
    src/ElementBuffer.cpp
    src/VertexArray.h
    src/VertexArray.cpp
    src/VertexBufferLayout.h

    src/Shader.h
    src/Shader.cpp
)

target_link_libraries(app
    glfw
    OpenGL::GL
)

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Renderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include "VertexBufferLayout.h"
using namespace std;

int main()
{
    GLFWwindow* window;

    if(!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1000, 1000, "Window", NULL, NULL);
    glfwMakeContextCurrent(window);

    // glfwSwapInterval(1);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Cound't load opengl" << endl;
        glfwTerminate();
        return -1; 
    }
    // VertexArray vao;
    // VertexBuffer vbo(data, size)
    // VertexBufferLayout layout;
    // layout.Push<float>(2);
    // vao.AddBuffer(vbo, layout);
    // ElementBuffer ebo(data, count)


    glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        // vao.bind()
        // ebo.bind();

        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}
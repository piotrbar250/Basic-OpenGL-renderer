#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Renderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"

using namespace std;

int main()
{
    GLFWwindow *window;

    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1000, 1000, "Window", NULL, NULL);
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Cound't load opengl" << endl;
        glfwTerminate();
        return -1;
    }
    float positions[] = {
        -0.5f, -0.5f, // 0
        0.5f, -0.5f,  // 1
        0.5f, 0.5f,   // 2
        -0.5f, 0.5f,  // 3
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0 // check order!!!!!
    };

    VertexArray VAO;
    VertexBuffer VBO(positions, 4 * 2 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(2);
    VAO.AddBuffer(VBO, layout);

    ElementBuffer EBO(indices, 6);
    // EBO.Bind();

    Shader shader("../res/shaders/Basic.glsl"); // default path
    shader.Bind();
    shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

    VAO.Unbind();
    VBO.Unbind();
    EBO.Unbind();
    shader.Unbind();

    float r = 0.0f;
    float increment = 0.05f;

    Renderer renderer;

    while (!glfwWindowShouldClose(window))
    {
        renderer.Clear();
 
        shader.Bind(); // is this needed?
        shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

        renderer.Draw(VAO, EBO, shader);

        if (r > 1.0f)
            increment = -0.05f;
        else if (r < 0.0f)
            increment = 0.05f;
        r += increment;

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
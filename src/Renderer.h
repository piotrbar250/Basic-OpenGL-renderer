#pragma once

// #include "GL/glew.h"
#include <glad/glad.h>
#include "VertexArray.h"
#include "ElementBuffer.h"
#include "Shader.h"

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

static bool GLLogCall(const char* function, const char* file, int line);

class Renderer
{
public:
    void Clear() const;
    void Draw(const VertexArray& VAO, const ElementBuffer& EBO, const Shader& shader) const;
};
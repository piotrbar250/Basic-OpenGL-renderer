#pragma once

// #include "GL/glew.h"
#include <glad/glad.h>

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

static bool GLLogCall(const char* function, const char* file, int line);

void hello();
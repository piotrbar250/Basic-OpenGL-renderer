#pragma once
#include <glad/glad.h>
#include <vector>
#include <stdexcept> 

#include <iostream>
using namespace std;

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSizeOfType(unsigned int type)
    {
        switch(type)
        {
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }
        throw std::runtime_error("unknown type");
    }
};

class VertexBufferLayout
{
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;
public:
    VertexBufferLayout() : m_Stride(0) {}

    template <typename T>
    void Push(unsigned int count)
    {
        static_assert(std::is_same<T, float>::value ||
                      std::is_same<T, unsigned int>::value ||  
                      std::is_same<T, unsigned char>::value,
                      "Unsupported type for VertexBufferLayout::Push");
    }
    inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }
    inline unsigned int getStride() const { return m_Stride; }
};

template <>
inline void VertexBufferLayout::Push<float>(unsigned int count)
{        
    m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
    m_Stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
}

template <>
inline void VertexBufferLayout::Push<unsigned int>(unsigned int count)
{
    m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
    m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
}

template <>
inline void VertexBufferLayout::Push<unsigned char>(unsigned int count)
{
    m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
    m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
}
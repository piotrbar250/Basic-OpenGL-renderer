#include "VertexArray.h"
#include <vector>

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_RenderID);
}

VertexArray::~VertexArray()
{
}

void VertexArray::AddBuffer(const VertexBuffer &vbo, const VertexBufferLayout &layout)
{
    Bind();
    vbo.Bind();
    const std::vector<VertexBufferElement>& elements = layout.GetElements();
    unsigned int offset = 0;
    for(unsigned int i = 0; elements.size(); i++)
    {
        const auto& element = elements[i];
        // glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void*)offset);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), reinterpret_cast<const void*>(static_cast<std::uintptr_t>(offset)));
        glEnableVertexAttribArray(i);
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}

void VertexArray::Bind() const
{
    glBindVertexArray(m_RenderID);
}

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}

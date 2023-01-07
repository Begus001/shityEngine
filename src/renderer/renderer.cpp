#include <renderer/renderer.h>

namespace se
{

Renderer::Renderer() : mMode(DM_TRIANGLES) {}

Renderer::~Renderer() {}

void Renderer::drawElem(VAO &vao, int count) const
{
	vao.bind();
	GLCALL(glDrawElements(mMode, count, GL_UNSIGNED_INT, nullptr));
}

void Renderer::drawArray(VAO &vao, int count) const
{
	vao.bind();
	GLCALL(glDrawArrays(mMode, 0, count));
}

void Renderer::clear() const
{
	GLCALL(glClear(GL_COLOR_BUFFER_BIT));
}

DrawMode Renderer::getMode() const
{
	return mMode;
}

void Renderer::setMode(DrawMode mode)
{
	mMode = mode;
}

void Renderer::setClearColor(float r, float g, float b, float a) const
{
	GLCALL(glClearColor(r, g, b, a));
}

}
#pragma once

#include "vbo.h"
#include "ebo.h"
#include "vao.h"
#include "shader.h"

namespace se
{

enum DrawMode {
	DM_LINES = GL_LINES, DM_TRIANGLES = GL_TRIANGLES
};

class Renderer {
public:
	Renderer();
	~Renderer();

	void drawElem(VAO &vao, int count) const;

	void drawArray(VAO &vao, int count) const;

	void clear() const;

	DrawMode getMode() const;

	void setMode(DrawMode mode);
	void setClearColor(float r, float g, float b, float a) const;

private:
	DrawMode mMode;
};

}
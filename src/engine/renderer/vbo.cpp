#include "vbo.h"

namespace se
{

VBO::VBO(const void *data, unsigned int size, BufferMode mode)
{
	GLCALL(glGenBuffers(1, &mID));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, mID));
	setData(data, size, mode);
}

VBO::~VBO()
{
	GLCALL(glDeleteBuffers(1, &mID));
}

void VBO::bind() const
{
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, mID));
}

void VBO::unbind() const
{
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void VBO::setData(const void *data, unsigned int size, BufferMode mode) const
{
	GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, mode));
}

unsigned int VBO::getID() const
{
	return mID;
}

}
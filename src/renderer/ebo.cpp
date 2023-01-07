#include <renderer/ebo.h>

namespace se
{

EBO::EBO(const void *data, unsigned int size, BufferMode mode)
{
	GLCALL(glGenBuffers(1, &mID));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mID));
	setData(data, size, mode);
}

EBO::~EBO()
{
	GLCALL(glDeleteBuffers(1, &mID));
}

void EBO::bind() const
{
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mID));
}

void EBO::unbind() const
{
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

void EBO::setData(const void *data, unsigned int size, BufferMode mode) const
{
	GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, mode));
}

unsigned int EBO::getID() const
{
	return mID;
}

}
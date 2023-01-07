#pragma once

#include "common.h"

namespace se 
{

class VBO {
public:
	VBO(const void *data, unsigned int size, BufferMode mode = BufferMode::BM_STATIC);
	~VBO();

	void bind() const;
	void unbind() const;

	void setData(const void *data, unsigned int size, BufferMode mode = BufferMode::BM_STATIC) const;

	unsigned int getID() const;

private:
	unsigned int mID;
};

}
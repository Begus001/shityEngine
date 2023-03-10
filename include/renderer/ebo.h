#pragma once

#include "common.h"

namespace se
{

class EBO {
public:
	EBO(const void *data, unsigned int size, BufferMode mode = BufferMode::BM_STATIC);
	~EBO();

	void bind() const;
	void unbind() const;

	void setData(const void *data, unsigned int size, BufferMode mode = BufferMode::BM_STATIC) const;

	unsigned int getID() const;

private:
	unsigned int mID;
};

}
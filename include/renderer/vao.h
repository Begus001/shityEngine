#pragma once

#include "common.h"
#include "vbo.h"
#include <vector>

namespace se {

struct VBOAttribute {
	unsigned int type;
	unsigned int count;
	bool normalized;
};

class VBOLayout {
public:
	VBOLayout();

	template<typename T = float>
	void push(unsigned int count, bool normalized = false);

	std::vector<VBOAttribute> getAttributes() const;
	unsigned int getStride() const;

private:
	std::vector<VBOAttribute> mAttributes;
	unsigned int mStride;
};

class VAO {
public:
	VAO();
	~VAO();

	void bind() const;
	void unbind() const;

	void addVBO(const VBO &vbo, const VBOLayout &layout);

	unsigned int getID() const;

private:
	unsigned int mID;
};

}
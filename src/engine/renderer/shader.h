#pragma once

#include "common.h"

namespace se
{

class Shader {
public:
	Shader(const char *vShaderPath, const char *fShaderPath);
	~Shader();

	void bind() const;
	void unbind() const;

	bool compile() const;

	int getUniform(const char *name) const;

	unsigned int getProgID() const;

private:
	unsigned int mVertID;
	unsigned int mFragID;
	unsigned int mProgID;

	const char *load(const char *path) const;
};

}
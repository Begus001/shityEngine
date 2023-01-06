#pragma once

#include <unordered_map>

#include "common.h"

namespace se
{

enum UniformType {
	U4F, U3F
};

class Shader {
public:
	Shader(const char *vShaderPath, const char *fShaderPath);
	~Shader();

	void bind() const;
	void unbind() const;

	bool compile() const;

	template<enum UniformType T = U4F>
	void setUniform(const char *name, float f1, float f2, float f3, float f4);

	int getUniform(const char *name);

	unsigned int getProgID() const;

private:
	unsigned int mVertID;
	unsigned int mFragID;
	unsigned int mProgID;

	std::unordered_map<const char *, int> mUniformMap;

	const char *load(const char *path) const;
};

}
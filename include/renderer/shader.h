#pragma once

#include <unordered_map>

#include "common.h"

namespace se
{

enum UniformType {
	UT_1F, UT_2F, UT_3F, UT_4F, UT_1D
};

class Shader {
public:
	Shader(const char *vShaderPath, const char *fShaderPath);
	~Shader();

	void bind() const;
	void unbind() const;

	bool compile() const;

	template<UniformType T>
	void setUniform(const char *name, float f1);

	template<UniformType T>
	void setUniform(const char *name, float f1, float f2);

	template<UniformType T>
	void setUniform(const char *name, float f1, float f2, float f3);

	template<UniformType T>
	void setUniform(const char *name, float f1, float f2, float f3, float f4);

	template<UniformType T>
	void setUniform(const char *name, double d1);

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
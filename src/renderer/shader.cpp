#include <renderer/shader.h>

namespace se
{

Shader::Shader(const char *vShaderPath, const char *fShaderPath)
{
	GLCALL(mVertID = glCreateShader(GL_VERTEX_SHADER));
	GLCALL(mFragID = glCreateShader(GL_FRAGMENT_SHADER));

	const char *vShaderSrc = load(vShaderPath);
	const char *fShaderSrc = load(fShaderPath);

	GLCALL(glShaderSource(mVertID, 1, &vShaderSrc, nullptr));
	GLCALL(glShaderSource(mFragID, 1, &fShaderSrc, nullptr));

	free((char *)vShaderSrc);
	free((char *)fShaderSrc);

	GLCALL(mProgID = glCreateProgram());
}

Shader::~Shader()
{
	if (mVertID) GLCALL(glDeleteShader(mVertID));
	if (mFragID) GLCALL(glDeleteShader(mFragID));
	if (mProgID) GLCALL(glDeleteProgram(mProgID));
}

void Shader::bind() const
{
	GLCALL(glUseProgram(mProgID));
}

void Shader::unbind() const
{
	GLCALL(glUseProgram(0));
}

bool Shader::compile() const
{
	int success;
	char buf[512];

	GLCALL(glCompileShader(mVertID));

	GLCALL(glGetShaderiv(mVertID, GL_COMPILE_STATUS, &success));
	if (!success) {
		GLCALL(glGetShaderInfoLog(mVertID, 512, NULL, buf));
		fprintf(stderr, "Vertex shader compilation failed: %s\n", buf);
		return false;
	}

	memset(buf, 0, sizeof(buf));

	GLCALL(glCompileShader(mFragID));

	GLCALL(glGetShaderiv(mFragID, GL_COMPILE_STATUS, &success));
	if (!success) {
		GLCALL(glGetShaderInfoLog(mFragID, 512, NULL, buf));
		fprintf(stderr, "Fragment shader compilation failed: %s\n", buf);
		return false;
	}

	memset(buf, 0, sizeof(buf));
	
	GLCALL(glAttachShader(mProgID, mVertID));
	GLCALL(glAttachShader(mProgID, mFragID));
	GLCALL(glLinkProgram(mProgID));

	GLCALL(glGetProgramiv(mProgID, GL_LINK_STATUS, &success));
	if (!success) {
		GLCALL(glGetProgramInfoLog(mProgID, 512, NULL, buf));
		fprintf(stderr, "Shader program linking failed: %s\n", buf);
		return false;
	}

	bind();

	GLCALL(glDeleteShader(mVertID));
	GLCALL(glDeleteShader(mFragID));

	return true;
}

template<>
void Shader::setUniform<UT_1F>(const char *name, float f1)
{
	GLCALL(glUniform1f(getUniform(name), f1));
}

template<>
void Shader::setUniform<UT_2F>(const char *name, float f1, float f2)
{
	GLCALL(glUniform2f(getUniform(name), f1, f2));
}

template<>
void Shader::setUniform<UT_3F>(const char *name, float f1, float f2, float f3)
{
	GLCALL(glUniform3f(getUniform(name), f1, f2, f3));
}

template<>
void Shader::setUniform<UT_4F>(const char *name, float f1, float f2, float f3, float f4)
{
	GLCALL(glUniform4f(getUniform(name), f1, f2, f3, f4));
}

template<>
void Shader::setUniform<UT_1D>(const char *name, double d1)
{
	GLCALL(glUniform1d(getUniform(name), d1));
}

int Shader::getUniform(const char *name)
{
	if (mUniformMap.contains(name)) {
		return mUniformMap[name];
	}

	int uni;
	GLCALL(uni = glGetUniformLocation(mProgID, name));
	assert(uni > -1);

	mUniformMap[name] = uni;

	return uni;
}

unsigned int Shader::getProgID() const
{
	return mProgID;
}

const char* Shader::load(const char *path) const
{
	FILE *f = fopen(path, "r");

	assert(f);

	fseek(f, 0, SEEK_END);
	size_t len = ftell(f);
	fseek(f, 0, SEEK_SET);

	char *buf = (char *)malloc(len + 1);
	memset(buf, 0, len + 1);
	fread(buf, len, 1, f);

	fclose(f);

	return buf;
}

}
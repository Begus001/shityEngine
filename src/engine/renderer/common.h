#pragma once

#define GLEW_STATIC
#include <GL/glew.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#define GLCALL(x) \
do { \
	x; \
	unsigned int glErr; \
	bool isErr = false; \
	while ((glErr = glGetError()) != GL_NO_ERROR) { \
		fprintf(stderr, "gl error 0x%X at %s in %s:%d\n", glErr, #x, __FILE__, __LINE__); \
		isErr = true; \
	} \
	if (isErr) exit(1); \
} while (0);

namespace se
{
	enum BufferMode
	{
		BM_STATIC = GL_STATIC_DRAW, BM_DYNAMIC = GL_DYNAMIC_DRAW, BM_STREAM = GL_STREAM_DRAW
	};
}
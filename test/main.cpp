#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <shityEngine.h>
#include <logging/logging.h>
#include <imgui/imgui.h>

#include "test.h"
#include "testClear.h"

// float vertices[] = {
// 	-0.5f, -0.5f,
// 	0.5f, -0.5f,
// 	0.0f, 0.5f,
// };


// class TestMultiColorTriangle : public Test {
// public:
// 	TestMultiColorTriangle()
// 	{
// 		run("Test");
// 	}

// 	~TestMultiColorTriangle() override
// 	{
// 		delete mRenderer;
// 	}

// 	void onStart() override
// 	{
		
// 	}

// 	void onUpdate() override
// 	{

// 	}

// 	void onRender() override
// 	{

// 	}

// 	void onUIRender() override
// 	{

// 	}

// private:
// 	se::Renderer *mRenderer;
// 	se::Shader *shader;
// 	se::VAO *vao;
// 	se::VBO *vbo;
// };

int main(void)
{
	Test test;
	test.addTest<TestClear>("Clear test");
	test.run("Test");
}
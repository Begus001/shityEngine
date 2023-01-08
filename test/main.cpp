#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <shityEngine.h>
#include <renderer/renderer.h>

float vertices[] = {
	-0.5f, -0.5f,
	0.5f, -0.5f,
	0.0f, 0.5f,
};

class App : public se::ShityApplication {
public:
	App()
	{
		run("Test");
	}

	~App()
	{
		delete renderer;
		delete vao;
		delete vbo;
	}

	void onStart() override
	{
		vao = new se::VAO;
		
		vbo = new se::VBO(vertices, sizeof(vertices));

		se::VBOLayout lay;
		lay.push<float>(2);

		vao->addVBO(*vbo, lay);

		se::Shader shader("vertexShader.glsl", "fragmentShader.glsl");
		shader.compile();

		renderer = new se::Renderer;
	}

	void onUpdate() override
	{
	}

	void onRender() override
	{
		renderer->setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		renderer->clear();
		renderer->drawArray(*vao, 3);
	}

private:
	se::Renderer *renderer;
	se::VAO *vao;
	se::VBO *vbo;
};

int main(void)
{
	App app;
}
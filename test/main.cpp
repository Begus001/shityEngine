#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <renderer/renderer.h>

float vertices[] = {
	-0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
	-0.5f,  0.5f, 0.0f, 1.0f, 0.0f,
	 0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, 1.0f, 0.0f, 1.0f,
};

unsigned int indices[] = {
	0, 1, 3,
	1, 2, 3,
};

void fb_size_callback(GLFWwindow *window, int w, int h) { GLCALL(glViewport(0, 0, w, h)); }

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
		switch (key) {
		case GLFW_KEY_Q:
			glfwTerminate();
			exit(0);
			break;
		}
}

int main(void)
{
	if (!glfwInit()) {
		fprintf(stderr, "GLFW init failed\n");
		exit(1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE);


	GLFWwindow *win = glfwCreateWindow(1280, 720, "Test", NULL, NULL);

	if (!win) {
		fprintf(stderr, "GLFW window creation failed\n");
		exit(1);
	}

	glfwMakeContextCurrent(win);

	glfwSetKeyCallback(win, key_callback);

	glfwSetFramebufferSizeCallback(win, fb_size_callback);

	glewInit();

	char *version = (char *)glGetString(GL_VERSION);
	printf("OpenGL version: %s\n", version);
	
	se::VAO vao;
	se::VBO vbo(vertices, sizeof(vertices));
	se::EBO ebo(indices, sizeof(indices));

	se::VBOLayout layout;
	layout.push<float>(2);
	layout.push<float>(3);
	vao.addVBO(vbo, layout);

	se::Shader shader("vertexShader.glsl", "fragmentShader.glsl");
	shader.compile();

	se::Renderer renderer;

	vao.unbind();
	vbo.unbind();
	ebo.unbind();

	const double interval = 1.0 / 60.0;
	double startTime = glfwGetTime();

	while (!glfwWindowShouldClose(win)) {

		if (glfwGetTime() - startTime >= interval) {

			startTime = glfwGetTime();

			renderer.clear();

			shader.setUniform<se::UT_1D>("test", glfwGetTime());
			
			vbo.bind();
			vbo.setData(vertices, sizeof(vertices));

			renderer.drawElem(vao, sizeof(indices) / sizeof(*indices));
			
			glfwSwapBuffers(win);
			glfwPollEvents();
		}
	}

	glfwDestroyWindow(win);
	glfwTerminate();

	return 0;
}
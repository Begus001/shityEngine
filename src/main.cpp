#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "engine/renderer/renderer.h"

bool apressed = false, dpressed = false, wpressed = false, spressed = false;

float vertices[] = {
	-0.5, -0.5,
	-0.5,  0.5,
	 0.5,  0.5,
	 0.5, -0.5,
};

unsigned int indices[] = {
	0, 1, 3,
	1, 2, 3,
};

void fb_size_callback(GLFWwindow *window, int w, int h) { GLCALL(glViewport(0, 0, w, h)); }

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {
		switch (key) {
		case GLFW_KEY_A:
			apressed = true;
			break;
		case GLFW_KEY_D:
			dpressed = true;
			break;
		case GLFW_KEY_W:
			wpressed = true;
			break;
		case GLFW_KEY_S:
			spressed = true;
			break;
		case GLFW_KEY_Q:
			glfwTerminate();
			exit(0);
			break;
		}
	} else if (action == GLFW_RELEASE) {
		switch (key) {
		case GLFW_KEY_A:
			apressed = false;
			break;
		case GLFW_KEY_D:
			dpressed = false;
			break;
		case GLFW_KEY_W:
			wpressed = false;
			break;
		case GLFW_KEY_S:
			spressed = false;
			break;
		}
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
	layout.push(2);
	vao.addVBO(vbo, layout);

	se::Shader shader("src/vertexShader.glsl", "src/fragmentShader.glsl");
	shader.compile();

	float r = 1.0f, g = 0.0f, b = 0.0f;
	unsigned int state = 0;

	const double interval = 1.0 / 60.0;
	double startTime = glfwGetTime();

	vao.unbind();
	vbo.unbind();

	while (!glfwWindowShouldClose(win)) {

		if (glfwGetTime() - startTime >= interval) {

			startTime = glfwGetTime();

			GLCALL(glClear(GL_COLOR_BUFFER_BIT));

			if (apressed) {
				for (unsigned int i = 0; i < sizeof(vertices) / sizeof(float); i += 2)
					vertices[i] -= 0.01f;
			}
			if (dpressed) {
				for (unsigned int i = 0; i < sizeof(vertices) / sizeof(float); i += 2)
					vertices[i] += 0.01f;
			}
			if (wpressed) {
				for (unsigned int i = 1; i < sizeof(vertices) / sizeof(float); i += 2)
					vertices[i] += 0.01f;
			}
			if (spressed) {
				for (unsigned int i = 1; i < sizeof(vertices) / sizeof(float); i += 2)
					vertices[i] -= 0.01f;
			}

			shader.setUniform("color", r, g, b, 1.0f);
			
			vbo.bind();
			vbo.setData(vertices, sizeof(vertices));

			if (state == 0) {
				r -= 0.01f;
				g += 0.01f;
				if (r <= 0.0f || g >= 1.0f) {
					r = 0.0f;
					g = 1.0f;
					state = 1;
				}
			} else if (state == 1) {
				g -= 0.01f;
				b += 0.01f;
				if (g <= 0.0f || b >= 1.0f) {
					g = 0.0f;
					b = 1.0f;
					state = 2;
				}
			} else if (state == 2) {
				b -= 0.01f;
				r += 0.01f;
				if (b <= 0.0f || r >= 1.0f) {
					b = 0.0f;
					r = 1.0f;
					state = 0;
				}
			}

			
			vao.bind();
			GLCALL(glDrawElements(GL_TRIANGLES, sizeof(vertices), GL_UNSIGNED_INT, nullptr));
			glfwSwapBuffers(win);
			glfwPollEvents();
		}
	}

	glfwDestroyWindow(win);
	glfwTerminate();

	return 0;
}
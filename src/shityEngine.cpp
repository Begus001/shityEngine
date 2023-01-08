#include "shityEngine.h"

// #include <imgui/imgui.h>
// #include <imgui/imgui_impl_glfw.h>
// #include <imgui/imgui_impl_opengl3.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace se
{

void ShityApplication::run(std::string name)
{
	mName = name;

	if (!glfwInit()) {
		fprintf(stderr, "GLFW initialization failed\n");
		exit(1);
	}

	GLFWwindow *win = glfwCreateWindow(1280, 720, name.c_str(), nullptr, nullptr);

	if (!win) {
		fprintf(stderr, "GLFW window creation failed\n");
		exit(1);
	}

	glfwMakeContextCurrent(win);

	glewInit();

	printf("Run called\n");

	// IMGUI_CHECKVERSION();
    // ImGui::CreateContext();
    // ImGuiIO &io = ImGui::GetIO();
    // ImGui_ImplGlfw_InitForOpenGL(win, true);
    // ImGui_ImplOpenGL3_Init("#version 450");
    // ImGui::StyleColorsDark();

	onStart();
	
	while (!glfwWindowShouldClose(win)) {
		onUpdate();

		onRender();

		// ImGui_ImplOpenGL3_NewFrame();
        // ImGui_ImplGlfw_NewFrame();
        // ImGui::NewFrame();

		// ImGui::Begin("Demo window");
        // ImGui::Button("Hello!");
        // ImGui::End();

		glfwPollEvents();
		glfwSwapBuffers(win);
	}
}

}
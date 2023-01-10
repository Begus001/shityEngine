#include <renderer/common.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include "shityEngine.h"

namespace se
{

void ShityApplication::run(std::string name)
{
	mName = name;

	if (!glfwInit()) {
		fprintf(stderr, "GLFW initialization failed\n");
		exit(1);
	}

	Window win("Cock", 1920, 1080);

	glfwMakeContextCurrent(win.getHandle());

	glewInit();

	IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(win.getHandle(), true);
    ImGui_ImplOpenGL3_Init("#version 450 core");
    ImGui::StyleColorsDark();

	onStart();
	
	while (!glfwWindowShouldClose(win.getHandle())) {
		glfwPollEvents();
		onUpdate();

		ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

		onRender();

		onUIRender();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(win.getHandle());
	}
}

}
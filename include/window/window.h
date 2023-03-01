#pragma once

#include <string>
#include <memory>
#include <unordered_map>

#include <renderer/common.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace se
{

class Window {
public:
	Window(const std::string &name, int width, int height, bool vsync = true);
	~Window();

	void close();

	GLFWwindow *getHandle() const;

private:
	GLFWwindow *mHandle;
};
	
class WindowManager {
public:
	static Window createWindow(const std::string name, int width, int height, bool vsync = true);
	static Window getWindow(const std::string name);

private:
	static std::unordered_map<const std::string, Window> mWindows;
};

}
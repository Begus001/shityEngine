#include "window/window.h"

#include <logging/logging.h>

namespace se
{

Window::Window(const std::string &name, int width, int height, bool vsync)
{
	mHandle = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);

	if (!mHandle) {
		Log::e("Creation of window '%s' failed", name.c_str());
	} else {
		Log::d("Created window '%s' (%dx%d vsync=%d)", name.c_str(), width, height, vsync);
	}

	int left, top, right, bottom;
	glfwGetWindowFrameSize(mHandle, &left, &top, &right, &bottom);
}

Window::~Window()
{
	delete mHandle;
}

void Window::close()
{

}

GLFWwindow* Window::getHandle() const
{
	return mHandle;
}

Window WindowManager::createWindow(const std::string name, int width, int height, bool vsync)
{

}

Window WindowManager::getWindow(const std::string name)
{

}

}
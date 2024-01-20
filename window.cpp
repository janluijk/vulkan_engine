#include "window.hpp"

namespace vke {

VkeWindow::VkeWindow(int w, int h, std::string name)
    : width{w}, height{h}, windowName{name} {
			initWindow();
}

VkeWindow::~VkeWindow() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void VkeWindow::initWindow() {
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // No OpenGL context
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);

}

} // namespace vulkanEngine
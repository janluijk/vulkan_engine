#pragma once

#include <vulkan/vulkan_core.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace vke {

  class Window {
  public:
    Window(int width, int height, std::string name);
    ~Window();

    // copy constructor and copy assignment operator are deleted
    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    bool shouldClose() { return glfwWindowShouldClose(window); }
    VkExtent2D getExtend() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height)}; }
    bool wasWindowResized() { return frameBufferResized; }
    void resetWindowResizedFlag() { frameBufferResized = false; }
    void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

  private:
    static void framebufferResizeCallback(GLFWwindow *window, int width, int height);
    void initWindow();

    // Constructor variables
    int width;
    int height;
    bool frameBufferResized = false;

    std::string windowName;

    GLFWwindow *window;
  };
}

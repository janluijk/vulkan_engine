#include "first_app.hpp"

namespace vke {

void FirstApp::run() {
  while (!vkeWindow.shouldClose()) {
    glfwPollEvents();
  }
}

} // namespace vke
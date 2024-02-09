#include "app.hpp"
#include "simple_render_system.hpp"


// GLM 
#include <glm/exponential.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DELPTH_ZERO_TO_ONE

// Standard lib
#include <memory>
#include <vulkan/vulkan_core.h>

namespace vke {

App::App() { loadGameObjects(); }

App::~App() {}

void App::run() {
  SimpleRenderSystem simpleRenderSystem{device,
                                        renderer.getSwapChainRenderPass()};
  while (!window.shouldClose()) {
    glfwPollEvents();
    
    if (auto commandBuffer = renderer.beginFrame()) {
      renderer.beginSwapChainRenderPass(commandBuffer);
      simpleRenderSystem.renderGameObjects(commandBuffer, gameObjects);
      renderer.endSwapChainRenderPass(commandBuffer);
      renderer.endFrame();
    }
  }

  vkDeviceWaitIdle(device.device());
}

void App::loadGameObjects() {
  std::vector<Model::Vertex> vertices{{{0.0f, -1.0f}, {1.0f, 0.0f, 0.0f}},
                                      {{-0.86f, 0.5f}, {0.0f, 1.0f, 0.0f}},
                                      {{0.86f, 0.5f}, {0.0f, 0.0f, 1.0f}}};
  auto model = std::make_shared<Model>(device, vertices);

  std::vector<glm::vec3> colors{{0.96f, 0.88f, 0.86f},
                                {0.80f, 0.65f, 0.97f},
                                {0.95f, 0.55f, 0.66f},
                                {0.98f, 0.70f, 0.53f},
                                {0.54f, 0.71f, 0.98f}};

  for (auto &color : colors) {
    color = glm::pow(color, glm::vec3(1.5f));
  }
  for (int i = 0; i < 100; i++) {
    auto triangle = GameObject::createGameObject();
    triangle.model = model;
    triangle.transform2d.scale = glm::vec2(0.5f) + i * 0.001f;
    triangle.transform2d.rotation = i * glm::pi<float>() * 0.001f;
    triangle.color = colors[i % colors.size()];
    gameObjects.push_back(std::move(triangle));
  }
}
} // namespace vke

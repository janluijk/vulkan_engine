#pragma once

#include "device.hpp"
#include "pipeline.hpp"
#include "swap_chain.hpp"
#include "window.hpp"
#include "model.hpp"

#include <memory>
#include <vector>
#include <vulkan/vulkan_core.h>

namespace vke {

class App {

public:
  static constexpr int WIDTH = 2560;
  static constexpr int HEIGHT = 1440;

  App();
  ~App();
  App(const App &) = delete;
  App &operator=(const App &) = delete;

  void run();
private:
  void loadModels();
  void createPipelineLayout();
  void createPipeline();
  void createCommandBuffers();
  void freeCommandBuffers();
  void drawFrame();
  void recreateSwapChain();
  void recordCommandBuffer(int imageIndex);

  Window window{WIDTH, HEIGHT, "Vulkan"};
  Device device{window};
  std::unique_ptr<SwapChain> swapChain;
  std::unique_ptr<Pipeline> pipeline;
  VkPipelineLayout pipelineLayout;
  std::vector<VkCommandBuffer> commandBuffers;
  std::unique_ptr<Model> model;


  // Sierpinksi
  void sierpinski(std::vector<Model::Vertex> &vertices, int depth, glm::vec2 left, glm::vec2 right, glm::vec2 top);
};

} // namespace vke

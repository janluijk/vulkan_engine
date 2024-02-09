#pragma once


#include "device.hpp"
#include "swap_chain.hpp"
#include "window.hpp"

#include <cassert>
#include <memory>
#include <vector>
#include <vulkan/vulkan_core.h>

namespace vke {

class Renderer {

public:
  Renderer(Window &window, Device &device);
  ~Renderer();
  Renderer(const Renderer &) = delete;
  Renderer &operator=(const Renderer &) = delete;

  VkRenderPass getSwapChainRenderPass() const { return swapChain->getRenderPass();}
  bool isFrameInProgress() const { return isFrameStarted; }

  VkCommandBuffer GetCurrentCommandBuffer() {
    assert(isFrameStarted && "Cannot get command buffer when frame not in prgress");
    return commandBuffers[currentFrameIndex];
  }

  int getFrameIndex() const {
    assert(isFrameStarted && "Cannot get frame index when frame not in progress");
    return currentImageIndex;
  }

  VkCommandBuffer beginFrame();
  void endFrame();
  void beginSwapChainRenderPass(VkCommandBuffer commandBuffer);
  void endSwapChainRenderPass(VkCommandBuffer commandBuffer);
private:
  void createCommandBuffers();
  void freeCommandBuffers();
  void recreateSwapChain();

  Window &window;
  Device &device;
  std::unique_ptr<SwapChain> swapChain;
  std::vector<VkCommandBuffer> commandBuffers;

  uint32_t currentImageIndex;
  int currentFrameIndex{0};
  bool isFrameStarted{false};
};
} // namespace vke

#pragma once

#include "device.hpp"

#include <glm/glm.hpp>
#include <vulkan/vulkan_core.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DELPTH_ZERO_TO_ONE

namespace vke {

class Model {
public:
  struct Vertex {
    glm::vec2 position;
    
    static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
    static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
  };

  Model(Device &device, const std::vector<Vertex> &vertices);
  ~Model();

  Model(const Model &) = delete;
  Model &operator=(const Model &) = delete;

  void bind(VkCommandBuffer commandBuffer);
  void draw(VkCommandBuffer commandBuffer);

private:
  void createVertexBuffers(const std::vector<Vertex> &vertices);

  Device &device;

  VkBuffer vertexBuffer;
  VkDeviceMemory vertexBufferMemory;
  uint32_t vertexCount;
};

} // namespace vke

#pragma once

#include "device.hpp"
#include "window.hpp"
#include "game_object.hpp"
#include "renderer.hpp"

#include <vector>
#include <vulkan/vulkan_core.h>

namespace vke {

class App {

public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 800;

  App();
  ~App();
  App(const App &) = delete;
  App &operator=(const App &) = delete;

  void run();
private:
  void loadGameObjects();

  Window window{WIDTH, HEIGHT, "Vulkan"};
  Device device{window};
  Renderer renderer{window, device};

  std::vector<GameObject> gameObjects;


};

} // namespace vke

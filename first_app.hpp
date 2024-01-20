#pragma once

#include "window.hpp"
#include "pipeline.hpp"

namespace vke {

class FirstApp {

	public:
	static constexpr int WIDTH = 800;
	static constexpr int HEIGHT = 600;

	void run();
	private:
		VkeWindow vkeWindow{WIDTH, HEIGHT, "Vulkan"};
		VkePipeline vkePipeline{"shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv"};
};

}
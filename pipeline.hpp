#pragma once

#include <string>
#include <vector>

namespace vke {

class VkePipeline {
	public:
		VkePipeline(const std::string &vertFilePath, const std::string &fragFilePath);
	private:
		static std::vector<char> readFile(const std::string& filepath);
		void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilePath);
};
} // namespace vke
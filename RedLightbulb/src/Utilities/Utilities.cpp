#include "pch.h"
#include "Utilities.hpp"
#include <fstream>

namespace RedLightbulb::Utilities
{
	void readFile(const std::string& fileName, std::string& fileContent)
	{
		std::ifstream file(fileName);

		file.seekg(0, std::ios::end);
		size_t size = file.tellg();

		fileContent.resize(size);

		file.seekg(0);
		file.read(&fileContent[0], size);
	}
}

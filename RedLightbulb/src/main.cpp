#include "pch.h"
#include "Application/Application.hpp"

using namespace RedLightbulb;

int main()
{
	std::cout << "Hello there!" << std::endl;

	Application app;
	app.init();

	app.run();

	app.deinit();
	return 0;
}

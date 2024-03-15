#include "pch.h"
#include "Application/Application.hpp"

using namespace RedLightbulb;

int main()
{
	LogInfo("Hello there!");

	Application app;
	app.init();

	app.run();

	app.deinit();
	return 0;
}

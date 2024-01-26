#include "pch.h"
#include "Application/Application.hpp"

using namespace RedLightbulb;

int main()
{
	Utilities::Logger::log("Hello there!", Utilities::Logger::LogStatus::Warning);

	Application app;
	app.init();

	app.run();

	app.deinit();
	return 0;
}

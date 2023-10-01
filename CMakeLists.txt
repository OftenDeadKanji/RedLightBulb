set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(RedLightbulb
	"src/Core/RedLightbulb.hpp"
	"src/Core/RedLightbulb.cpp"

	"src/Config/OSInfo.hpp"

	"src/Utilities/Utilities.hpp"

	"src/Window/Window.hpp"
	"src/Window/Window.cpp"

	"src/EventManager/Event.hpp"
	"src/EventManager/EventManager.hpp"
	"src/EventManager/EventManager.cpp"
)
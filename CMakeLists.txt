set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(RedLightbulb
	"src/Core/RedLightbulb.hpp"
	"src/Core/RedLightbulb.cpp"

	"src/Config/OSInfo.hpp"

	"src/Utilities/NonCopyable.hpp"

	"src/Window/Window.hpp"
	"src/Window/Window.cpp"

)
#ifndef __EVENT_HPP__
#define __EVENT_HPP__

namespace RedLightbulb
{
	struct Event
	{
		enum class Type
		{
			WindowClose,

			MouseCursorMoved,
			MouseButtonPressed,
			MouseButtonReleased,

			KeyboardKeyPressed,
			KeyboardKeyReleased,
		};

		Type type;

		//Mouse
		int mousePosition;
	};
}

#endif

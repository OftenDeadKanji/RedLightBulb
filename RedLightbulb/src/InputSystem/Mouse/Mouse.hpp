#ifndef __MOUSE_HPP__
#define __MOUSE_HPP__

namespace RedLightbulb
{
	class EventManager;
	class EventManagerWindows;

	class Mouse
	{
		friend EventManager;
		friend EventManagerWindows;
	public:
		enum class Button
		{
			None = -1,

			Left,
			Middle,
			Right,

			Last
		};

		bool isPressed(Button button);
		const Vec2& getPosition() const;
	private:
		bool m_buttons[static_cast<int>(Button::Last)];
		Vec2 m_position;
	};
}

#endif
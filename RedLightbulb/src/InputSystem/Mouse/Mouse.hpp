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
		const Math::Vec2f& getPosition() const;
	private:
		bool m_buttons[static_cast<int>(Button::Last)];
		Math::Vec2f m_position;
	};
}

#endif
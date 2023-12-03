#ifndef __KEYBOARD_HPP__
#define __KEYBOARD_HPP__

namespace RedLightbulb
{
	class EventManager;
	class EventManagerWindows;

	class Keyboard
	{
		friend EventManager;
		friend EventManagerWindows;
	public:
		enum class KeyCode
		{
			None = -1,

			A,
			B,
			C,
			D,
			E,
			F,
			G,
			H,
			I,
			J,
			K,
			L,
			M,
			N,
			O,
			P,
			Q,
			R,
			S,
			T,
			U,
			V,
			W,
			X,
			Y,
			Z,

			LShift,
			LCtrl,
			LAlt,

			Space,

			Esc,

			Last
		};

	public:
		bool isPressed(KeyCode key);

	private:
		bool m_keys[static_cast<int>(KeyCode::Last)]{};
	};
}

#endif
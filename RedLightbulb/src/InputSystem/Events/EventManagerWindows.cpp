#include "pch.h"
#include "EventManagerWindows.h"
#include "../Window/WindowWindows.hpp"

namespace RedLightbulb
{
	void EventManagerWindows::pollEvents()
	{
		MSG msg{};
		GetMessageA(&msg, NULL, 0, 0);
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}

	WPARAM EventManagerWindows::processKey(WPARAM wparam, LPARAM lParam)
	{
		WPARAM key = wparam;
		UINT scancode = (lParam & 0x00ff0000) >> 16;
		int extended = (lParam & 0x01000000) != 0;

		switch (key)
		{
			case VK_SHIFT:
				key = MapVirtualKey(scancode, MAPVK_VSC_TO_VK_EX);
				break;
			case VK_CONTROL:
				key = extended ? VK_RCONTROL : VK_LCONTROL;
				break;
			case VK_MENU:
				key = extended ? VK_RMENU : VK_LMENU;
				break;
		}

		return key;
	}

	Keyboard::KeyCode EventManagerWindows::translateKeyCode(WPARAM key)
	{
		switch (key)
		{
			case 'A':
				return Keyboard::KeyCode::A;
			case 'B':
				return Keyboard::KeyCode::B;
			case 'C':
				return Keyboard::KeyCode::C;
			case 'D':
				return Keyboard::KeyCode::D;
			case 'E':
				return Keyboard::KeyCode::E;
			case 'F':
				return Keyboard::KeyCode::F;
			case 'G':
				return Keyboard::KeyCode::G;
			case 'H':
				return Keyboard::KeyCode::H;
			case 'I':
				return Keyboard::KeyCode::I;
			case 'J':
				return Keyboard::KeyCode::J;
			case 'K':
				return Keyboard::KeyCode::K;
			case 'L':
				return Keyboard::KeyCode::L;
			case 'M':
				return Keyboard::KeyCode::M;
			case 'N':
				return Keyboard::KeyCode::N;
			case 'O':
				return Keyboard::KeyCode::O;
			case 'P':
				return Keyboard::KeyCode::P;
			case 'Q':
				return Keyboard::KeyCode::Q;
			case 'R':
				return Keyboard::KeyCode::R;
			case 'S':
				return Keyboard::KeyCode::S;
			case 'T':
				return Keyboard::KeyCode::T;
			case 'U':
				return Keyboard::KeyCode::U;
			case 'V':
				return Keyboard::KeyCode::V;
			case 'W':
				return Keyboard::KeyCode::W;
			case 'X':
				return Keyboard::KeyCode::X;
			case 'Y':
				return Keyboard::KeyCode::Y;
			case 'Z':
				return Keyboard::KeyCode::Z;
			case VK_LSHIFT:
				return Keyboard::KeyCode::LShift;
			case VK_LCONTROL:
				return Keyboard::KeyCode::LCtrl;
			case VK_SPACE:
				return Keyboard::KeyCode::Space;
			default:
				return Keyboard::KeyCode::None;
		}
	}

	LRESULT EventManagerWindows::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		WindowWindows* window = WindowWindows::getInstancePtr(hWnd);
		if (!window)
		{
			return DefWindowProcA(hWnd, uMsg, wParam, lParam);
		}

		EventManagerWindows& eventManager = static_cast<EventManagerWindows&>(window->getEventManager());
		Event receivedEvent;

		auto key = processKey(wParam, lParam);
		switch (uMsg)
		{
			case WM_CLOSE:
				receivedEvent.type = Event::Type::WindowClose;
				eventManager.m_eventsQueue.emplace(receivedEvent);
				break;
			case WM_DESTROY:
				DeleteDC(window->getHDC());
				PostQuitMessage(0);
				break;
			case WM_KEYDOWN:
				if ((HIWORD(lParam) & KF_REPEAT) != KF_REPEAT)
				{
					Keyboard::KeyCode code = translateKeyCode(key);
					eventManager.m_keyboard->m_keys[static_cast<int>(code)] = true;
				}
				break;
			case WM_KEYUP:
				Keyboard::KeyCode code = translateKeyCode(key);
				eventManager.m_keyboard->m_keys[static_cast<int>(code)] = false;
				break;
		}

		return DefWindowProcA(hWnd, uMsg, wParam, lParam);
	}
}

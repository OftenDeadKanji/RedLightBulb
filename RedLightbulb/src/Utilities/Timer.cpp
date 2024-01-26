#include "pch.h"
#include "Timer.hpp"

namespace Utilities
{
	void Timer::setNewTimePoint()
	{
		m_start = clock::now();
	}
	float Timer::elapsed() const
	{
		return duration(clock::now() - m_start).count();
	}
}
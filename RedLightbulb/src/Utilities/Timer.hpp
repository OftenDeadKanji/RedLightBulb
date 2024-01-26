#ifndef __TIMER_HPP__
#define __TIMER_HPP__

namespace Utilities
{
	class Timer
	{
	public:
		void setNewTimePoint();
		float elapsed() const;

	private:
		using clock = std::chrono::high_resolution_clock;
		using duration = std::chrono::duration<float>;

		clock::time_point m_start;
	};
}

#endif

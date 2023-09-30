#ifndef __RED_LIGHTBULB_HPP__
#define __RED_LIGHTBULB_HPP__

namespace RedLightbulb
{
	class RedLighbulb
	{
	public:
		~RedLighbulb();

		void init();
		void deinit();
	private:
		bool m_isInitialised = false;
	};
}

#endif

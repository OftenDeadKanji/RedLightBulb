#ifndef __UTILITIES_HPP__
#define __UTILITIES_HPP__

#define sCast(type, value)      static_cast<type>(value)
#define dCast(type, value)     dynamic_cast<type>(value)
#define cCast(type, value)       const_cast<type>(value)
#define rCast(type, value) reinterpret_cast<type>(value)

namespace RedLightbulb
{
	class NonCopyable
	{
	public:
		NonCopyable() = default;
		NonCopyable(const NonCopyable&) = delete;
		NonCopyable& operator=(const NonCopyable&) = delete;
	};
}

#endif

#ifndef __WINDOWS_HPP__
#define __WINDOWS_HPP__

#include "../../Config/OSInfo.hpp"

#ifdef __OS_WINDOWS_64__
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif

	#include <Windows.h>
#endif

#endif
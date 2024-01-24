#ifndef __OS_INFO_HPP__
#define __OS_INFO_HPP__

#if _WIN32
	#if _WIN64
		#define __OS_WINDOWS_64__
	#else
		#define __OS_WINDOWS_32__
	#endif
#endif

#endif

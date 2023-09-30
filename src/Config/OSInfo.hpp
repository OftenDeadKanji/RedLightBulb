#ifndef __OS_INFO_HPP__
#define __OS_INFO_HPP__

//#define __OS_UNKNOWN__	0
//#define __OS_WINDOWS_32__	1
//#define __OS_WINDOWS_64__	2
//#define __OS_LINUX__		3

#if _WIN32
	#if _WIN64
		#define __OS_WINDOWS_64__
	#else
		#define __OS_WINDOWS_32__
	#endif
#endif

#endif

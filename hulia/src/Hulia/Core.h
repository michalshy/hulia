#pragma once

#ifdef HA_PLATFORM_WINDOWS
	#ifdef HA_BUILD_DLL
		#define HULIA_API __declspec(dllexport)
	#else
		#define HULIA_API __declspec(dllimport)
	#endif
#else
	#error Hulia is only for Windows!
#endif
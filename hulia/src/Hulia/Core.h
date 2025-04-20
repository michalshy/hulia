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

#ifdef HA_ENABLE_ASSERTS
	#define HA_ASSERT(x, ...) { if(!(x)) { HA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HA_CORE_ASSERT(x, ...) { if(!(x)) { HA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HA_ASSERT(x, ...)
	#define HA_CORE_ASSERT(x, ...)
#endif
#define BIT(x) (1 << x)
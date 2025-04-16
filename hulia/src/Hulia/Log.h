#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
#include <memory>

namespace Hulia {
	class HULIA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Logging Macros
#if defined(HA_DEBUG)
	#define HA_CORE_CRITICAL(...) ::Hulia::Log::GetCoreLogger()->critical(__VA_ARGS__);
	#define HA_CORE_ERROR(...)    ::Hulia::Log::GetCoreLogger()->error(__VA_ARGS__);
	#define HA_CORE_WARN(...)     ::Hulia::Log::GetCoreLogger()->warn(__VA_ARGS__);
	#define HA_CORE_INFO(...)     ::Hulia::Log::GetCoreLogger()->info(__VA_ARGS__);
	#define HA_CORE_TRACE(...)    ::Hulia::Log::GetCoreLogger()->trace(__VA_ARGS__);

	#define HA_CRITICAL(...)      ::Hulia::Log::GetClientLogger()->critical(__VA_ARGS__);
	#define HA_ERROR(...)         ::Hulia::Log::GetClientLogger()->error(__VA_ARGS__);
	#define HA_WARN(...)          ::Hulia::Log::GetClientLogger()->warn(__VA_ARGS__);
	#define HA_INFO(...)          ::Hulia::Log::GetClientLogger()->info(__VA_ARGS__);
	#define HA_TRACE(...)         ::Hulia::Log::GetClientLogger()->trace(__VA_ARGS__);
// Striping for release build
#else
	#define HA_CORE_CRITICAL(...) 
	#define HA_CORE_ERROR(...)   
	#define HA_CORE_WARN(...) 
	#define HA_CORE_INFO(...) 
	#define HA_CORE_TRACE(...)

	#define HA_CRITICAL(...)
	#define HA_ERROR(...)
	#define HA_WARN(...)
	#define HA_INFO(...)
	#define HA_TRACE(...)
#endif


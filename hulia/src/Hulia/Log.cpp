#include "hapch.h"
#include "Log.h"

namespace Hulia {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("HULIA");
		//TODO: expose level of logging
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		//TODO: expose level of logging
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}

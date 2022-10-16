#include "pch.h"
#include "Log.h"


namespace RockEngine
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// change log pattern
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// Core 
		s_CoreLogger = spdlog::stdout_color_mt("ENGINE");
		s_CoreLogger->set_level(spdlog::level::trace);
		
		// Client
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);

	}

	void Log::Shutdown()
	{
		//TODO: Make a body for function
	}
}


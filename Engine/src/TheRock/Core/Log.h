#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace RockEngine
{
	class Log
	{
	public:
		static void Init();
		static void Shutdown();

		static inline std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static inline std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Logging Macros
#define RE_CORE_TRACE(...)			RockEngine::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define RE_CORE_INFO(...)			RockEngine::Log::GetCoreLogger()->info(__VA_ARGS__);
#define RE_CORE_WARN(...)			RockEngine::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define RE_CORE_ERROR(...)			RockEngine::Log::GetCoreLogger()->error(__VA_ARGS__);
#define RE_CORE_FATAL(...)			RockEngine::Log::GetCoreLogger()->critical(__VA_ARGS__);


// Client Logging Macros
#define RE_TRACE(...)		RockEngine::Log::GetClientLogger()->trace(__VA_ARGS__);
#define RE_INFO(...)			RockEngine::Log::GetClientLogger()->info(__VA_ARGS__);
#define RE_WARN(...)			RockEngine::Log::GetClientLogger()->warn(__VA_ARGS__);
#define RE_ERROR(...)		RockEngine::Log::GetClientLogger()->error(__VA_ARGS__);
#define RE_FATAL(...)		RockEngine::Log::GetClientLogger()->critical(__VA_ARGS__);



#include "pch.h"
#include "Base.h"

#include "Log.h"

#include <Windows.h>

#define BUILD_ID "v0.1a"

namespace RockEngine {

	void InitializeCore()
	{
		RockEngine::Log::Init();

		RE_CORE_TRACE("The Rock Engine {}", BUILD_ID);
		RE_CORE_TRACE("Initializing...");
	}

	void ShutdownCore()
	{
		RE_CORE_TRACE("Shutting down...");
	}

}
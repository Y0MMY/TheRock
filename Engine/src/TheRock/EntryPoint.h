#pragma once

#ifdef RE_PLATFORM_WINDOWS

extern RockEngine::Application* RockEngine::CreateApplication();

int main(int argc, char** argv)
{
	RockEngine::InitializeCore();
	RockEngine::Application* app = RockEngine::CreateApplication();
	RE_CORE_ASSERT(app, "Client Application is null!");
	app->Run();
	delete app;
	RockEngine::ShutdownCore();
}

#endif

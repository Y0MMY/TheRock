#include "TheRock.h"
#include <TheRock/EntryPoint.h>

struct RockEngine::ApplicationProps;

class Sandbox : public RockEngine::Application
{
public: 
	Sandbox(const RockEngine::ApplicationProps& props)
		: Application(props)
	{
		RE_CORE_TRACE("Hello!");
	}
};

RockEngine::Application* RockEngine::CreateApplication()
{
	RockEngine::ApplicationProps props;
	props.Name = "TheRock";
	props.WindowWidth = 1280;
	props.WindowHeight = 720;
	return new Sandbox({ "Rock", 1600, 900 });
}
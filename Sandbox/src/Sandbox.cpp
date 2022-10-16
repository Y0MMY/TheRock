#include "TheRock.h"
#include <TheRock/EntryPoint.h>

class Sandbox : public RockEngine::Application
{
public: 
	Sandbox()
	{
		RE_CORE_TRACE("Hello!");
	}
};

RockEngine::Application* RockEngine::CreateApplication()
{
	return new Sandbox();
}
#include <TheRock.h>
#include "TheRock/EntryPoint.h"

#include "EditorLayer.h"


class Sandbox : public RockEngine::Application
{
public:
	Sandbox(const RockEngine::ApplicationProps& props)
		: Application(props)
	{
		RE_CORE_TRACE("Hello!");
	}

	virtual void OnInit() override
	{
		PushLayer(new RockEngine::EditorLayer());
	}

};

RockEngine::Application* RockEngine::CreateApplication()
{
	RockEngine::ApplicationProps props;
	props.Name = "TheRock";
	props.WindowWidth = 1600;
	props.WindowHeight = 900;

	return new Sandbox(props);
}
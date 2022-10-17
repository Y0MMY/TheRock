#include "TheRock.h"
#include <TheRock/EntryPoint.h>

#include "TheRock/ImGui/ImGuiLayer.h"

#include "TheRock/Core/Input.h"

struct RockEngine::ApplicationProps;

class GameLayer : public RockEngine::Layer
{
public:
	GameLayer()
	{
	}

	virtual ~GameLayer()
	{
	}

	virtual void OnAttach() override
	{
	}

	virtual void OnDetach() override
	{
	}

	virtual void OnUpdate() override
	{
		RockEngine::Renderer::Clear(0.2f, 0.3f, 0.8f, 1);
	}

	virtual void OnEvent(RockEngine::Event& event) override
	{
	}
};


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
		PushLayer(new GameLayer());
		//PushOverlay(new RockEngine::ImGuiLayer("ImGui"));
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
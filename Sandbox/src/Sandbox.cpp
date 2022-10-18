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
		static float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		static unsigned int indices[] = {
			0, 1, 2
		};

		m_VB = RockEngine::Scope<RockEngine::VertexBuffer>(RockEngine::VertexBuffer::Create());
		m_VB->SetData(vertices, sizeof(vertices));

		m_IB = std::unique_ptr<RockEngine::IndexBuffer>(RockEngine::IndexBuffer::Create());
		m_IB->SetData(indices, sizeof(indices));

	}

	virtual void OnDetach() override
	{
	}

	virtual void OnImGuiRender()
	{
		ImGui::Begin("GameLayer");
		ImGui::ColorEdit4("Clear Color", m_ClearColor);
		ImGui::End();
	}

	virtual void OnUpdate() override
	{
		RockEngine::Renderer::Clear(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]);
		m_VB->Bind();
		m_IB->Bind();
		RockEngine::Renderer::DrawIndexed(3);
	}

	virtual void OnEvent(RockEngine::Event& event) override
	{
	}
private:
	std::unique_ptr<RockEngine::VertexBuffer> m_VB;
	std::unique_ptr<RockEngine::IndexBuffer> m_IB;
	float m_ClearColor[4];

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
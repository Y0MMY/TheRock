#include "TheRock.h"
#include <TheRock/EntryPoint.h>

#include "TheRock/ImGui/ImGuiLayer.h"

#include "TheRock/Core/Input.h"

struct RockEngine::ApplicationProps;

class GameLayer : public RockEngine::Layer
{
public:
	GameLayer()
		: m_TriangleColor{ 0.8f, 0.2f, 0.3f, 1.0f }
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

		m_Shader.reset(RockEngine::Shader::Create("assets/shaders/shader.glsl"));
	}

	virtual void OnDetach() override
	{
	}

	virtual void OnImGuiRender()
	{
		ImGui::Begin("GameLayer");
		ImGui::ColorEdit4("Clear Color", m_ClearColor);
		ImGui::ColorEdit4("Triangle Color", &m_TriangleColor[0]);
		ImGui::End();
	}

	virtual void OnUpdate() override
	{
		RockEngine::Renderer::Clear(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]);
		RockEngine::UniformBufferDeclaration<sizeof(glm::vec4), 1> buffer;
		buffer.Push("u_Color", m_TriangleColor);
		m_Shader->UploadUniformBuffer(buffer);

		m_VB->Bind();
		m_IB->Bind();
		m_Shader->Bind();
		RockEngine::Renderer::DrawIndexed(3);
	}

	virtual void OnEvent(RockEngine::Event& event) override
	{
	}
private:
	RockEngine::Scope<RockEngine::VertexBuffer> m_VB;
	RockEngine::Scope<RockEngine::IndexBuffer> m_IB;

	RockEngine::Scope<RockEngine::Shader> m_Shader;

	float m_ClearColor[4];
	glm::vec4 m_TriangleColor;
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
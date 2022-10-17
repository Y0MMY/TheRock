#pragma once

#include "TheRock/Core/Layer.h"

namespace RockEngine { // TODO: GLFWcursor* m_ImGuiMouseCursors[9] = { 0 }; in WindowsWindow class

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		ImGuiLayer(const std::string& name);
		virtual ~ImGuiLayer();

		void Begin();
		void End();


		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
	private:
		float m_Time = 0.0f;
	};

}

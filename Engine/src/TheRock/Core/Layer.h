#pragma once

#include "TheRock/Core/Base.h"
#include "TheRock/Core/Events/Event.h"

#include "TheRock/Core/Timestep.h"

namespace RockEngine
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach(){}
		virtual void OnDetach(){}
		virtual void OnUpdate(Timestep ts){}
		virtual void OnEvent(Event& e){}

		virtual void OnImGuiRender() {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}
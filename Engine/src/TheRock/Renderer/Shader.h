#pragma once

#include "TheRock/Core/Base.h"
#include "TheRock/Renderer/Renderer.h"

#include <string>

namespace RockEngine
{
	class Shader
	{
	public:
		virtual void Bind() const = 0;

		// Represents a complete shader program stored in a single file.
		// Note: currently for simplicity this is simply a string filepath, however
		//       in the future this will be an asset object + metadata

		static Shader* Create(const std::string& filepath);
	};
}
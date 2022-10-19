//
// Note:	this file is to be included in client applications ONLY
//			NEVER include this file anywhere in the engine codebase
//
#pragma once

#include "TheRock/Core/Application.h"
#include "TheRock/Core/Log.h"

// ------ Events ------------------------------------
#include "TheRock/Core/Events/Event.h"
#include "TheRock/Core/Events/ApplicationEvent.h"
#include "TheRock/Core/Events/KeyEvent.h"
#include "TheRock/Core/Events/MouseEvent.h"
// ---------------------------------------------------

// --- TheRock Render API ----------------------------
#include "ImGui/imgui.h"
#include "TheRock/Renderer/Renderer.h"
//#include "TheRock/Renderer/FrameBuffer.h"
#include "TheRock/Renderer/VertexBuffer.h"
#include "TheRock/Renderer/IndexBuffer.h"
#include "TheRock/Renderer/Texture.h"
#include "TheRock/Renderer/Shader.h"


// ---------------------------------------------------
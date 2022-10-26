//
// Note:	this file is to be included in client applications ONLY
//			NEVER include this file anywhere in the engine codebase
//
#pragma once

#include "TheRock/Core/Application.h"
#include "TheRock/Core/Log.h"
#include "TheRock/Core/Input.h"

// ------ Events ------------------------------------
#include "TheRock/Core/Events/Event.h"
#include "TheRock/Core/Events/ApplicationEvent.h"
#include "TheRock/Core/Events/KeyEvent.h"
#include "TheRock/Core/Events/MouseEvent.h"
// ---------------------------------------------------

// --- TheRock Render API ----------------------------
#include "ImGui/imgui.h"
#include "TheRock/Renderer/Renderer.h"
#include "TheRock/Renderer/SceneRenderer.h"
#include "TheRock/Renderer/RenderPass.h"
#include "TheRock/Renderer/FrameBuffer.h"
#include "TheRock/Renderer/Buffer.h"
#include "TheRock/Renderer/VertexArray.h"
#include "TheRock/Renderer/Mesh.h"
#include "TheRock/Renderer/Camera.h"
#include "TheRock/Renderer/Texture.h"
#include "TheRock/Renderer/Shader.h"
#include "TheRock/Renderer/Material.h"
// ---------------------------------------------------

// --- Math ------------------------------------------



// ---------------------------------------------------

// Scenes
#include "TheRock/Scene/Entity.h"
#include "TheRock/Scene/Scene.h"

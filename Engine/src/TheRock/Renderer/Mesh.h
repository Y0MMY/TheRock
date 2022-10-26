#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "TheRock/Core/TimeStep.h"

#include "TheRock/Renderer/VertexArray.h"
#include "TheRock/Renderer/Buffer.h"
#include "TheRock/Renderer/Shader.h"
#include "TheRock/Renderer/Material.h"

struct aiNode;
struct aiAnimation;
struct aiNodeAnim;
struct aiScene;

namespace Assimp {
	class Importer;
}


namespace RockEngine
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec3 Tangent;
		glm::vec3 Binormal;
		glm::vec2 Texcoord;
	};

	struct AnimatedVertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec3 Tangent;
		glm::vec3 Binormal;
		glm::vec2 Texcoord;

		u32 IDs[4] = { 0,0,0,0 };
		float Weights[4] = { 0.f,0.f,0.f,0.f };

		void AddBoneData(u32 BoneID, float Weight)
		{
			for (u32 i = 0; i < 4; i++)
			{
				if (IDs[i])
					continue;
				IDs[i] = BoneID;
				Weights[i] = Weight;
				return;
			}

			// TODO: Keep top weights
			RE_CORE_WARN("Vertex has more than four bones/weights affecting it, extra data will be discarded (BoneID={0}, Weight={1})", BoneID, Weight);
		}
	};

	struct Index
	{
		uint32_t V1, V2, V3;
	};
	static_assert(sizeof(Index) == 3 * sizeof(uint32_t));

	struct BoneInfo
	{
		glm::mat4 BoneOffset;
		glm::mat4 FinalTransformation;
	};

	struct VertexBoneData
	{
		uint32_t IDs[4];
		float Weights[4];
		
		VertexBoneData()
		{
			memset(IDs, 0, sizeof(IDs));
			memset(Weights, 0, sizeof(Weights));
		};

		void AddBoneData(u32 BoneID, float Weight)
		{
			for (u32 i = 0; i < 4; i++)
			{
				if (IDs[i])
					continue;
				IDs[i] = BoneID;
				Weights[i] = Weight;
				return;
			}

			// TODO: Keep top weights
			RE_CORE_ASSERT(false, "Too many bones!");
		}
	};

	struct Submesh
	{
		u32 BaseVertex;
		u32 BaseIndex;
		u32 MaterialIndex;
		u32 IndexCount;

		glm::mat4 Transform;
	};

	class Mesh
	{
	public:
		Mesh(const std::string& filename);
		~Mesh();

		void OnUpdate(Timestep ts);
		void DumpVertexBuffer();

		Ref<Shader> GetMeshShader() { return m_MeshShader; }
		Ref<Material> GetMaterial() { return m_BaseMaterial; }
		std::vector<Ref<MaterialInstance>> GetMaterials() { return m_Materials; }
		const std::vector<Ref<Texture2D>>& GetTextures() const { return m_Textures; }
		const std::string& GetFilePath() const { return m_FilePath; }
	private:
		void BoneTransform(float time);
		void ReadNodeHierarchy(float AnimationTime, const aiNode* pNode, const glm::mat4& ParentTransform);
		void TraverseNodes(aiNode* node, const glm::mat4& parentTransform = glm::mat4(1.0f), uint32_t level = 0);

		const aiNodeAnim* FindNodeAnim(const aiAnimation* animation, const std::string& nodeName);
		u32 FindPosition(float AnimationTime, const aiNodeAnim* pNodeAnim);
		uint32_t FindScaling(float AnimationTime, const aiNodeAnim* pNodeAnim);
		uint32_t FindRotation(float AnimationTime, const aiNodeAnim* pNodeAnim);
		glm::vec3 InterpolateTranslation(float animationTime, const aiNodeAnim* nodeAnim);
		glm::quat InterpolateRotation(float animationTime, const aiNodeAnim* nodeAnim);
		glm::vec3 InterpolateScale(float animationTime, const aiNodeAnim* nodeAnim);
	private:
		std::vector<Submesh> m_Submeshes;
		Scope<Assimp::Importer> m_Importer;

		std::vector<BoneInfo> m_BoneInfo;

		glm::mat4 m_InverseTransform;
		u32 m_BoneCount = 0;
		std::unordered_map<std::string, uint32_t> m_BoneMapping;
		std::vector<glm::mat4> m_BoneTransforms;
		const aiScene* m_Scene;

		std::vector<Vertex> m_StaticVertices;
		std::vector<AnimatedVertex> m_AnimatedVertices;

		std::vector<Index> m_Indices;

		Ref<VertexArray> m_VertexArray;

		std::string m_FilePath;

		// Materials
		Ref<Shader> m_MeshShader;
		Ref<Material> m_BaseMaterial;
		std::vector<Ref<Texture2D>> m_Textures;
		std::vector<Ref<Texture2D>> m_NormalMaps;
		std::vector<Ref<MaterialInstance>> m_Materials;

		// Animation
		bool m_IsAnimated = false;
		float m_AnimationTime = 0.0f;
		float m_WorldTime = 0.0f;
		float m_TimeMultiplier = 1.0f;
		bool m_AnimationPlaying = true;

		friend class Renderer;
		friend class SceneHierarchyPanel;
	};
}

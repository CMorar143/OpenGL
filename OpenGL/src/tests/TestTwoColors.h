#pragma once

#include "Test.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Texture.h"
#include <memory>

namespace test {
	struct Colors
	{
		glm::vec4 Color1, Color2;
	};

	class TestTwoColors : public Test
	{
	public:
		TestTwoColors();
		~TestTwoColors();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

	private:
		std::unique_ptr<VertexArray> m_VAO;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<Shader> m_Shader;

		float m_Color1[4];
		float m_Color2[4];
	};
}
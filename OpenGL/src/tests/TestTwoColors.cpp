#include "TestTwoColors.h"

#include "Renderer.h"
#include "imgui/imgui.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace test {

    TestTwoColors::TestTwoColors()
        : m_Color1 { 0.8f, 0.3f, 0.2f, 1.0f },
          m_Color2 { 0.3f, 0.4f, 0.8f, 1.0f }

	{
        float positions[] = {
            -0.9f, -0.5f, m_Color1[0], m_Color1[1], m_Color1[2], m_Color1[3],
            -0.5f, -0.5f, m_Color1[0], m_Color1[1], m_Color1[2], m_Color1[3],
            -0.5f,  0.5f, m_Color1[0], m_Color1[1], m_Color1[2], m_Color1[3],
            -0.9f,  0.5f, m_Color1[0], m_Color1[1], m_Color1[2], m_Color1[3],

             0.5f, -0.5f, m_Color2[0], m_Color2[1], m_Color2[2], m_Color2[3],
             0.9f, -0.5f, m_Color2[0], m_Color2[1], m_Color2[2], m_Color2[3],
             0.9f,  0.5f, m_Color2[0], m_Color2[1], m_Color2[2], m_Color2[3],
             0.5f,  0.5f, m_Color2[0], m_Color2[1], m_Color2[2], m_Color2[3]
        };

        uint32_t indices[] = {
            0, 1, 2, 2, 3, 0,
            4, 5, 6, 6, 7, 4
        };

        m_VAO = std::make_unique<VertexArray>();
        m_VertexBuffer = std::make_unique<VertexBuffer>(positions, 6 * 8 * sizeof(float));
        m_IndexBuffer = std::make_unique<IndexBuffer>(indices, 12);

        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(4);
        m_VAO->AddBuffer(*m_VertexBuffer, layout);
        
        m_Shader = std::make_unique<Shader>("res/shaders/TwoColor.shader");
        m_Shader->Bind();
        m_Shader->SetUniform4f("u_Color", m_Color1[0], m_Color1[1], m_Color1[2], m_Color1[3]);
	}

    TestTwoColors::~TestTwoColors()
    {

    }

    void TestTwoColors::OnUpdate(float deltaTime)
    {

    }

    void TestTwoColors::OnRender()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

        Renderer renderer;

        m_Shader->Bind();
        m_Shader->SetUniform4f("u_Color", m_Color1[0], m_Color1[1], m_Color1[2], m_Color1[3]);
        renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
	}

	void TestTwoColors::OnImGuiRender()
	{
        ImGui::ColorEdit4("color 1", m_Color1);
        ImGui::ColorEdit4("color 2", m_Color2);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}
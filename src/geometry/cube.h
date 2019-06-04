#pragma once

#include <glad/glad.h>

class Cube
{
public:
	Cube(float scale) : m_scale(scale)
	{
	}

    virtual ~Cube() = default;

	void prepare()
	{
		float half = (m_scale / 2.f);
		float vertices[] = {
			-half, -half, -half,  0.0f, 0.0f,
			half, -half, -half,  1.0f, 0.0f,
			half,  half, -half,  1.0f, 1.0f,
			half,  half, -half,  1.0f, 1.0f,
			-half,  half, -half,  0.0f, 1.0f,
			-half, -half, -half,  0.0f, 0.0f,

			-half, -half,  half,  0.0f, 0.0f,
			half, -half,  half,  1.0f, 0.0f,
			half,  half,  half,  1.0f, 1.0f,
			half,  half,  half,  1.0f, 1.0f,
			-half,  half,  half,  0.0f, 1.0f,
			-half, -half,  half,  0.0f, 0.0f,

			-half,  half,  half,  1.0f, 0.0f,
			-half,  half, -half,  1.0f, 1.0f,
			-half, -half, -half,  0.0f, 1.0f,
			-half, -half, -half,  0.0f, 1.0f,
			-half, -half,  half,  0.0f, 0.0f,
			-half,  half,  half,  1.0f, 0.0f,

			half,  half,  half,  1.0f, 0.0f,
			half,  half, -half,  1.0f, 1.0f,
			half, -half, -half,  0.0f, 1.0f,
			half, -half, -half,  0.0f, 1.0f,
			half, -half,  half,  0.0f, 0.0f,
			half,  half,  half,  1.0f, 0.0f,

			-half, -half, -half,  0.0f, 1.0f,
			half, -half, -half,  1.0f, 1.0f,
			half, -half,  half,  1.0f, 0.0f,
			half, -half,  half,  1.0f, 0.0f,
			-half, -half,  half,  0.0f, 0.0f,
			-half, -half, -half,  0.0f, 1.0f,

			-half,  half, -half,  0.0f, 1.0f,
			half,  half, -half,  1.0f, 1.0f,
			half,  half,  half,  1.0f, 0.0f,
			half,  half,  half,  1.0f, 0.0f,
			-half,  half,  half,  0.0f, 0.0f,
			-half,  half, -half,  0.0f, 1.0f
		};

		glGenVertexArrays(1, &m_vao_id);
		glGenBuffers(1, &m_vbo_id);
		//glGenBuffers(1, &m_ebo_id);

		// bind Vertex Array Object
		glBindVertexArray(m_vao_id);

		// copy vertices to Vertex Buffer Object

		glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// then set our vertex attributes pointers
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// then texture co-ordinate
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}

	void draw() const
	{
		glBindVertexArray(m_vao_id);

		glDrawArrays(GL_TRIANGLES, 0, 36);

		glBindVertexArray(0);
	}

private:
	float m_scale;

	unsigned int m_vao_id{ 0 };
	unsigned int m_vbo_id{ 0 };
	//unsigned int m_ebo_id{ 0 };
};
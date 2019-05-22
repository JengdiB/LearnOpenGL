#pragma once

#include <glad/glad.h>

#include <iostream>

class Triangle
{
public:
	Triangle(float scale)
	{
		float half = (scale / 2.f);

		// lower left
		m_vertices[0] = -half;
		m_vertices[1] = -half;
		m_vertices[2] = 0.f;
		m_vertices[3] = 0.f; // texture co-ordinate
		m_vertices[4] = 0.f; // texture co-ordinate

		// lower right
		m_vertices[5] = half;
		m_vertices[6] = -half;
		m_vertices[7] = 0.f;
		m_vertices[8] = 1.f; // texture co-ordinate
		m_vertices[9] = 0.f; // texture co-ordinate

		// top
		m_vertices[10] = 0.f;
		m_vertices[11] = half;
		m_vertices[12] = 0.f;
		m_vertices[13] = 0.5f; // texture co-ordinate
		m_vertices[14] = 1.0f; // texture co-ordinate

	}

	virtual ~Triangle()
	{
		glDeleteVertexArrays(1, &m_vao_id);
		glDeleteBuffers(1, &m_vbo_id);
		glDeleteBuffers(1, &m_ebo_id);
	}

	void prepare()
	{
		glGenVertexArrays(1, &m_vao_id);
		glGenBuffers(1, &m_vbo_id);
		glGenBuffers(1, &m_ebo_id);

		// bind Vertex Array Object
		glBindVertexArray(m_vao_id);

		// copy vertices to Vertex Buffer Object
		
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, GL_STATIC_DRAW);

		// order to use vertex data to draw
		unsigned int indices[] = {0, 1, 2};
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo_id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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

		//glDrawArrays(GL_TRIANGLES, 0, 3);

		
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
	}

private:
	float m_vertices[15];

	unsigned int m_vao_id{ 0 };
	unsigned int m_vbo_id{ 0 };
	unsigned int m_ebo_id{ 0 };

	unsigned int m_texture_id{ 0 };
};
#include "shader.h"

#include <glad/glad.h> // include glad to get all the required OpenGL headers
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

Shader::Shader(const std::string& vertexShader, const std::string& fragmentShader)
	: m_vertexShader(vertexShader)
	, m_fragmentShader(fragmentShader)
{

}

bool Shader::build()
{
	m_lastError = std::string();
	int  success;
	char infoLog[512];

	unsigned int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	const char* vectexShaderSrc = m_vertexShader.c_str();
	glShaderSource(vertexShaderID, 1, &(vectexShaderSrc), NULL);
	glCompileShader(vertexShaderID);

	
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
		m_lastError = infoLog;

		glDeleteShader(vertexShaderID);

		return false;
	}

	unsigned int fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentShaderSrc = m_fragmentShader.c_str();
	glShaderSource(fragmentShaderID, 1, &(fragmentShaderSrc), NULL);
	glCompileShader(fragmentShaderID);

	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShaderID, 512, NULL, infoLog);
		m_lastError = infoLog;

		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);

		return false;
	}

	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertexShaderID);
	glAttachShader(m_ID, fragmentShaderID);
	glLinkProgram(m_ID);

	glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_ID, 512, NULL, infoLog);
		m_lastError = infoLog;

		return false;
	}

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return true;
}

void Shader::active() const
{
	glUseProgram(m_ID);
}

unsigned int Shader::id() const
{
	return m_ID;
}

const std::string& Shader::getLastError() const
{
	return m_lastError;
}

void Shader::setBool(const std::string &name, bool value) const
{
	int location = glGetUniformLocation(m_ID, name.c_str());
	glUniform1i(location, value ? 1 : 0);
}

void Shader::setInt(const std::string &name, int value) const
{
	int location = glGetUniformLocation(m_ID, name.c_str());
	glUniform1i(location, value);
}

void Shader::setFloat(const std::string &name, float value) const
{
	int location = glGetUniformLocation(m_ID, name.c_str());
	glUniform1f(location, value);
}

void Shader::setMat4(const std::string &name, const glm::mat4& trans) const
{
	int location = glGetUniformLocation(m_ID, name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(trans));
}

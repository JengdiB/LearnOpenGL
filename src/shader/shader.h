#pragma once

//#include <glm/vec4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>

class Shader
{
public:
	Shader(const std::string& vertexShader, const std::string& fragmentShader);

	bool build();
	const std::string& getLastError() const;

	unsigned int id() const;
	void active() const;

	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
	void setMat4(const std::string &name, const glm::mat4& trans) const;
private:
	unsigned int m_ID{ 0 }; // OpenGL ID to shader program
	const std::string m_vertexShader;
	const std::string m_fragmentShader;

	std::string m_lastError;
};
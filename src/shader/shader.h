#pragma once
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

private:
	unsigned int m_ID{ 0 }; // OpenGL ID to shader program
	const std::string m_vertexShader;
	const std::string m_fragmentShader;

	std::string m_lastError;
};
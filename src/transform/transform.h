#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform
{
public:
	Transform();
	virtual ~Transform() = default;

	void rotateDegree(float degree);
	void rotateRadian(float radian);
	void rotateAxis(glm::vec3 axis);

	void scale(glm::vec3 scale);

	void translate(glm::vec3 translate);

	const glm::mat4& getTransform();
private:
	// translate
	glm::vec3 m_translate;

	// rotate
	float	  m_rotate_radian;
	glm::vec3 m_rotate_axis;

	// scale
	glm::vec3 m_scale;

	// cache
	glm::mat4 m_transform;
	bool	  m_updated;
};

Transform::Transform()
	: m_updated(false)
	, m_transform(glm::mat4(1.f))
	, m_translate(0.f, 0.f, 0.f)
	, m_rotate_radian(0.f)
	, m_rotate_axis(0.f, 0.f, 1.f)
	, m_scale(1.f, 1.f, 1.f)
{
}

void
Transform::rotateDegree(float degree)
{
	m_rotate_radian = glm::radians(degree);
	m_updated = true;
}

void
Transform::rotateRadian(float radian)
{
	m_rotate_radian = radian;
	m_updated = true;
}

void
Transform::rotateAxis(glm::vec3 axis)
{
	m_rotate_axis = axis;
	m_updated = true;
}

void
Transform::scale(glm::vec3 scale)
{
	m_scale = scale;
	m_updated = true;
}

void
Transform::translate(glm::vec3 translate)
{
	m_translate = translate;
	m_updated = true;
}

const glm::mat4&
Transform::getTransform()
{
	if (!m_updated)
		return m_transform;

	m_transform = glm::mat4(1.f);
	m_transform = glm::translate(m_transform, m_translate);
	m_transform = glm::scale(m_transform, m_scale);
	m_transform = glm::rotate(m_transform, m_rotate_radian, m_rotate_axis);
	
	return m_transform;
}
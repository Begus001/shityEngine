#include <objects/shityObject.h>
#include <glm/gtx/transform.hpp>

#include <cassert>

namespace se
{

ShityObject::ShityObject()
{

}

ShityObject::~ShityObject()
{

}

void ShityObject::translate(const glm::vec3 val)
{
	mModelMatrix = glm::translate(mModelMatrix, val);
}

void ShityObject::rotate(const glm::vec3 axis, const float angle, const bool rad)
{
	float convertedAngle = angle;
	if (!rad) convertedAngle = glm::radians(angle);
	mModelMatrix = glm::rotate(mModelMatrix, angle, axis);
}

void ShityObject::scale(const glm::vec3 val)
{
	mModelMatrix = glm::scale(mModelMatrix, val);
}

void ShityObject::setPosition(const glm::vec3 &val)
{
	assert(false && "NOT IMPLEMENTED");
}

void ShityObject::setRotation(const glm::vec3 &val)
{
	assert(false && "NOT IMPLEMENTED");
}

void ShityObject::setScale(const glm::vec3 &val)
{
	assert(false && "NOT IMPLEMENTED");
}

glm::vec3 ShityObject::getPosition() const
{
	return glm::vec3(mModelMatrix[3][0], mModelMatrix[3][1], mModelMatrix[3][2]);
}

glm::vec3 ShityObject::getRotation() const
{
	assert(false && "NOT IMPLEMENTED");
}

glm::vec3 ShityObject::getScale() const
{
	return glm::vec3(mModelMatrix[0][0], mModelMatrix[1][1], mModelMatrix[2][2]);
}

}

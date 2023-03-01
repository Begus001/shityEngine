#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace se
{

class ShityObject {
public:
	ShityObject();
	~ShityObject();

	virtual void translate(const glm::vec3 val);
	virtual void rotate(const glm::vec3 axis, const float angle, const bool rad = false);
	virtual void scale(const glm::vec3 val);

	virtual void setPosition(const glm::vec3 &val);
	virtual void setRotation(const glm::vec3 &val);
	virtual void setScale(const glm::vec3 &val);

	virtual glm::vec3 getPosition() const;
	virtual glm::vec3 getRotation() const;
	virtual glm::vec3 getScale() const;

private:
	glm::mat4 mModelMatrix;
	std::vector<float> mVertices;
};

}
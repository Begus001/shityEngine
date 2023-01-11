#pragma once

#include "test.h"

class TestColorTriangle : public Test {
public:
	TestColorTriangle();
	~TestColorTriangle();
	
	void onRender() override;
	void onUIRender() override;

private:
	std::unique_ptr<se::Renderer> mRenderer;
	std::unique_ptr<se::Shader> mShader;
	std::unique_ptr<se::VAO> mVao;
	std::unique_ptr<se::VBO> mVbo;

	float mVertices[18];
};
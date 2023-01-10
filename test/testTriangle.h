#pragma once

#include "test.h"

class TestColorTriangle : public Test {
public:
	TestColorTriangle();
	~TestColorTriangle();
	
	void onRender() override;
	void onUIRender() override;

private:
	se::Renderer *mRenderer;
	se::Shader *mShader;
	se::VAO *mVao;
	se::VBO *mVbo;

	float mVertices[6];
	float mColor[4];
};
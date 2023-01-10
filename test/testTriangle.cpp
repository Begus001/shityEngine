#include "testTriangle.h"

TestColorTriangle::TestColorTriangle() : 
mVertices {
	-0.5f, -0.5f,
	0.5f, -0.5f,
	0.0f,  0.5f,
},
mColor { 0.0f, 0.5f, 1.0f, 1.0f }
{
	mRenderer = new se::Renderer();
	mVao = new se::VAO();
	mVbo = new se::VBO(mVertices, sizeof(mVertices));

	se::VBOLayout layout;
	layout.push<float>(2);

	mVao->addVBO(*mVbo, layout);

	mShader = new se::Shader("triangleVert.glsl", "triangleFrag.glsl");
	mShader->compile();
}

TestColorTriangle::~TestColorTriangle()
{
	
}

void TestColorTriangle::onRender()
{
	mRenderer->setClearColor(0, 0, 0, 0);
	mRenderer->clear();
	mShader->bind();
	mShader->setUniform<se::UT_4F>("fragColor", mColor[0], mColor[1], mColor[2], mColor[3]);
	mVao->bind();
	mRenderer->drawArray(*mVao, sizeof(mVertices) / sizeof(float));
}

void TestColorTriangle::onUIRender()
{
	ImGui::ColorEdit4("Color", mColor);
}

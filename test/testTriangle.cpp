#include "testTriangle.h"

TestColorTriangle::TestColorTriangle() : 
mVertices {
	-0.5f, -0.5f, 0.1f, 0.5f, 1.0f, 1.0f,
	0.5f, -0.5f, 0.7f, 0.1f, 1.0f, 1.0f,
	0.0f,  0.5f, 1.0f, 0.7f, 0.1f, 1.0f,
}
{
	mRenderer = std::make_unique<se::Renderer>();
	mVao = std::make_unique<se::VAO>();
	mVbo = std::make_unique<se::VBO>(mVertices, sizeof(mVertices));

	se::VBOLayout layout;
	layout.push<float>(2);
	layout.push<float>(4);

	mVao->addVBO(*mVbo, layout);

	mShader = std::make_unique<se::Shader>("triangleVert.glsl", "triangleFrag.glsl");
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
	mVbo->bind();
	mVbo->setData(mVertices, sizeof(mVertices));
	mVao->bind();
	mRenderer->drawArray(*mVao, sizeof(mVertices) / sizeof(float));
}

void TestColorTriangle::onUIRender()
{
	ImGui::ColorEdit4("Left", &mVertices[2]);
	ImGui::ColorEdit4("Right", &mVertices[8]);
	ImGui::ColorEdit4("Top", &mVertices[14]);
}

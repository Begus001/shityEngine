#include "testClear.h"

TestClear::TestClear() : 
mRenderer(std::make_unique<se::Renderer>()),
mClearColor { 0.0f, 0.5f, 1.0f, 1.0f } {}

void TestClear::onRender()
{
	mRenderer->setClearColor(mClearColor[0], mClearColor[1], mClearColor[2], mClearColor[3]);
	mRenderer->clear();
}

void TestClear::onUIRender()
{
	ImGui::ColorEdit4("Clear color", mClearColor);
}
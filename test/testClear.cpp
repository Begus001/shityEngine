#include "testClear.h"

TestClear::TestClear()
{
	mRenderer = new se::Renderer();
	*mClearColor = {};
}

TestClear::~TestClear()
{
	delete mRenderer;
}

void TestClear::onRender()
{
	mRenderer->setClearColor(mClearColor[0], mClearColor[1], mClearColor[2], mClearColor[3]);
	mRenderer->clear();
}

void TestClear::onUIRender()
{
	ImGui::ColorEdit4("Clear color", mClearColor);
}
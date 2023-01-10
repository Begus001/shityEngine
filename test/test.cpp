#include "test.h"

Test::Test()
{
	
}

Test::~Test()
{
}

void Test::onStart()
{
	mRenderer = new se::Renderer;
}

void Test::onUpdate()
{
	if (!mCurrentTest) return;
	mCurrentTest->onUpdate();
}

void Test::onRender()
{
	if (!mCurrentTest) {
		mRenderer->setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		mRenderer->clear();
		return;
	}

	mCurrentTest->onRender();
}

void Test::onUIRender()
{
	ImGui::Begin("Tests");
	ImGui::SetWindowFontScale(3.0f);
	if (!mCurrentTest) {
		for (unsigned long i = 0; i < mTests.size(); i++) {
			if (ImGui::Button(mTests[i].first.c_str())) {
				mCurrentTest = mTests[i].second();
			}
		}
		goto end;
	}

	if (ImGui::Button("<--")) {
		delete mCurrentTest;
		mCurrentTest = nullptr;
		goto end;
	}
	
	mCurrentTest->onUIRender();

end:
	ImGui::End();
}
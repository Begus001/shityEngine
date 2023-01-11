#include "test.h"

void Test::onStart()
{
	mRenderer = std::make_unique<se::Renderer>();
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
		for (auto &cur : mTests) {
			if (ImGui::Button(cur.first.c_str())) {
				mCurrentTest = cur.second();
			}
		}
		if (ImGui::Button("Quit"))
			exit(0);
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
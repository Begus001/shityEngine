#pragma once

#include "test.h"

class TestClear : public Test {
public:
	TestClear();
	
	void onRender() override;
	void onUIRender() override;

private:
	std::unique_ptr<se::Renderer> mRenderer;
	float mClearColor[4];
};
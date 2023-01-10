#pragma once

#include "test.h"

class TestClear : public Test {
public:
	TestClear();
	~TestClear() override;
	
	void onRender() override;
	void onUIRender() override;

private:
	se::Renderer *mRenderer;
	float mClearColor[4];
};
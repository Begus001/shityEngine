#pragma once

#include <shityEngine.h>
#include <renderer/renderer.h>
#include <imgui/imgui.h>
#include <vector>
#include <functional>

class Test : public se::ShityApplication {
public:
	Test();

	virtual ~Test();

	virtual void onStart() override;

	virtual void onUpdate() override;

	virtual void onRender() override;

	virtual void onUIRender() override;

	template <typename T>
	void addTest(const std::string &name)
	{
		mTests.push_back(std::make_pair(name, []() { return new T(); }));
	}

private:
	se::Renderer *mRenderer;
	std::vector<std::pair<const std::string &, std::function<Test *()>>> mTests;
	Test *mCurrentTest = nullptr;
};
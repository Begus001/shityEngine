#pragma once

#include <shityEngine.h>
#include <renderer/renderer.h>
#include <imgui/imgui.h>
#include <vector>
#include <functional>
#include <memory>

class Test : public se::ShityApplication {
public:
	Test() {}
	virtual ~Test() {}

	virtual void onStart() override;
	virtual void onUpdate() override;
	virtual void onRender() override;
	virtual void onUIRender() override;

	template <typename T>
	void addTest(const std::string &name)
	{
		se::Log::d("Adding test: %s", name.c_str());
		mTests.push_back(std::make_pair(name, []() { return new T(); }));
	}

private:
	std::unique_ptr<se::Renderer> mRenderer;
	std::vector<std::pair<const std::string, std::function<Test *()>>> mTests;
	Test *mCurrentTest = nullptr;
};
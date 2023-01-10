#pragma once

#include <string>

#include <window/window.h>
#include <logging/logging.h>

namespace se
{

class ShityApplication {
	public:
		ShityApplication(){}
		~ShityApplication(){}

		virtual void onStart() = 0;
		virtual void onUpdate() = 0;
		virtual void onRender() = 0;
		virtual void onUIRender() = 0;

		void run(std::string name);

	private:
		std::string mName;
};

}
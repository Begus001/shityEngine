#pragma once

#include <string>

namespace se
{

class ShityApplication {
	public:
		ShityApplication(){}
		~ShityApplication(){}

		virtual void onStart(){}
		virtual void onUpdate(){}
		virtual void onRender(){}

		void run(std::string name);

	private:
		std::string mName;
};

}
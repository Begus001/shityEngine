#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <shityEngine.h>
#include <logging/logging.h>
#include <imgui/imgui.h>

#include "test.h"
#include "testClear.h"
#include "testTriangle.h"

int main(void)
{
	Test test;
	test.addTest<TestClear>("Clear test");
	test.addTest<TestColorTriangle>("Triangle test");
	test.run("Test");
}
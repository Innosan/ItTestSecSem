#include <sstream>
#include <iostream>
#include <cassert>

#include "Tests.h"
#include "MenuOption.h"

using namespace std;

void testMenuOptionPrint() {

	// Redirect std::cout
	ostringstream oss;
	streambuf* p_cout_streambuf = std::cout.rdbuf();
	cout.rdbuf(oss.rdbuf());

	// Create a MenuOption and call print
	MenuOption option(1, "Test Option", {});
	option.print();

	// Check the output
	string expectedOutput = "1. Test Option\n";
	assert(oss.str() == expectedOutput);

	// Reset std::cout
	cout.rdbuf(p_cout_streambuf);

	cout << "Test passed: MenuOption::print" << endl;
}
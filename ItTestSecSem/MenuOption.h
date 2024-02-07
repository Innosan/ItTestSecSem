#pragma once

#include <functional>
#include "FileManager.h"

using namespace std;

/**
 * \brief Represents a menu option with action as lambda.
 */
class MenuOption
{
	int id;
	string title;
	function<void()> action;

public:
	// constructor
	MenuOption(const int id, const string& title, const function<void()>& action)
		: id(id), title(title), action(action) {}

	void print();
	void callAction();
};


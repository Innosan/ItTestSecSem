#pragma once

#include <vector>
#include "MenuOption.h"

using namespace std;

/**
 * \brief Responsible for managing a collection of menu options (menu).
 * Basic usage - initialize a menu with vector of MenuOption, then call actions
 */
class Menu
{
	vector<MenuOption> options;

public:
	// constructor
	Menu(const std::vector<MenuOption>& options) : options(options) {}

	void display();

	/**
	 * \brief Calling a menu action.
	 *
	 * \param index of option to call
	 */
	void choose(int index);
};


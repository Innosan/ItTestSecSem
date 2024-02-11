#pragma once

#include <iostream>
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
	enum optionsIds {
		PRINT_FILES = 1,
		SORT_FILES,
		FILES_ABOVE_SIZE,
		FILES_ABOVE_USAGE,
		RUN_TESTS,
		READ_FROM_FILE,
		EXIT,
	};

	void initializeMenu(std::unique_ptr<FileManager>& fileManager);
	void display();

	/**
	 * \brief Calling a menu action.
	 *
	 * \param index of option to call
	 */
	void choose(int index);
};


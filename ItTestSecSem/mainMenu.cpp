#include <iostream>
#include <vector>

#include "mainMenu.h"
#include "MenuOption.h"
#include "Menu.h"

using namespace std;

void mainMenu() {
	std::vector<MenuOption> items = {
		MenuOption(1, "Option 1",  []() { cout << "You chose Option 1.\n"; }),
		MenuOption(2, "Option 2",  []() { cout << "You chose Option 2.\n"; }),
		MenuOption(3, "Option 3",  []() {
			cout << "You chose Option 3.\n";
			cout << "You chose Option 3.\n";
		})
	};

	Menu menu(items);

	menu.display();

	cout << "\n\nEnter your choice: ";
	int choice;
	cin >> choice;

	menu.choose(choice);
}

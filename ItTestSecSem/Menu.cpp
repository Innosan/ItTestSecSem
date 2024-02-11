#include "Menu.h"
#include "MenuOption.h"

void Menu::display() {
	std::cout << "\n";

	for (MenuOption item : this->options) {
		item.print();
	}
}

void Menu::choose(int index) {
	if (index >= 1 && index <= this->options.size()) {
		this->options[index - 1].callAction();
	}
	else {
		std::cout << "Invalid choice.\n";
	}
}

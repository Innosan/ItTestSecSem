#include "MenuOption.h"
#include <iostream>

using namespace std;

void MenuOption::print() {
	cout << this->id << ". " << this->title << endl;
}

void MenuOption::callAction() {
	this->action();
}
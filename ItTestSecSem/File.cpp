#include <iostream>

#include "File.h"

string File::getTitle() {
	return this->title;
}

int File::getSize() {
	return this->size;
}

int File::getUsage() {
	return this->usage;
}

int File::getId() {
	return this->id;
}

void File::printFile() {
	cout << this->id << ". " << this->title << '\t' << this->createdAt << '\t';
	cout << this->size << " bytes\t" << this->usage << endl;
}
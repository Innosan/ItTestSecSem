#include <iostream>

#include "File.h"

using namespace std;

string File::getTitle() {
	return this->title;
}

int File::getSize() {
	return this->size;
}

int File::getUsage() {
	return this->usage;
}

void File::printFile() {
	cout << this->id << ". " << this->title << '\t' << this->createdAt << '\t';
	cout << this->size << " bytes\t" << this->usage << endl;
}
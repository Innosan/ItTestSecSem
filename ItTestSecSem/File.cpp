#include <iostream>
#include <string>

#include "File.h"
#include "inputs.h"

string File::getTitle() {
	return this->title;
}

int File::getSize() {
	return this->size;
}

string File::getCreatedAt() {
	return this->createdAt;
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

File File::getFileFromInput() {
	int id = getIntUserInput("Input file id: ");

	cout << "Input file title: " << endl;
	string title;
	cin >> title;

	int day = getIntUserInput("Input file creation day: ", 0, 32);
	int month = getIntUserInput("Input file creation month: ", 0, 13);
	int year = getIntUserInput("Input file creation day: ", 1969, 2025);
	string createdAt = to_string(year) + '-' + to_string(month) + '-' + to_string(day);

	int size = getIntUserInput("Input file size: ");
	int usage = getIntUserInput("Input file usage: ", -1);

	return File(id, title, createdAt, size, usage);
}
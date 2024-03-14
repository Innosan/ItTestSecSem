#pragma once
#include <iostream>

using namespace std;

/**
 * \brief Represents the file object.
 */
class File
{
	string title;
	string createdAt;

	int size;
	int usage;

public:
	// constructor
	File(std::string title, std::string createdAt, int size, int usage)
		: title(title), createdAt(createdAt), size(size), usage(usage) {}

	// getters
	int getSize();
	int getUsage();
	string getTitle();
	string getCreatedAt();

	static File getFileFromInput();

	// showers
	void printFile();
};

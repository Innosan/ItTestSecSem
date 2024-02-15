#pragma once
#include <iostream>

using namespace std;

/**
 * \brief Represents the file object.
 */
class File
{
	int id;

	string title;
	string createdAt;

	int size;
	int usage;

public:
	// constructor
	File(int id, std::string title, std::string createdAt, int size, int usage)
		: id(id), title(title), createdAt(createdAt), size(size), usage(usage) {}

	// getters
	int getId();
	int getSize();
	int getUsage();
	string getTitle();
	string getCreatedAt();

	static File getFileFromInput();

	// showers
	void printFile();
};


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
	// default constructor
	File(int id, std::string title, std::string createdAt, int size, int usage)
		: id(id), title(title), createdAt(createdAt), size(size), usage(usage) {}

	// getters
	string getTitle();
	int getSize();
	int getUsage();

	//showers
	void printFile();
};


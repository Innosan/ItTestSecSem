#pragma once
#include <vector>

#include "File.h"

using namespace std;

/**
 * \brief Responsible for managing a collection of files.
 *
 */
class FileManager
{
	vector<File> files;

public:
	/**
	 * \brief Initialize a collection with basic files.
	 *
	 */
	void initializeFiles();

	/**
	 * \brief Prints out collection of files.
	 *
	 */
	void printFiles();

	/**
	 * \brief Prints out given vector of File objects.
	 *
	 * \param vectorFiles - vector to print
	 */
	static void printVectorOfFiles(vector<File> vectorFiles);


	// Actions with collection

	/**
	 * \brief Adds file to the collection.
	 *
	 * \param file - file to add
	 */
	void addFile(const File& file);

	/**
	 * \brief Returns a vector of File objects sorted in alphabetical order.
	 *
	 * \return vector of files
	 */
	vector<File> getSortedFiles();

	/**
	 * \brief Returns a vector of File objects that have a size greater than the given size.
	 *
	 * \param size of file as lower bound
	 * \return vector of files
	 */
	vector<File> getFilesAboveSize(int size);

	/**
	 * \brief Returns a vector of File objects that have a usage greater than the given usage.
	 *
	 * \param usage of file as lower bound
	 * \return vector of files
	 */
	vector<File> getFilesAboveUsage(int usage);
};
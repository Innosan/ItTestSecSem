#pragma once

#include <iostream>
#include <vector>

#include "FileManager.h"
#include "File.h"

/**
 * \brief Runs test for FileManager::getSortedFiles function.
 *
 * \param fileManager - FileManager object.
 * \param filesToTest - vector of files to test.
 * \param expectedFiles - expected result vector.
 * \param caseTitle - title of the test case.
 */
void runSortTest(
	std::unique_ptr<FileManager>& fileManager,
	vector<File>& filesToTest,
	vector<File>& expectedFiles,
	const std::string caseTitle
);

/**
 * \brief Runs test for FileManager::getFilesAboveSize function.
 *
 * \param fileManager - FileManager object.
 * \param filesToTest - vector of files to test.
 * \param expectedFiles - expected result vector.
 * \param caseTitle - title of the test case.
 * \param testSize - size of file to test.
 */
void runSizeTest(
	std::unique_ptr<FileManager>& fileManager,
	vector<File>& filesToTest,
	vector<File>& expectedFiles,
	const std::string caseTitle,
	const int testSize
);

/**
 * \brief Runs test for FileManager::getFilesAboveUsage function.
 *
 * \param fileManager - FileManager object.
 * \param filesToTest - vector of files to test.
 * \param expectedFiles - expected result vector.
 * \param caseTitle - title of the test case.
 * \param testUsage - usage of file to test.
 */
void runUsageTest(
	std::unique_ptr<FileManager>& fileManager,
	vector<File>& filesToTest,
	vector<File>& expectedFiles,
	const std::string caseTitle,
	const int testUsage
);
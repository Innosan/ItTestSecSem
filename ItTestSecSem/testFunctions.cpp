#include <iostream>
#include <vector>

#include "FileManager.h"
#include "File.h"
#include "testFunctions.h"
#include "testUtils.h"

void runSortTest(
	std::unique_ptr<FileManager>& fileManager,
	vector<File>& filesToTest,
	vector<File>& expectedFiles,
	const std::string caseTitle
) {
	fileManager->setFiles(filesToTest);
	vector<File> sortedTestFiles = fileManager->getSortedFiles();

	bool checkStatus = runVectorCheck(sortedTestFiles, expectedFiles);

	printTestResults(checkStatus, "getSortedFiles", caseTitle);
}

void runSizeTest(
	std::unique_ptr<FileManager>& fileManager,
	vector<File>& filesToTest,
	vector<File>& expectedFiles,
	const std::string caseTitle,
	const int testSize
) {
	fileManager->setFiles(filesToTest);
	vector<File> aboveSizeFiles = fileManager->getFilesAboveSize(testSize);

	bool checkStatus = runVectorCheck(aboveSizeFiles, expectedFiles);

	printTestResults(checkStatus, "getFilesAboveSize", caseTitle);
}

void runUsageTest(
	std::unique_ptr<FileManager>& fileManager,
	vector<File>& filesToTest,
	vector<File>& expectedFiles,
	const std::string caseTitle,
	const int testUsage
) {
	fileManager->setFiles(filesToTest);
	vector<File> aboveUsageFiles = fileManager->getFilesAboveUsage(testUsage);

	bool checkStatus = runVectorCheck(aboveUsageFiles, expectedFiles);

	printTestResults(checkStatus, "getFilesAboveUsage", caseTitle);
}
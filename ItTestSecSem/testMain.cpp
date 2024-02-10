#include <iostream>
#include <vector>

#include "File.h"
#include "FileManager.h"
#include "TestCase.h"

#include "testMain.h"
#include "testFunctions.h"

void runTests() {
	std::unique_ptr<FileManager> fileManager = std::make_unique<FileManager>();

	vector<TestCase> testCases = {
		// General case
		// Different alphabetical order
		// Size/usage in middle (60, 3)
		TestCase(
			"General Case",
			vector<File>{
				{1, "Document B", "2024-02-08", 100, 2},
				{2, "Document A", "2024-02-07", 50, 4},
				{3, "Document C", "2024-02-09", 150, 6}
			},
			vector<File>{
				{2, "Document A", "2024-02-07", 50, 4},
				{1, "Document B", "2024-02-08", 100, 2},
				{3, "Document C", "2024-02-09", 150, 6}
			},
			vector<File>{
				{1, "Document B", "2024-02-08", 100, 2},
				{3, "Document C", "2024-02-09", 150, 6}
			},
			vector<File>{
				{2, "Document A", "2024-02-07", 50, 4},
				{3, "Document C", "2024-02-09", 150, 6}
			},
			60,
			3
		),
	};

	for (TestCase testCase : testCases)
	{
		runSortTest(fileManager, testCase.filesToTest, testCase.expectedSortResult, testCase.title);
		runSizeTest(fileManager, testCase.filesToTest, testCase.expectedSizeResult, testCase.title, testCase.sizeToTest);
		runUsageTest(fileManager, testCase.filesToTest, testCase.expectedUsageResult, testCase.title, testCase.usageToTest);
	}


	//// Mixed case and special characters
	//// Size above ALL
	//// Original vector
	//vector<File> files1 = {
	//	{1, "Document_A.txt", "2024-02-09", 100, 4},
	//	{2, "document b", "2024-02-08", 50, 2},
	//	{3, "CaSe_SeNsItIvE.pdf", "2024-02-07", 150, 6}
	//};

	//// Expected sorted vector
	//vector<File> expectedSortedFiles1 = {
	//	{3, "CaSe_SeNsItIvE.pdf", "2024-02-07", 150, 3},
	//	{1, "Document_A.txt", "2024-02-09", 100, 2},
	//	{2, "document b", "2024-02-08", 50, 1}
	//};

	//// Expected size vector
	//vector<File> expectedSizeFiles1 = {
	//};

	//runSortTest(fileManager, files1, expectedSortedFiles1, "Mixed case and special characters");
	//runSizeTest(fileManager, files1, expectedSizeFiles1, "Size above ALL", 200);
	//files1, expectedSortedFiles1, expectedSizeFiles1 = vector<File>();


	//// Numbers and symbols:
	//// Size below ALL
	//// Original vector
	//vector<File> files2 = {
	//	{4, "File 123", "2024-02-06", 20, 0},
	//	{5, "File.with!symbols", "2024-02-05", 200, 4},
	//	{6, "File%with&percent", "2024-02-10", 120, 2}
	//};

	//// Expected sorted vector
	//vector<File> expectedSortedFiles2 = {
	//	{4, "File 123", "2024-02-06", 20, 0},
	//	{6, "File%with&percent", "2024-02-10", 120, 2},
	//	{5, "File.with!symbols", "2024-02-05", 200, 4}
	//};

	//// Expected size vector
	//vector<File> expectedSizeFiles2 = {
	//	{4, "File 123", "2024-02-06", 20, 0},
	//	{5, "File.with!symbols", "2024-02-05", 200, 4},
	//	{6, "File%with&percent", "2024-02-10", 120, 2}
	//};

	//runSortTest(fileManager, files2, expectedSortedFiles2, "Numbers and symbols");
	//runSizeTest(fileManager, files2, expectedSizeFiles2, "Size below ALL", 10);
	//files2, expectedSortedFiles2 = vector<File>();


	//// Duplicates and leading/trailing spaces:
	//// Size equal to one (40)
	//// Original vector
	//vector<File> files3 = {
	//	{8, "  Duplicate2", "2024-02-01", 60, 5},
	//	{7, "Duplicate1  ", "2024-01-31", 80, 1},
	//	{9, "Another File", "2024-02-02", 40, 3}
	//};

	//// Expected sorted vector
	//vector<File> expectedSortedFiles3 = {
	//	{8, "  Duplicate2", "2024-02-01", 60, 5},
	//	{9, "Another File", "2024-02-02", 40, 3},
	//	{7, "Duplicate1  ", "2024-01-31", 80, 1}
	//};

	//// Expected size vector
	//vector<File> expectedSizeFiles3 = {
	//	{8, "  Duplicate2", "2024-02-01", 60, 5},
	//	{7, "Duplicate1  ", "2024-01-31", 80, 1}
	//};

	//runSortTest(fileManager, files3, expectedSortedFiles3, "Duplicates and leading/trailing spaces");
	//runSizeTest(fileManager, files3, expectedSizeFiles3, "Size equal to one (40)", 40);
	//files3, expectedSortedFiles3 = vector<File>();


	//// Tilde and backtick and empty title:
	//// Size slightly below one (89)
	//// Original vector
	//vector<File> files4 = {
	//	{10, "", "2024-02-03", 130, 2},
	//	{11, "Empty Title", "2024-02-04", 90, 1},
	//	{12, "File~with`tilde", "2024-02-02", 50, 3}
	//};

	//// Expected sorted vector
	//vector<File> expectedSortedFiles4 = {
	//	{10, "", "2024-02-03", 130, 2},
	//	{11, "Empty Title", "2024-02-04", 90, 1},
	//	{12, "File~with`tilde", "2024-02-02", 50, 3}
	//};

	//// Expected size vector
	//vector<File> expectedSizeFiles4 = {
	//	{10, "", "2024-02-03", 130, 2},
	//	{11, "Empty Title", "2024-02-04", 90, 1},
	//};

	//runSortTest(fileManager, files4, expectedSortedFiles4, "Tilde and backtick and empty title");
	//runSizeTest(fileManager, files4, expectedSizeFiles4, "Size slightly below one (89)", 89);
	//files4, expectedSortedFiles4 = vector<File>();


	//// 
}
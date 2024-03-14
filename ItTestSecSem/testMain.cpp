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
		// Different alphabetical order
		// Size/usage in middle (60, 3)
		TestCase(
			"Different alphabetical order, Size/usage in middle (60, 3)",
			vector<File>{
				{"Document B", "2024-02-08", 100, 2},
				{"Document A", "2024-02-07", 50, 4},
				{"Document C", "2024-02-09", 150, 6}
			},
			vector<File>{
				{"Document A", "2024-02-07", 50, 4},
				{"Document B", "2024-02-08", 100, 2},
				{"Document C", "2024-02-09", 150, 6}
			},
			vector<File>{
				{"Document B", "2024-02-08", 100, 2},
				{"Document C", "2024-02-09", 150, 6}
			},
			vector<File>{
				{"Document A", "2024-02-07", 50, 4},
				{"Document C", "2024-02-09", 150, 6}
			},
			60,
			3
		),
		// Mixed case and special characters
		// Size/usage above all
		TestCase(
			"Mixed case and special characters, Size/usage above all",
			vector<File>{
				{"Document_A.txt", "2024-02-09", 100, 2},
				{"CaSe_SeNsItIvE.pdf", "2024-02-07", 150, 3},
				{"document b", "2024-02-08", 50, 1}
			},
			vector<File>{
				{"CaSe_SeNsItIvE.pdf", "2024-02-07", 150, 3},
				{"Document_A.txt", "2024-02-09", 100, 2},
				{"document b", "2024-02-08", 50, 1}
			},
			vector<File>{
			},
			vector<File>{
			},
			200,
			10
		),
		// Numbers and symbols
		// Size/usage below all
		TestCase(
			"Numbers and symbols, Size/usage below all",
			vector<File>{
				{"File 123", "2024-02-06", 20, 1},
				{"File.with!symbols", "2024-02-05", 200, 4},
				{"File%with&percent", "2024-02-10", 120, 2}
			},
			vector<File>{
				{"File 123", "2024-02-06", 20, 1},
				{"File%with&percent", "2024-02-10", 120, 2},
				{"File.with!symbols", "2024-02-05", 200, 4}
			},
			vector<File>{
				{"File 123", "2024-02-06", 20, 1},
				{"File.with!symbols", "2024-02-05", 200, 4},
				{"File%with&percent", "2024-02-10", 120, 2}
			},
			vector<File>{
				{"File 123", "2024-02-06", 20, 1},
				{"File.with!symbols", "2024-02-05", 200, 4},
				{"File%with&percent", "2024-02-10", 120, 2}
			},
			10,
			0
		),
		// Duplicates and leading/trailing spaces
		// Size equal to one (40/3)
		TestCase(
			"Duplicates and leading/trailing spaces, Size equal to one (40/3)",
			vector<File>{
				{"  Duplicate2", "2024-02-01", 60, 5},
				{"Duplicate1  ", "2024-01-31", 80, 1},
				{"Another File", "2024-02-02", 40, 3}
			},
			vector<File>{
				{"  Duplicate2", "2024-02-01", 60, 5},
				{"Another File", "2024-02-02", 40, 3},
				{"Duplicate1  ", "2024-01-31", 80, 1}
			},
			vector<File>{
				{"  Duplicate2", "2024-02-01", 60, 5},
				{"Duplicate1  ", "2024-01-31", 80, 1}
			},
			vector<File>{
				{"  Duplicate2", "2024-02-01", 60, 5},
			},
			40,
			3
		),
		// Tilde and backtick and empty title
		// Size/usage slightly below one (89/2)
		TestCase(
			"Tilde and backtick and empty title, Size/usage slightly below one (89/2)",
			vector<File>{
				{"", "2024-02-03", 130, 6},
				{"Empty Title", "2024-02-04", 90, 1},
				{"File~with`tilde", "2024-02-02", 50, 3}
			},
			vector<File>{
				{"", "2024-02-03", 130, 6},
				{"Empty Title", "2024-02-04", 90, 1},
				{"File~with`tilde", "2024-02-02", 50, 3}
			},
			vector<File>{
				{"", "2024-02-03", 130, 6},
				{"Empty Title", "2024-02-04", 90, 1},
			},
			vector<File>{
				{"", "2024-02-03", 130, 6},
				{"File~with`tilde", "2024-02-02", 50, 3}
			},
			89,
			2
		),
	};

	for (TestCase testCase : testCases)
	{
		runSortTest(fileManager, testCase.filesToTest, testCase.expectedSortResult, testCase.title);
		runSizeTest(fileManager, testCase.filesToTest, testCase.expectedSizeResult, testCase.title, testCase.sizeToTest);
		runUsageTest(fileManager, testCase.filesToTest, testCase.expectedUsageResult, testCase.title, testCase.usageToTest);
	}

	cout << "Testing successfull!";
}
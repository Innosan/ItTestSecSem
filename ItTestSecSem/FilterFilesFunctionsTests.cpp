#include <iostream>
#include <vector>

#include "File.h"
#include "FileManager.h"

void runSortTest(std::unique_ptr<FileManager>& fileManager, vector<File>& filesToTest, vector<File>& expectedFiles, std::string caseTitle) {
	bool passed = true;

	fileManager->setFiles(filesToTest);
	vector<File> sortedTestFiles = fileManager->getSortedFiles();

	for (int i = 0; i < sortedTestFiles.size(); i++) {
		// std::cout << sortedTestFiles[i].getId() << " expected to be " << expectedFiles[i].getId() << std::endl;

		if (sortedTestFiles[i].getId() != expectedFiles[i].getId()) {
			passed = false;

			break;
		}
	}

	passed ?
		std::cout << "Test passed: getSortedFiles() - " << caseTitle << std::endl :
		std::cout << "Test failed: getSortedFiles() - " << caseTitle << std::endl;
}

void testGetSortedFiles() {
	bool passed = true;

	std::unique_ptr<FileManager> fileManager = std::make_unique<FileManager>();


	// General case
	// Different alphabetical order
	vector<File> files0 = {
		{1, "Document B", "2024-02-08", 100, 2},
		{2, "Document A", "2024-02-07", 50, 1},
		{3, "Document C", "2024-02-09", 150, 3}
	};

	vector<File> expectedSortedFiles0 = {
		{2, "Document A", "2024-02-07", 50, 1},
		{1, "Document B", "2024-02-08", 100, 2},
		{3, "Document C", "2024-02-09", 150, 3}
	};

	runSortTest(fileManager, files0, expectedSortedFiles0, "General case");


	// Mixed case and special characters:
	// Original vector
	vector<File> files1 = {
		{1, "Document_A.txt", "2024-02-09", 100, 2},
		{2, "document b", "2024-02-08", 50, 1},
		{3, "CaSe_SeNsItIvE.pdf", "2024-02-07", 150, 3}
	};

	// Expected sorted vector
	vector<File> expectedSortedFiles1 = {
		{3, "CaSe_SeNsItIvE.pdf", "2024-02-07", 150, 3},
		{1, "Document_A.txt", "2024-02-09", 100, 2},
		{2, "document b", "2024-02-08", 50, 1}
	};

	runSortTest(fileManager, files1, expectedSortedFiles1, "Mixed case and special characters");


	// Numbers and symbols:
	// Original vector
	vector<File> files2 = {
		{4, "File 123", "2024-02-06", 20, 0},
		{5, "File.with!symbols", "2024-02-05", 200, 4},
		{6, "File%with&percent", "2024-02-10", 120, 2}
	};

	// Expected sorted vector
	vector<File> expectedSortedFiles2 = {
		{4, "File 123", "2024-02-06", 20, 0},
		{6, "File%with&percent", "2024-02-10", 120, 2},
		{5, "File.with!symbols", "2024-02-05", 200, 4}
	};

	runSortTest(fileManager, files2, expectedSortedFiles2, "Numbers and symbols");


	// Duplicates and leading/trailing spaces:
	// Original vector
	vector<File> files3 = {
		{8, "  Duplicate2", "2024-02-01", 60, 5},
		{7, "Duplicate1  ", "2024-01-31", 80, 1},
		{9, "Another File", "2024-02-02", 40, 3}
	};

	// Expected sorted vector
	vector<File> expectedSortedFiles3 = {
		{8, "  Duplicate2", "2024-02-01", 60, 5},
		{9, "Another File", "2024-02-02", 40, 3},
		{7, "Duplicate1  ", "2024-01-31", 80, 1}
	};

	runSortTest(fileManager, files3, expectedSortedFiles3, "Duplicates and leading/trailing spaces");


	// Tilde and backtick and empty title:
	// Original vector
	vector<File> files4 = {
		{10, "", "2024-02-03", 130, 2},
		{11, "Empty Title", "2024-02-04", 90, 1},
		{12, "File~with`tilde", "2024-02-02", 50, 3}
	};

	// Expected sorted vector
	vector<File> expectedSortedFiles4 = {
		{10, "", "2024-02-03", 130, 2},
		{11, "Empty Title", "2024-02-04", 90, 1},
		{12, "File~with`tilde", "2024-02-02", 50, 3}
	};

	runSortTest(fileManager, files4, expectedSortedFiles4, "Tilde and backtick and empty title");
}

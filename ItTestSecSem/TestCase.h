#pragma once
#include <iostream>
#include <vector>
#include <functional>

#include "File.h"
#include "FileManager.h"

class TestCase
{
public:
	std::string title;

	std::vector<File> filesToTest;

	std::vector<File> expectedSortResult;
	std::vector<File> expectedSizeResult;
	std::vector<File> expectedUsageResult;

	int sizeToTest = 0;
	int usageToTest = 0;

	TestCase(
		std::string title,
		std::vector<File> filesToTest,
		std::vector<File> expectedSortResult,
		std::vector<File> expectedSizeResult,
		std::vector<File> expectedUsageResult,
		int sizeToTest = 0,
		int usageToTest = 0
	) : title(title),
		filesToTest(filesToTest),
		expectedSortResult(expectedSortResult),
		expectedSizeResult(expectedSizeResult),
		expectedUsageResult(expectedUsageResult),
		sizeToTest(sizeToTest),
		usageToTest(usageToTest)
	{}
};


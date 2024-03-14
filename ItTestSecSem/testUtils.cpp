#include <iostream>
#include <string>
#include <vector>

#include "File.h"
#include "testUtils.h"

bool runVectorCheck(vector<File>& vectorToCheck, vector<File>& expectedVector) {
	bool passed = true;

	for (size_t i = 0; i < vectorToCheck.size(); ++i) {
		string actualId = vectorToCheck[i].getTitle();
		string expectedId = expectedVector[i].getTitle();

		// cout << "Actual: " << actualId << " Expected: " << expectedId << endl;

		if (actualId != expectedId) {
			std::cerr << "\n\nError: Mismatch at index " << i << ": "
				<< actualId << " != " << expectedId << "\n\n";
			return false;
		}
	}

	return passed;
}

void printTestResults(const bool checkStatus, const std::string functionTitle, const std::string caseTitle) {
	/*checkStatus ?
		std::cout << "Test passed: " << functionTitle << " - " << caseTitle << std::endl :
		std::cout << "Test failed: " << functionTitle << " - " << caseTitle << std::endl;*/
}
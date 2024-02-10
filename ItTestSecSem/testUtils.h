#pragma once

#include <vector>
#include <iostream>

#include "File.h"

/**
 * \brief Utility function to check if actual result vector is equal to expected result vector.
 *
 * \param vectorToCheck - actual vector to test.
 * \param expectedVector - expected result vector.
 *
 * \return true if vectors are equal, false otherwise.
 */
bool runVectorCheck(vector<File>& vectorToCheck, vector<File>& expectedVector);

/**
 * \brief Print test results to the console.
 *
 * \param checkStatus - status of the test.
 * \param functionTitle - title of the function that was tested.
 * \param caseTitle - title of the test case.
 */
void printTestResults(const bool checkStatus, const std::string functionTitle, const std::string caseTitle);
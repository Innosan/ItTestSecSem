#pragma once

#include <iostream>
#include <vector>

#include "File.h"

using namespace std;

/**
 * \brief Check if a file exists.
 *
 * \param filename - name of the file to check
 *
 * \return true if the file exists, false otherwise
 */
bool fileExists(const std::string& filename);

/**
 * \brief Prompt user for overwrite confirmation.
 *
 * \param filename - name of the file to overwrite
 *
 * \return true if the user confirms the overwrite, false otherwise
 */
bool confirmOverwrite(const std::string& filename);

/**
 * Reads data from a file and constructs a vector of File objects.
 *
 * \param fileName The name of the file to read.
 * \return A vector of File objects, or an empty vector if there was an error.
 */
vector<File> getFilesFromFile(string fileName);

/**
 * Exports data to a file.
 *
 * \param filesToExport A vector of File objects to export.
 */
void exportToFile(vector<File> filesToExport);

/**
 * \brief Check if a file path is valid.
 *
 * \param filePath - path to check
 *
 * \return true if the file path is valid, false otherwise
 */
bool isFilePathValid(const std::string& filePath);
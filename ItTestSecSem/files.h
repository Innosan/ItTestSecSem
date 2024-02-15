#pragma once

#include <iostream>
#include <vector>

#include "File.h"

using namespace std;

bool fileExists(const std::string& filename);

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

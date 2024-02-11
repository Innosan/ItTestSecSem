#pragma once

#include <iostream>
#include <vector>

#include "File.h"

using namespace std;

/**
 * Reads data from a file and constructs a vector of File objects.
 *
 * @param filename The name of the file to read.
 * @return A vector of File objects, or an empty vector if there was an error.
 */
vector<File> getFilesFromFile(string fileName);

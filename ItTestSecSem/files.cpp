#include <iostream>
#include <fstream>
#include <sstream>

#include "files.h"

using namespace std;

vector<File> getFilesFromFile(string fileName) {
	vector<File> files;

	ifstream inputFile(fileName);
	if (!inputFile.is_open()) {
		cerr << "Error opening file: " << fileName << endl;
		return files; // Return empty vector on error
	}

	string line;
	while (getline(inputFile, line)) {

		// Handle empty lines or lines with incorrect formatting
		if (line.empty()) {
			cerr << "Warning: Skipped empty line." << endl;
			continue;
		}

		stringstream ss(line);
		string token;
		int fieldCount = 0;

		int id = 0;
		string title = "";
		string createdAt = "";
		int size = 0;
		int usage = 0;

		// Extract data from the line
		while (getline(ss, token, ',')) {
			try {
				switch (fieldCount) {
				case 0: id = stoi(token); break;
				case 1: title = token; break;
				case 2: createdAt = token; break;
				case 3: size = stoi(token); break;
				case 4: usage = stoi(token); break;
				default:
					// Handle unexpected field count
					std::cerr << "Warning: parsing " << fieldCount << " field: " << "wrong number of fileds" << std::endl;
				}
			}
			catch (const std::invalid_argument& e) {
				// Handle conversion error
				std::cerr << "Warning: converting field " << fieldCount << ": " << e.what() << std::endl;
				// You can choose to skip the line, continue without the value, or throw an exception
			}

			fieldCount++;
		}

		// Create a File object and add it to the vector
		File file(id, title, createdAt, size, usage);
		files.push_back(file);
	}

	inputFile.close();
	return files;
};

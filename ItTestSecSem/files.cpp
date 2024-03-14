#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>

#include "File.h"
#include "files.h"

using namespace std;

// Function to check if a file exists
bool fileExists(const std::string& filename) {
	std::ifstream file(filename);
	return file.is_open();
}

// Function to prompt user for overwrite confirmation
bool confirmOverwrite(const std::string& filename) {
	std::cout << "File '" << filename << "' already exists." << std::endl;
	std::cout << "Do you want to overwrite it? (y/n): ";

	char answer;
	std::cin >> answer;

	return std::tolower(answer) == 'y';
}

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

		string title = "";
		string createdAt = "";
		int size = 0;
		int usage = 0;

		// Extract data from the line
		while (getline(ss, token, ',')) {
			try {
				switch (fieldCount) {
				case 0: title = token; break;
				case 1: createdAt = token; break;
				case 2: size = stoi(token); break;
				case 3: usage = stoi(token); break;
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
		File file(title, createdAt, size, usage);
		files.push_back(file);
	}

	inputFile.close();
	return files;
};

bool isFilePathValid(const std::string& filePath) {

	// Regular expression to match a valid file path (Windows)
	regex filePathRegex("^(?:[a-zA-Z]\\:|\\\\)\\\\([^\\\\]+\\\\)*[^\\/:*?\"<>|]+\\.csv$");

	if (!regex_match(filePath, filePathRegex)) {
		std::cerr << "Error: Invalid file path." << std::endl;
		return false;
	}

	return true;
}

void exportToFile(vector<File> filesToExport) {
	string fileName = "";

	string path = "";

	do {
		cout << "Input file name (only csv available): ";
		cin >> fileName;

		cout << "Input full path: \n";
		cin >> path;

	} while (!isFilePathValid(path + fileName));

	string fullPath = path + fileName;

	// Check if file exists and prompt user for overwrite
	if (fileExists(fullPath)) {
		if (!confirmOverwrite(fullPath)) {
			std::cerr << "Error: File already exists and user chose not to overwrite." << std::endl;
			return;
		}
	}

	// Write data to file
	ofstream file(path + fileName);
	if (file.is_open()) {
		for (File& exportFile : filesToExport) {
			file << exportFile.getTitle() << "," << exportFile.getCreatedAt() << ","
				<< exportFile.getSize() << "," << exportFile.getUsage() << "\n";
		}
		file.close();
	}
	else {
		std::cerr << "Error opening file for writing." << std::endl;
	}
};

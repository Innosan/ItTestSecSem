#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>
#include <string>

#include "File.h"
#include "files.h"
#include "inputs.h"

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

bool isFileNameValid(const std::string& fileName) {
	// Regular expression to match a valid file name
	regex fileNameRegex("^[^\\/:*?\"<>|]+\\.csv$");
	// Regular expression to match reserved file names in Windows
	regex fileNameReservedNames("^(?:CON|PRN|AUX|NUL|COM[1-9]|LPT[1-9]|con|prn|aux|nul|com[1-9]|lpt[1-9])(?:\\..*)?$");
	// Regular expression to match reserved characters in Windows file names
	regex fileNameReservedChars("[\\/:*?\"<>|]");

	if (!regex_match(fileName, fileNameRegex)) {
		std::cerr << "Error: Invalid file name." << std::endl;
		return false;
	}

	if (regex_match(fileName, fileNameReservedNames)) {
		std::cerr << "Error: Invalid file name. Using reserved filenames is prohibited!" << std::endl;
		return false;
	}

	if (regex_search(fileName, fileNameReservedChars)) {
		std::cerr << "Error: Invalid file name. Using reserved characters is prohibited!" << std::endl;
		return false;
	}

	return true;
}

string getValidFilePath() {
	bool isPathValid = false;
	bool isNameValid = false;

	string filename = "";
	string filepath = "";

	while (!isPathValid && !isNameValid) {
		filename = getStringUserInput("Input filename (only csv acceptable): ");
		filepath = getStringUserInput("Input full path to path: ");

		if (isFilePathValid(filepath + filename) && isFileNameValid(filename)) {
			isPathValid = true;
			isNameValid = true;
		}
	}

	return filepath + filename;
}


void exportToFile(vector<File> filesToExport) {
	string fullPath = getValidFilePath();

	// Check if file exists and prompt user for overwrite
	if (fileExists(fullPath)) {
		if (!confirmOverwrite(fullPath)) {
			std::cerr << "Error: File already exists and user chose not to overwrite." << std::endl;
			return;
		}
	}

	// Write data to file
	ofstream file(fullPath);
	if (file.is_open()) {
		for (File& exportFile : filesToExport) {
			file << exportFile.getTitle() << "," << exportFile.getCreatedAt() << ","
				<< exportFile.getSize() << "," << exportFile.getUsage() << "\n";
		}

		file.close();
		std::cout << "Data successfully exported to file: " << fullPath << std::endl;
	}
	else {
		std::cerr << "Error opening file for writing." << std::endl;
	}
};

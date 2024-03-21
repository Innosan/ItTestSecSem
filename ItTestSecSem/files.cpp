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

bool fileExists(const string& filename) {
	ifstream file(filename);
	return file.is_open();
}

bool confirmOverwrite(const string& filename) {
	cout << "File '" << filename << "' already exists." << endl;
	cout << "Do you want to overwrite it? (y/n): ";

	char answer;
	cin >> answer;

	return tolower(answer) == 'y';
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
					cerr << "Warning: parsing " << fieldCount << " field: " << "wrong number of fileds" << endl;
				}
			}
			catch (const invalid_argument& e) {
				// Handle conversion error
				cerr << "Warning: converting field " << fieldCount << ": " << e.what() << endl;
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
		cerr << "Error: Invalid file path." << endl;
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
		cerr << "Error: Invalid file name." << std::endl;
		return false;
	}

	if (regex_match(fileName, fileNameReservedNames)) {
		cerr << "Error: Invalid file name. Using reserved filenames is prohibited!" << std::endl;
		return false;
	}

	if (regex_search(fileName, fileNameReservedChars)) {
		cerr << "Error: Invalid file name. Using reserved characters is prohibited!" << std::endl;
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

string getOverwriteConfirmation(const string& fullPath) {
	while (fileExists(fullPath)) {
		if (confirmOverwrite(fullPath)) {
			return fullPath;
		}
		else {
			cout << "Please choose another file." << endl;
			return getValidFilePath();
		}
	}
	return fullPath;
}

void exportToFile(vector<File> filesToExport) {
	string fullPath = getValidFilePath();
	fullPath = getOverwriteConfirmation(fullPath);

	// Try to open the file for writing
	ofstream file(fullPath);
	if (!file) {
		cerr << "Error: File is read-only or another error occurred." << endl;
		file.close();

		// Prompt the user to enter a new path
		while (true) {
			cout << "Please enter a new path." << endl;
			fullPath = getValidFilePath();
			fullPath = getOverwriteConfirmation(fullPath);

			// Try to open the new file for writing
			file.open(fullPath);
			if (file) {
				break;
			}
			else {
				cerr << "Error: File is read-only or another error occurred." << endl;
				file.close();
			}
		}
	}

	// Write data to file
	for (File& exportFile : filesToExport) {
		file << exportFile.getTitle() << "," << exportFile.getCreatedAt() << ","
			<< exportFile.getSize() << "," << exportFile.getUsage() << "\n";
	}

	file.close();
	cout << "Data successfully exported to file: " << fullPath << endl;
};

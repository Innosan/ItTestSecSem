#include <iostream>
#include <vector>

#include "inputs.h"
#include "testMain.h"
#include "files.h"
#include "Menu.h"
#include "MenuOption.h"

bool promptUserForExport() {
	cout << "Export results to file? (1/0)" << endl;

	bool isAgreed = getIntUserInput("", -1, 2);

	return isAgreed;
}

void Menu::initializeMenu(unique_ptr<FileManager>& fileManager) {
	vector<MenuOption> items = {
		// Print files
		MenuOption(this->PRINT_FILES, "Print files",  [&fileManager]() {
			fileManager->printFiles();
		}),

		// Add file
		MenuOption(this->ADD_FILE, "Add file",  [&fileManager]() {
			File file = File::getFileFromInput();

			fileManager->addFile(file);
		}),

		// Export to file
		MenuOption(this->EXPORT_TO_FILE, "Export to file",  [&fileManager]() {
			vector<File> filesToExport = fileManager->getFiles();

			if (filesToExport.size() == 0) cout << "No files to export!";
			else exportToFile(filesToExport);
		}),

		// Sort files
		MenuOption(Menu::optionsIds::SORT_FILES, "Get alphabetically sorted files",  [&fileManager]() {
			vector<File> sortedFiles = fileManager->getSortedFiles();
			if (sortedFiles.size() != 0) FileManager::printVectorOfFiles(sortedFiles);
			else {
				cout << "No files to sort";
				return;
			};

			bool isAgreed = promptUserForExport();

			if (isAgreed && sortedFiles.size() != 0) exportToFile(sortedFiles);
			else {
				cout << "No files to export";
				return;
			};
		}),

		// Get files above some size
		MenuOption(this->FILES_ABOVE_SIZE, "Get files above some size",  [&fileManager]() {
			int userSize = getIntUserInput("Input desired size: ");
			vector<File> newFiles = fileManager->getFilesAboveSize(userSize);

			if (newFiles.empty()) {
				cout << "No files found\n";
				return;
			}

			cout << "Files above " << userSize << " size" << endl;
			FileManager::printVectorOfFiles(newFiles);

			bool isAgreed = promptUserForExport();

			if (isAgreed) exportToFile(newFiles);

		}),

		// Get files above some usage
		MenuOption(this->FILES_ABOVE_USAGE, "Get files above some usage",  [&fileManager]() {
			int userUsage = getIntUserInput("Input desired usage:");
			vector<File> newFiles = fileManager->getFilesAboveUsage(userUsage);

			if (newFiles.empty()) {
				cout << "No files found\n";
				return;
			}

			cout << "Files above " << userUsage << " usage" << endl;
			FileManager::printVectorOfFiles(newFiles);

			bool isAgreed = promptUserForExport();

			if (isAgreed) exportToFile(newFiles);
		}),

		// Run tests
		MenuOption(this->RUN_TESTS , "Run tests",  []() { runTests(); }),

		// Read from file
		MenuOption(this->READ_FROM_FILE, "Read from file",  [&fileManager]() {
			string filename = "resources/demoFiles.csv";
			vector<File> filesFromFile = getFilesFromFile(filename);

			if (filesFromFile.empty()) {
				cerr << "Error reading files from file." << endl;
			}
			else {
				fileManager->setFiles(filesFromFile);

				cout << "Successfull read from file!" << endl;
			}
		}),

		// Exit
		MenuOption(this->EXIT, "Exit",  []() { exit(EXIT_SUCCESS); })
	};

	this->options = items;
};

void Menu::display() {
	std::cout << "\n";

	for (MenuOption item : this->options) {
		item.print();
	}
}

void Menu::choose(int index) {
	this->options[index - 1].callAction();
}

void Menu::printWelcomeMessage() {
	cout << "Fomin Mikhail Vital\'evich, 4307, 25" << endl;
	cout << "1, 11, Develop a class for the specified subject area. Implement data access using the Set, Get, Show. Provide for necessary checks of source data." << endl << endl;

	cout << "File: file name, size, creation date, number of hits." << endl << "Create an array of objects.Realize the possibility of receiving:" << endl;
	cout << "\t- a list of files arranged in alphabetical order" << endl << "\t- a list of files whose size exceeds the specified one" << endl;
	cout << "\t- a list of files the number of accesses to which exceeds the specified number" << endl << endl;
};

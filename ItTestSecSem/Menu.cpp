#include <iostream>
#include <vector>

#include "inputs.h"
#include "testMain.h"
#include "files.h"
#include "Menu.h"
#include "MenuOption.h"

void Menu::initializeMenu(unique_ptr<FileManager>& fileManager) {
	vector<MenuOption> items = {
		// Print files
		MenuOption(this->PRINT_FILES, "Print files",  [&fileManager]() {
			fileManager->printFiles();
		}),

		// Sort files
		MenuOption(Menu::optionsIds::SORT_FILES, "Get alphabetically sorted files",  [&fileManager]() {
			vector<File> sortedFiles = fileManager->getSortedFiles();

			FileManager::printVectorOfFiles(sortedFiles);
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
		}),

		// Run tests
		MenuOption(this->RUN_TESTS , "Run tests",  []() { runTests(); }),

		// Read from file
		MenuOption(this->READ_FROM_FILE, "Read from file",  []() {
			string filename = "resources/demoFiles.csv";
			vector<File> files = getFilesFromFile(filename);

			if (files.empty()) {
				cerr << "Error reading files from file." << endl;
			}

			cout << "Files:\n";
			for (File& gigaFile : files) {
				gigaFile.printFile();
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
	if (index >= 1 && index <= this->options.size()) {
		this->options[index - 1].callAction();
	}
	else {
		std::cout << "Invalid choice.\n";
	}
}

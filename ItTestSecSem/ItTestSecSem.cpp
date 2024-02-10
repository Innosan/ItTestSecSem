#include <iostream>
#include <string>

#include "testMain.h"
#include "FileManager.h"
#include "MenuOption.h"
#include "Menu.h"
#include "WelcomeMessage.h"

#include "inputs.h"

using namespace std;

int main()
{
	WelcomeMessage::printWelcomeMessage(
		Student("Fomin Mikhail Vital\'evich", 4307, 25),
		Task(
			1,
			11,
			"Develop a class for the specified subject area. Implement data access using the Set, Get, Show. Provide for necessary checks of source data."
		)
	);

	// Initialize the file manager
	std::unique_ptr<FileManager> fileManager = std::make_unique<FileManager>();
	fileManager->initializeFiles();

	// Initialize the menu options
	vector<MenuOption> items = {
		MenuOption(1, "Print files",  [&fileManager]() {
			fileManager->printFiles();
		}),
		MenuOption(2, "Get alphabetically sorted files",  [&fileManager]() {
			vector<File> sortedFiles = fileManager->getSortedFiles();

			FileManager::printVectorOfFiles(sortedFiles);
		}),
		MenuOption(3, "Get files above some size",  [&fileManager]() {
			int userSize = getIntUserInput("Input desired size: ");
			vector<File> newFiles = fileManager->getFilesAboveSize(userSize);

			if (newFiles.empty()) {
				cout << "No files found\n";
				return;
			}

			cout << "Files above " << userSize << " size" << endl;
			FileManager::printVectorOfFiles(newFiles);
		}),
		MenuOption(4, "Get files above some usage",  [&fileManager]() {
			int userUsage = getIntUserInput("Input desired usage:");
			vector<File> newFiles = fileManager->getFilesAboveUsage(userUsage);

			if (newFiles.empty()) {
				cout << "No files found\n";
				return;
			}

			cout << "Files above " << userUsage << " usage" << endl;
			FileManager::printVectorOfFiles(newFiles);
		}),
		MenuOption(5, "Run tests",  []() { runTests(); }),
		MenuOption(6, "Exit",  []() { exit(EXIT_SUCCESS); })
	};

	// Initialize the menu
	Menu menu(items);

	int pickedItem = 0;

	do {
		// Display the menu
		menu.display();

		pickedItem = getIntUserInput("Choose an option: ");

		menu.choose(pickedItem);
	} while (pickedItem != 6);

	return EXIT_SUCCESS;
}
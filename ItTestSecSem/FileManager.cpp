#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "FileManager.h"
#include "File.h"

void FileManager::printFiles() {
	cout << endl;

	for (File file : this->files)
	{
		file.printFile();
	}

	cout << "\nTotal files: " << this->files.size() << "\n\n";
}

void FileManager::addFile(const File& file) {
	this->files.push_back(file);

	cout << "File added!\n";
}

vector<File> FileManager::getSortedFiles() {
	vector<File> sortedFiles = this->files;

	for (size_t i = 0; i < sortedFiles.size(); i++) {
		for (size_t j = 0; j < sortedFiles.size() - i - 1; j++) {
			// Compare file titles
			if (sortedFiles[j].getTitle() > sortedFiles[j + 1].getTitle()) {
				// Swap files
				File temp = sortedFiles[j];
				sortedFiles[j] = sortedFiles[j + 1];
				sortedFiles[j + 1] = temp;
			}
		}
	}

	return sortedFiles;
}

vector<File> FileManager::getFilesAboveSize(int size) {
	vector<File> newFiles;

	for (File file : this->files)
	{
		if (file.getSize() > size) newFiles.push_back(file);
	}

	return newFiles;
}

vector<File> FileManager::getFilesAboveUsage(int usage) {
	vector<File> newFiles;

	for (File file : this->files)
	{
		if (file.getUsage() > usage) newFiles.push_back(file);
	}

	return newFiles;
}

void FileManager::printVectorOfFiles(vector<File> vectorFiles) {
	cout << "\n";

	for (File file : vectorFiles)
	{
		file.printFile();
	}

	cout << "\n\n";
};

void FileManager::setFiles(const vector<File>& newFiles) {
	this->files.clear();

	this->files = newFiles;
}

vector<File> FileManager::getFiles() {
	return this->files;
};

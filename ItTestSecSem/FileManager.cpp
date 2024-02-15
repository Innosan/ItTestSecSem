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

	sort(sortedFiles.begin(), sortedFiles.end(), [](File& a, File& b) {
		for (size_t i = 0; i < std::min(a.getTitle().size(), b.getTitle().size()); ++i) {
			// Compare characters, treating whitespaces as equal
			if (a.getTitle()[i] != b.getTitle()[i]) {
				return a.getTitle()[i] < b.getTitle()[i];
			}
		}

		// Titles are equal up to this point, use length for additional sorting
		return a.getTitle().size() < b.getTitle().size();
		});

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

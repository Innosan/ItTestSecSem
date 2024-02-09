#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "FileManager.h"
#include "File.h"

using namespace std;

void FileManager::printFiles() {
	cout << "\n";

	for (File file : this->files)
	{
		file.printFile();
	}

	cout << "\nTotal files: " << this->files.size() << "\n\n";
}
void FileManager::addFile(const File& file) {
	this->files.push_back(file);

	//cout << "File added!\n";
}

vector<File> FileManager::getSortedFiles() {
	vector<File> sortedFiles = this->files;

	sort(sortedFiles.begin(), sortedFiles.end(), [](File& a, File& b) {
		return a.getTitle() < b.getTitle();
		}
	);

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

void FileManager::initializeFiles() {
	for (auto i = 0; i < 5; i++)
	{
		auto fileId = i + 1;

		File file(
			fileId,
			to_string(fileId) + "File",
			"Created " + to_string(fileId) + " of February",
			512 + fileId * 12,
			fileId * 4
		);

		this->addFile(file);
	}

	File file(
		20,
		"0File",
		"Created 4 of February",
		512 * 12,
		4 * 4
	);

	this->addFile(file);
}

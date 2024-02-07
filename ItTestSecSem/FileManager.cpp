#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "FileManager.h"
#include "File.h"

using namespace std;

void FileManager::printFiles() {
	for (File file : this->files)
	{
		file.printFile();
	}
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
	vector<File> files;

	for (File file : this->files)
	{
		if (file.getSize() > size) files.push_back(file);
	}

	return files;
}

vector<File> FileManager::getFilesAboveUsage(int usage) {
	vector<File> files;

	for (File file : this->files)
	{
		if (file.getUsage() > usage) files.push_back(file);
	}

	return files;
}

void FileManager::printVectorOfFiles(vector<File> vectorFiles) {
	for (File file : vectorFiles)
	{
		file.printFile();
	}
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

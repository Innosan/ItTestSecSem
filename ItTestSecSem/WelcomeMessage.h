#pragma once

#include <iostream>

class Student
{
public:
	std::string name;

	int groupNumber;
	int studentNumber;

	Student(std::string name, int groupNumber, int studentNumber) :
		name(name), groupNumber(groupNumber), studentNumber(studentNumber) {}
};

class Task
{
public:
	int number;
	int testNumber;

	std::string description;

	Task(int number, int testNumber, std::string description) :
		number(number), testNumber(testNumber), description(description) {}
};

class WelcomeMessage
{
public:
	static void printWelcomeMessage(Student student, Task task);
};

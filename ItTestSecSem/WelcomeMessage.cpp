#include <iostream>
#include "WelcomeMessage.h"

void WelcomeMessage::printWelcomeMessage(Student student, Task task) {
	std::cout << student.name << ", group " << student.groupNumber << ", number " << student.studentNumber << "\n\n";
	std::cout << "Task " << task.number << "\n" << task.description << std::endl;

	std::cout << std::endl;
};

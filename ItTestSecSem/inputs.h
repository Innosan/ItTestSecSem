#pragma once
#include <iostream>

/**
 * \brief Get int user intput.
 *
 * \param welcomeMessage - message to display to the user
 * \param min - minimum value
 * \param max - maximum value
 *
 * \return int user input
 */
int getIntUserInput(std::string welcomeMessage, int min = 0, int max = INT_MAX);

/**
 * \brief Get string user input.
 *
 * \param welcomeMessage - message to display to the user
 *
 * \return string user input
 */
std::string getStringUserInput(std::string welcomeMessage);

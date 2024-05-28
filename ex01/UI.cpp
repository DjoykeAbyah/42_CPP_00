/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   UI.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 20:18:03 by dreijans      #+#    #+#                 */
/*   Updated: 2024/05/28 20:34:39 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "UI.hpp"

const char* const UI::BOLD_TEXT = "\033[1m";
const char* const UI::RESET = "\033[0m";
const char* const UI::BLUE = "\033[34m";
const char* const UI::CYAN = "\033[36m";
const char* const UI::GREEN = "\033[32m";
const char* const UI::MAGENTA = "\033[35m";
const char* const UI::RED = "\033[31m";
const char* const UI::WHITE = "\033[37m";
const char* const UI::YELLOW = "\033[33m";

void UI::menuOptions() 
{
    std::cout << "\t\t\t\t\t\tEnter ADD, SEARCH, DELETE or EXIT in capital letters: " << RESET;
}

void UI::showChoice(const std::string& input) 
{
    std::cout << "\n\t\t\t\t\t\t\t\tyou chose: [" << BOLD_TEXT << MAGENTA << input << RESET << "]\n\n";
}

void UI::numericOptions() 
{
    std::cout << " Please choose a number between 1 - 8: ";
}

void UI::isEmpty() 
{
    std::cout << BLUE << "\nPhoneBook is empty\n\n" << RESET;
}

void UI::introduceOptions() 
{
    std::cout << RED << "\nPlease enter a number between 1 and 8.\n\n" << RESET;
}

void UI::showPrompt() 
{
    std::cout << BOLD_TEXT;
    std::cout << CYAN << "Welcome to my Phonebook let's go 80's!!\n";
    std::cout << CYAN << "This high-end piece of technology has an ADD, SEARCH, EXIT, and even a DELETE option!\n\n";
    std::cout << RESET;
}

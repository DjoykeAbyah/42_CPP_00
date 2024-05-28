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

void UI::tryAgain()
{
    std::cout << UI::RED << "Field cannot be empty. Try again" << UI::RESET << std::endl;

}

void UI::invalidInput()
{
    std::cout << UI::RED << "Invalid input. Try again" << UI::RESET << std::endl;
}

void UI::deletionSuccess(const std::string& input)
{
    std::cout << UI::GREEN << "\nYou've successfully deleted entry nr." << input << "\n\n\n" << UI::RESET << std::endl;

}

void UI::additionSuccess()
{
    std::cout << UI::GREEN << "you've successfully added a new contact!\n\n\n" << UI::RESET <<std::endl;
}

void UI::overwriteWarning()
{
    std::cout << UI::BOLD_TEXT << "\nyou're about to overwrite your oldest contact, are you sure?" << UI::RESET <<std::endl;
}

void UI::showPrompt() 
{
    std::cout << BOLD_TEXT;
    std::cout << CYAN << "Welcome to my Phonebook let's go 80's!!\n";
    std::cout << CYAN << "This high-end piece of technology has an ADD, SEARCH, EXIT, and even a DELETE option!\n\n";
    std::cout << RESET;
}

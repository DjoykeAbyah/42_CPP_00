/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:05:06 by dreijans      #+#    #+#                 */
/*   Updated: 2024/05/26 16:13:09 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Utils.hpp"
#include <cstring>

/**
 * declare enum struct
 */
enum UserChoice
{
	ADD,
	SEARCH,
	DELETE,
	EXIT,
	INVALID
};

/**
 * links enum to input
 */
UserChoice getChoice(const std::string& input) 
{
    if (input == "ADD") 
		return ADD;
    if (input == "SEARCH") 
		return SEARCH;
    if (input == "DELETE") 
		return DELETE;
    if (input == "EXIT") 
		return EXIT;
    return INVALID;
}

/**
 * displays prompt at start of program
 */
void prompt()
{
  std::cout << BOLD_TEXT;
	std::cout << CYAN "Welcome to my Phonebook let's go 80's!!\n";
	std::cout << CYAN "this high end piece of technology has an ADD, SEARCH, EXIT, and even a DELETE option!\n\n\n\n\n";
  std::cout << RESET;
}

/**
 * protects getline
 */
bool safeGetLine(std::string& input) 
{
    if (!std::getline(std::cin, input, '\n'))
    {
        if (std::cin.eof())
        {
            std::cout << RED "EOF encountered. Exiting program.\n" << RESET << std::endl;
            return false;
        }
        else
        {
            std::cout << RED "Error reading input. Exiting program.\n" << RESET << std::endl;
            std::cin.clear();  // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
    }
    return true;
}

/**
 * main method
 */
int main() 
{
	PhoneBook phoneBook;
  std::string input;
    
  prompt();
  while (true) 
  {
    std::cout << "            Enter ADD, SEARCH, DELETE or EXIT in capital letters: " << RESET;
    if (!safeGetLine(input))
      return 0;
    std::cout << "\n                           you chose: [" BOLD_TEXT MAGENTA << input <<  RESET "]\n\n\n\n\n" << std::endl;
    switch (getChoice(input)) 
    {
      case ADD: 
      {
          phoneBook.addContact();
          break;
      }
      case SEARCH: 
      {
          phoneBook.searchContact();
          break;
      }
      case DELETE: 
      {
          phoneBook.deleteContact();
          break;
      }
      case EXIT: 
      {
          std::cout << BOLD_TEXT "bye now!\n" << RESET << std::endl;
          return 0;
      }
      case INVALID:
      {
          std::cout << RED "Option doesn't exist\n" << RESET << std::endl;
          break;
      }
    }
  }
  return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:05:06 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/31 16:04:33 by dreijans      ########   odam.nl         */
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
	std::cout << "Welcome to my Phonebook let's go 80's!!\n";
	std::cout << "to use this phonebook choose between the following options:\n";
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
            std::cout << "EOF encountered. Exiting program.\n";
            return false;
        }
        else
        {
            std::cout << "Error reading input. Exiting program.\n";
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
    std::cout << "enter ADD, SEARCH, DELETE or EXIT in capital letters" << '\n';
    if (!safeGetLine(input))
      return 0;
    std::cout << "you chose " << input << std::endl;
    switch (getChoice(input)) 
    {
      case ADD: 
      {
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          phoneBook.addContact();
          break;
      }
      case SEARCH: 
      {
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          phoneBook.searchContact();
          break;
      }
      case DELETE: 
      {
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          phoneBook.deleteContact();
          break;
      }
      case EXIT: 
      {
          std::cout << "bye now!\n";
          return 0;
      }
      case INVALID:
      {
          std::cout << "Option doesn't exist\n";
          break;
      }
    }
  }
  return 0;
}

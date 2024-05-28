/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:05:06 by dreijans      #+#    #+#                 */
/*   Updated: 2024/05/28 20:43:07 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Utils.hpp"
#include "UI.hpp"
#include <cstring>

/**
 * protects getline
 */
bool safeGetLine(std::string& input) 
{
    if (!std::getline(std::cin, input, '\n'))
    {
        if (std::cin.eof())
        {
            std::cout << UI::RED << "EOF encountered. Exiting program.\n" << UI::RESET << std::endl;
            return false;
        }
        else
        {
            std::cout << UI::RED << "Error reading input. Exiting program.\n" << UI::RESET << std::endl;
            std::cin.clear();
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
    
 UI::showPrompt();
  while (true) 
  {
    UI::menuOptions();
    if (!safeGetLine(input))
      return 0;

    // SHOW_CHOICE(input);
    UI::showChoice(input);
    UserChoice choice = getChoice(input);
    switch (choice) 
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
          std::cout << UI::BOLD_TEXT << "bye now!\n" << UI::RESET << std::endl;
          return 0;
      }
      case INVALID:
      {
          std::cout << UI::RED << "Option doesn't exist\n" << UI::RESET << std::endl;
          break;
      }
    }
  }
  return 0;
}

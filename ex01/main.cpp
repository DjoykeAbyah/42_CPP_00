/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:05:06 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/29 17:42:56 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
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
        std::cin >> input;
        std::cout << "you chose " << input << '\n';
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
                std::cout << "you chose EXIT, bye now!\n";
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:05:06 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/29 15:29:57 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstring>

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
 * @todo 
 * 1. delete unnecessary comments above functions, look for best practice in commenting methods
 */
int main()
{
	PhoneBook phoneBook;
	std::string input;
	prompt();
	while (input != "EXIT")
	{
		std::cout << "enter ADD, SEARCH, DELETE or EXIT in capital letters" << '\n';
		std::cin >> input;
		std::cout << "you chose " << input << '\n';
		if (input == "ADD")
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			int currentIndex = 0;
			phoneBook.addContact();
			currentIndex = phoneBook.getContactIndex();// Retrieve the current index
        	std::cout << "Contact added at index: " << currentIndex << '\n';
		}
		else if (input == "SEARCH")
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			phoneBook.searchContact();
		}
		else if (input == "DELETE")
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
			phoneBook.deleteContact();
		}
		else
			std::cout << "option doesn't exist" << '\n';
	}
	if (input == "EXIT")
	{
		std::cout << "you chose EXIT, bye now!\n";
		exit(0);
	}
	return 0;
}

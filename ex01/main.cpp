/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:05:06 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/28 22:01:19 by djoyke        ########   odam.nl         */
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
 * @todo 
 * 1. how to do this in a more c++ way
 * 2. delete unnecessary comments above functions, look for best practice in commenting methods
 * 
 * @note 
 * lenght returns an unsigned integral value 
 * so if you want to assign to int you should static_cast<int>
 * name.lenght() because lenght is a member function
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
			int currentIndex = 0;
			phoneBook.addContact();
			currentIndex = phoneBook.getContactIndex(); // Retrieve the current index
        	std::cout << "Contact added at index: " << currentIndex << '\n';
		}
		else if (input == "SEARCH")
			phoneBook.searchContact();
		else if (input == "DELETE")
			phoneBook.deleteContact();
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

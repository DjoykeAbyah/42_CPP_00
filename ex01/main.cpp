/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:05:06 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/18 17:03:38 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstring>

void prompt()
{
	std::cout << "Welcome to my Phonebook let's go 80's!!\n";
	std::cout << "to use this phonebook choose between the following options";
	std::cout << "enter ADD, SEARCH or EXIT" << '\n';
}

int main()
{
	PhoneBook phoneBook;
	//phonebook is empty
	//prompt user to enter 3 commands
	//ADD, SEARCH, EXIT
	//ADD save a new contact
	//saved contact cant have empty fields
	std::string input;
	prompt();

	while (1)
	{
		//loop doesnt stop fix that
		std::cout << "enter ADD, SEARCH or EXIT" << '\n';
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
		{
			phoneBook.searchContact();
		}
		else if (input == "EXIT")
		{
			exit(0);
		}
		else
			return 0;
	}
	return 0;
}
//use std::getline(std::cin >> std std::ws, name); //use this for darkest secret
//std::ws manipulator ignores leading whitespaces
//name.lenght() because lenght is a member function
//lenght returns an unsigned integral value so if you want to assign to int you should static_cast<int>
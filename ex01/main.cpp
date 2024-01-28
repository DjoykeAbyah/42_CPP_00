/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:05:06 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/28 16:32:31 by djoyke        ########   odam.nl         */
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
 * 1. what to do when phonebook is empty and someoe types SEARCH
 * 2. what to do when someone wants to see index that is empty
 * 3. make sure phonebook is empty at start
 * 4. give correct messages at exit etc
 * 5. delete unnecessary comments above functions, look for best practice in commenting methods
 * 6. make sure ADD SEARCH DELETE are in capital letters, throw error message if not
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
		std::cout << "enter ADD, SEARCH, DELETE or EXIT" << '\n';
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
		exit(0);
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:05:06 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/18 20:36:44 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstring>

/**
 * @brief displays prompt at start of program
 */
void prompt()
{
	std::cout << "Welcome to my Phonebook let's go 80's!!\n";
	std::cout << "to use this phonebook choose between the following options";
	std::cout << "enter ADD, SEARCH or EXIT" << '\n';
}

/**
 * @todo 
 * 1. what to do when phonebook is empty and someoe types SEARCH
 * 2. display phonebook
 * 3. input check for contact elememts
 * 4. incorrect phonebook commands (other than ADD, SEARCH, EXIT, DELETE)
 * 5. Delete method
 * 6. make sure contact cant have empty fields
 * 7. make sure phonebook is empty at start
 * 8. give correct messages at exit etc
 * 
 * lenght returns an unsigned integral value 
 * so if you want to assign to int you should static_cast<int>
 * name.lenght() because lenght is a member function
 */
int main()
{
	PhoneBook phoneBook;
	std::string input;
	prompt();

	while (1)
	{
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

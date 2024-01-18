/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:05:06 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/18 15:48:15 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstring>
// #include <cctype>

int main()
{
	PhoneBook phoneBook;
	//phonebook is empty
	//prompt user to enter 3 commands
	//ADD, SEARCH, EXIT
	//ADD save a new contact
	//saved contact cant have empty fields
	std::string input;
	std::cout << "Welcome to my Phonebook let's go 80's!!\n";
	std::cout << "to use this phonebook choose between the following options";
	std::cout << "enter ADD, SEARCH or EXIT" << '\n';
	std::cin >> input;
	std::cout << "you chose " << input << '\n';

	if (input == "ADD")
	{
		phoneBook.addContact();
	}
	phoneBook.printPhoneBook();
}
//use std::getline(std::cin >> std std::ws, name); //use this for darkest secret
//std::ws manipulator ignores leading whitespaces
//name.lenght() because lenght is a member function
//lenght returns an unsigned integral value so if you want to assign to int you should static_cast<int>
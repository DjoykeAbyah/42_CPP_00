/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:05:06 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/17 21:55:37 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(int argc, char **argv)
{
	//phonebook is empty
	//prompt user to enter 3 commands
	//ADD, SEARCH, EXIT
	std::string input;

	//ADD save a new contact
	//saved contact cant have empty fields
	std::cout << "enter ADD, SEARCH or EXIT" << '\n';
	std::cin >> input;
	std::cout << input << '\n';
	
	return (0);
}
//std::string name;
//use std::getline(std::cin >> std std::ws, name);
//std::ws manipulator ignores leading whitespaces
//name.lenght() because lenght is a member function
//lenght returns an unsigned integral value so if you want to assign to int you should static_cast<int>
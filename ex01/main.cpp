/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:05:06 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/17 17:11:04 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	//phonebook is empty
	//prompt user to enter 3 commands
	//ADD, SEARCH, EXIT
	std::string input;

	//ADD save a new contact
		//if user enters this command, prompted to input info of the new contact
		//one field at a time
		//1. first name
		//2. last name
		//3. nickname
		//4. phone number
		//5. darkest secret
		//saved contact cant have empty fields
	std::cout << "enter ADD, SEARCH or EXIT" << '\n';
	std::cin >> input;
	std::cout << input << '\n-';
	return (0);
}
//std::string name;
//use std::getline(std::cin >> std std::ws, name);
//std::ws manipulator ignores leading whitespaces
//name.lenght() because lenght is a member function
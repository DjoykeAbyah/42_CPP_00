/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:05:06 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/18 14:52:52 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	//phonebook is empty
	//prompt user to enter 3 commands
	//ADD, SEARCH, EXIT
	// std::string input;

	//ADD save a new contact
	//saved contact cant have empty fields
	// std::cout << "enter ADD, SEARCH or EXIT" << '\n';
	// std::cin >> input;
	// std::cout << input << '\n';

	Contact contact;
	contact.setFirstName();
	contact.setLastName();
	contact.setNickName();
	contact.setPhoneNumber();
	contact.setDarkestSecret();

	// You can now use the getters to retrieve the entered information
    std::cout << "Contact information:\n"
              << "First Name: " << contact.getFirstName() << "\n"
              << "Last Name: " << contact.getLastName() << "\n"
              << "Nickname: " << contact.getNickName() << "\n"
              << "Phone Number: " << contact.getPhoneNumber() << "\n"
              << "Darkest Secret: " << contact.getDarkestSecret() << "\n";
	return (0);
}
//use std::getline(std::cin >> std std::ws, name); //use this for darkest secret
//std::ws manipulator ignores leading whitespaces
//name.lenght() because lenght is a member function
//lenght returns an unsigned integral value so if you want to assign to int you should static_cast<int>
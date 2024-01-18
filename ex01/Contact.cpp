/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 21:15:51 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/18 14:47:37 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){};

Contact::~Contact(){};

void Contact::setFirstName()
{
	std::cout << "Enter first name: ";
	std::cin >> firstName;
}

void Contact::setLastName()
{
	std::cout << "Enter last name: ";
	std::cin >> lastName;
}

void Contact::setNickName()
{
	std::cout << "Enter nick name: ";
	std::cin >> nickName;
}

void Contact::setPhoneNumber()
{
	std::cout << "Enter phone number: ";
	std::cin >> phoneNumber;
}

void Contact::setDarkestSecret()
{
	std::cout << "Enter darkest secret: ";
	// Ignore any previous newline character in the input buffer
    std::cin.ignore();
    std::getline(std::cin, darkestSecret);
}

std::string Contact::getFirstName()
{
	return firstName;
}

std::string Contact::getLastName()
{
	return lastName;
}

std::string Contact::getNickName()
{
	return nickName;
}

std::string Contact::getPhoneNumber()
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return darkestSecret;
}
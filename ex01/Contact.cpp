/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 21:15:51 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/19 21:28:32 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){};

Contact::~Contact(){};

/**
 * @todo do input checks on the setters
*/
void Contact::setFirstName()
{
	std::cout << "Enter first name: ";
	std::cin >> firstName;
	// if (firstName == NULL)
	// 	std::cout << "Field cannot be empty";
	//prompt user again for input
}

/**
 * @todo do input checks on the setters
*/
void Contact::setLastName()
{
	std::cout << "Enter last name: ";
	std::cin >> lastName;
}

/**
 * @todo do input checks on the setters
*/
void Contact::setNickName()
{
	std::cout << "Enter nick name: ";
	std::cin >> nickName;
}

/**
 * @todo do input checks on the setters
*/
void Contact::setPhoneNumber()
{
	std::cout << "Enter phone number: ";
	std::cin >> phoneNumber;
}

/**
 * @todo do input checks on the setters
*/
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
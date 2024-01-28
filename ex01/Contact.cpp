/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 21:15:51 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/28 16:28:35 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){};

Contact::~Contact(){};

bool Contact::isAlphabetic(const std::string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (!isalpha(str[i]))
			return false;
	}
	return true;
}

void Contact::nameCheck(std::string& input, const std::string& prompt)
{
    bool isValidInput = false;

    while (!isValidInput)
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << prompt;
		std::cin >> input;
		std::cout << std::endl;
        if (input.empty())
            std::cout << "Field cannot be empty. Press Enter to try again" << std::endl;
        else if (!isAlphabetic(input))
            std::cout << "Invalid input. Press Enter to try again" << std::endl;
        else
            isValidInput = true;
    }
}

bool Contact::digitCheck(std::string& input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}

void Contact::phoneNumberCheck()
{
	bool isValidInput = false;
	while (!isValidInput) 
	{
		std::cout << "Enter phone number: ";
		std::cin >> phoneNumber;
		std::cout << std::endl;
		if (digitCheck(phoneNumber))
			isValidInput = true;
		else 
		{
			std::cerr << "Invalid input. Please give a valid phone number." << std::endl;
			// Clear the input buffer to handle invalid input
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}


void Contact::resetContact() 
{
    firstName.clear();
    lastName.clear();
    nickName.clear();
    phoneNumber.clear();
    darkestSecret.clear();
}

void Contact::setFirstName()
{
	nameCheck(firstName, "Enter first name in alphabetic characters: ");
}

void Contact::setLastName()
{
	nameCheck(lastName, "Enter last name in alphabetic characters: ");
}

void Contact::setNickName()
{
	nameCheck(nickName, "Enter nickname in alphabetic characters: ");
}

void Contact::setPhoneNumber()
{
	phoneNumberCheck();
}

void Contact::setDarkestSecret()
{
	std::cout << "Enter darkest secret: ";
    std::cin.ignore(); 	// Ignore any previous newline character in the input buffer
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
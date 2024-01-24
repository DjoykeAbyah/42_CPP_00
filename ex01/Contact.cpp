/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 21:15:51 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/24 21:47:06 by djoyke        ########   odam.nl         */
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

/**
 * get rid of the double enter after giving input
 */
void Contact::nameCheck(std::string& input, const std::string& prompt)
{
	do
    {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << "Field cannot be empty. press Enter to try again\n";
            continue;  // Skip the remaining checks and prompt again
        }
        if (!isAlphabetic(input))
		{
            std::cout << "Invalid input. Press enter to try again\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
    } while (input.empty() || !isAlphabetic(input));
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
	nameCheck(lastName, "Enter nickname in alphabetic characters: ");
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
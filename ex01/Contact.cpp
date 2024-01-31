/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 21:15:51 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/31 15:45:07 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Utils.hpp"

Contact::Contact(){};

Contact::~Contact(){};

/**
 * checks if input is alphabetic
*/
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
 * checks if input is valid by checking if it's empty or alphabetic
*/
void Contact::nameCheck(std::string& input, const std::string& prompt)
{
    bool isValidInput = false;

    while (!isValidInput)
    {
        std::cout << prompt;
        if (!safeGetLine(input))
            break ;
		std::cout << std::endl;
        if (input.empty())
            std::cout << "Field cannot be empty. Press Enter to try again" << std::endl;
        else if (!isAlphabetic(input))
            std::cout << "Invalid input. Press Enter to try again" << std::endl;
        else
            isValidInput = true;
    }
}

/**
 * checks if input is numeric
*/
bool Contact::digitCheck(std::string& input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}

/**
 * checks if input is alphabetic
*/
void Contact::phoneNumberCheck()
{
	bool isValidInput = false;

    while (!isValidInput)
    {
        std::cout << "Enter phone number: ";
        if (!safeGetLine(phoneNumber))
            break ;
		std::cout << std::endl;
        if (phoneNumber.empty())
            std::cout << "Field cannot be empty. Press Enter to try again" << std::endl;
        else if (!digitCheck(phoneNumber))
            std::cout << "Invalid input. Press Enter to try again" << std::endl;
        else
            isValidInput = true;
    }
}

/**
 * resets field to empty
*/
void Contact::resetContact() 
{
    firstName.clear();
    lastName.clear();
    nickName.clear();
    phoneNumber.clear();
    darkestSecret.clear();
}

/**
 * firstname setter, uses nameCheck
*/
void Contact::setFirstName()
{
	nameCheck(firstName, "Enter first name in alphabetic characters: ");
}

/**
 * lastname setter, uses nameCheck
*/
void Contact::setLastName()
{
	nameCheck(lastName, "Enter last name in alphabetic characters: ");
}

/**
 * nickname setter, uses nameCheck
*/
void Contact::setNickName()
{
	nameCheck(nickName, "Enter nickname in alphabetic characters: ");
}

/**
 * phonenumber setter, uses phoneNumberCheck
*/
void Contact::setPhoneNumber()
{
	phoneNumberCheck();
}

/**
 * darkest secret setter
*/
void Contact::setDarkestSecret()
{
	bool isValidInput = false;

    while (!isValidInput)
    {
        std::cout << "Enter darkest secret: ";
        if (!safeGetLine(darkestSecret))
            break ;
		std::cout << std::endl;
        if (darkestSecret.empty())
            std::cout << "Field cannot be empty. Press Enter to try again" << std::endl;
        else
            isValidInput = true;
    }
}

/**
 * gets firstname
*/
std::string Contact::getFirstName()
{
	return firstName;
}

/**
 * gets lastname
*/
std::string Contact::getLastName()
{
	return lastName;
}

/**
 * gets nickname
*/
std::string Contact::getNickName()
{
	return nickName;
}

/**
 * gets phone number
*/
std::string Contact::getPhoneNumber()
{
	return phoneNumber;
}

/**
 * gets darkest secret
*/
std::string Contact::getDarkestSecret()
{
	return darkestSecret;
}
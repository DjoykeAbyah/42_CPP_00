/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 21:15:51 by dreijans      #+#    #+#                 */
/*   Updated: 2024/05/28 20:43:07 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Utils.hpp"
#include "UI.hpp"

Contact::Contact(){};

Contact::~Contact(){};

/**
 * firstname setter, uses nameCheck
*/
void Contact::setFirstName()
{
	nameCheck(_firstName, "Enter first name in alphabetic characters: ");
}

/**
 * lastname setter, uses nameCheck
*/
void Contact::setLastName()
{
	nameCheck(_lastName, "Enter last name in alphabetic characters: ");
}

/**
 * nickname setter, uses nameCheck
*/
void Contact::setNickName()
{
	nameCheck(_nickName, "Enter nickname in alphabetic characters: ");
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
        if (!safeGetLine(_darkestSecret))
            break ;
		std::cout << std::endl;
        if (_darkestSecret.empty())
            std::cout << UI::RED << "Field cannot be empty. Press Enter to try again" << UI::RESET << std::endl;
        else
            isValidInput = true;
    }
}

/**
 * gets firstname
*/
std::string Contact::getFirstName()
{
	return _firstName;
}

/**
 * gets lastname
*/
std::string Contact::getLastName()
{
	return _lastName;
}

/**
 * gets nickname
*/
std::string Contact::getNickName()
{
	return _nickName;
}

/**
 * gets phone number
*/
std::string Contact::getPhoneNumber()
{
	return _phoneNumber;
}

/**
 * gets darkest secret
*/
std::string Contact::getDarkestSecret()
{
	return _darkestSecret;
}

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
        if (input.empty())
            std::cout << UI::RED << "Field cannot be empty. Press Enter to try again" << UI::RESET << std::endl;
        else if (!isAlphabetic(input))
            std::cout << UI::RED << "Invalid input. Press Enter to try again" << UI::RESET << std::endl;
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
        if (!safeGetLine(_phoneNumber))
            break ;
        if (_phoneNumber.empty())
            std::cout << UI::RED << "Field cannot be empty. Press Enter to try again" << UI::RESET << std::endl;
        else if (!digitCheck(_phoneNumber))
            std::cout<< UI::RED << "Invalid input. Press Enter to try again" << UI::RESET << std::endl;
        else
            isValidInput = true;
    }
}

/**
 * resets field to empty
*/
void Contact::resetContact() 
{
    _firstName.clear();
    _lastName.clear();
    _nickName.clear();
    _phoneNumber.clear();
    _darkestSecret.clear();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

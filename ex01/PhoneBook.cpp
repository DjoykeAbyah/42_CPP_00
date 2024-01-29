/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 21:01:05 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/29 13:41:30 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook():contactIndex(0){};

PhoneBook::~PhoneBook(){};

/**
 * checks if input is numeric
*/
bool PhoneBook::isNumeric(std::string& pageNum)
{
    for (int i = 0; i < pageNum.size(); i++)
    {
        if (i > 1)
            return false;
        if (!std::isdigit(pageNum[i]))
            return false;
        else
        {
            int number = std::stoi(pageNum);
            if (number < 0 && number > 9)
                return false;
        }
    }
    return true;
}

/**
 * Searches a contact based on the index number of the phonebook
 * @todo do I need to say the book is empty if it is?
 */ 
void PhoneBook::searchContact()
{
    std::string pageNum;

    printPhoneBook();
    std::cout << "\nWhich page do you want to see?\n\n";
    while (true)
    {
        std::cout << "\nPlease give a number 1 - 8\n\n";
        std::cin >> pageNum;
        if (isNumeric(pageNum))
        {
            int number = std::stoi(pageNum);
            if (number >= 1 && number <= 8)
            {
                if (contacts[number - 1].getFirstName().empty())
                {
                    std::cout << "\nEntry is empty\n\n";
                    break ;
                }
                printContact(number);
                break;
            }
            else
                std::cout << "\nPlease enter a number between 1 and 8.\n\n";
        }
    }
}

/**
 * Contact Index getter
 */
int PhoneBook::getContactIndex() const
{
    return contactIndex;
}

/**
 * adds contact and contact info to the array
 * @todo give warning before overwriting?
 */
void PhoneBook::addContact()
{
    if (contactIndex == 8)
        contactIndex = 0;
    contacts[contactIndex].setFirstName();
    contacts[contactIndex].setLastName();
    contacts[contactIndex].setNickName();
    contacts[contactIndex].setPhoneNumber();
    contacts[contactIndex].setDarkestSecret();
    contactIndex++;
}

/**
 * deletes contact and contact info on specific index of the array
 */
void PhoneBook::deleteContact()
{
    std::string pageNum;
    
    printPhoneBook();
    std::cout << "\nWhich contact do you want to delete?\n\n";
    while (true)
    {
        std::cout << "\nPlease give a number 1 - 8\n\n";
        std::cin >> pageNum;
        if (isNumeric(pageNum))
        {
            int number = std::stoi(pageNum);
            if (number >= 1 && number <= 8)
            {
                number -= 1;
                contacts[number].resetContact();
                std::cout << "\nYou've deleted entry nr." << pageNum << "\n\n";
                break;
            }
            else
                std::cout << "\nPlease enter a number between 1 and 8.\n\n";
        }
    }
}

/**
 * Truncates the text if it's longer than 10 characters 
 * and replace the last displayable character with a dot
*/
std::string PhoneBook::truncateInput(const std::string& input)
{
    const int columnWidth = 10;
    if (input.length() > columnWidth)
        return input.substr(0, columnWidth - 1) + ".";
    else
        return input;
}

/**
 * displays one contact
 */ 
void PhoneBook::printContact(int page)
{
    page -= 1;
    {
        std::cout << "\nContact information:\n\n"
              << "First Name: " << contacts[page].getFirstName() << "\n"
              << "Last Name: " << contacts[page].getLastName() << "\n"
              << "Nickname: " << contacts[page].getNickName() << "\n"
              << "Phone Number: " << contacts[page].getPhoneNumber() << "\n"
              << "Darkest Secret: " << contacts[page].getDarkestSecret() << "\n";
    }
}

/**
 * displays all entered contacts and truncates entries longer than with 10
 */ 
void PhoneBook::printPhoneBook()
{
   for (int index = 0; index < 8; index++)
    {
        std::cout << std::setw(10) << std::right << truncateInput(contacts[index].getFirstName()) << " | "
                  << std::setw(10) << std::right << truncateInput(contacts[index].getLastName()) << " | " 
                  << std::setw(10) << std::right << truncateInput(contacts[index].getPhoneNumber()) << " | "
                  << std::setw(10) << std::right << truncateInput(contacts[index].getDarkestSecret()) << std::endl;
    }
}

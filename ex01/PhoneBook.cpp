/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 21:01:05 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/19 20:02:20 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook():contactIndex(0){};

PhoneBook::~PhoneBook(){};

/**
 * @todo 
 * ◦ Each column must be 10 characters wide. A pipe character (’|’) separates
 * them. The text must be right-aligned. If the text is longer than the column,
 * it must be truncated and the last displayable character must be replaced by a
 * dot (’.’).
 */ 
void PhoneBook::searchContact()
{
    std::string pageNum;
    
    displayContacts();
    std::cout << "\nWhich page do you want to see?\nplease give a number 1 - 8\n\n";
    std::cin >> pageNum;
    if (pageNum.size() == 1)
    {
        int number = std::stoi(pageNum);
        if (number > 0 && number < 9)
            printContact(number);
        else
            std::cout << "\nPlease enter a numeric character from 1 till 8\n\n";
    }
    else
        std::cout << "\nPlease enter a numeric character from 1 till 8\n\n";
}

int PhoneBook::getContactIndex() const
{
    return contactIndex;
}

/**
 * @todo 
 * 1. parsing checks on correct input of each field need to do in method
 * 2. no empty fields are allowed, promt user again to fill in field
 */
void PhoneBook::addContact()
{
    if (contactIndex == 7)
        contactIndex = 0;
    contacts[contactIndex].setFirstName();
    contacts[contactIndex].setLastName();
    contacts[contactIndex].setNickName();
    contacts[contactIndex].setPhoneNumber();
    contacts[contactIndex].setDarkestSecret();
    contactIndex++;
}

/**
 * @todo 
 * 1. make the deleteContact function
 * 2. add parsing checks on user input
 */
void PhoneBook::deleteContact()
{
    //delete a contact based on number 1 - 8
    //which is array index 0 - 7
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
void PhoneBook::displayContacts()
{
   for (int index = 0; index < 8; index++)
    {
        std::cout << std::setw(10) << std::right << truncateInput(contacts[index].getFirstName()) << " | "
                  << std::setw(10) << std::right << truncateInput(contacts[index].getLastName()) << " | " 
                  << std::setw(10) << std::right << truncateInput(contacts[index].getPhoneNumber()) << " | "
                  << std::setw(10) << std::right << truncateInput(contacts[index].getDarkestSecret()) << std::endl;
    }
}


/**
 * @todo make the method
 */ 
void PhoneBook::printPhoneBook()
{
    
}

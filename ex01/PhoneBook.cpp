/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 21:01:05 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/18 17:02:53 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook():contactIndex(0){};

PhoneBook::~PhoneBook(){};

void PhoneBook::searchContact()
{
    //search for a contact based on number 1 - 8
    //which is array index 0 - 7
    std::string pageNum;
    
    std::cout << "Which page do you want to see?\n";
    std::cout << "please give a number 1 - 8\n";
    std::cin >> pageNum;
    int number = std::stoi(pageNum);
    printPhoneBook(number);
}

int PhoneBook::getContactIndex() const
{
    return contactIndex;
}

void PhoneBook::addContact()
{
    //if user tries to add 9th,
    //it will replace the first
    contacts[contactIndex].setFirstName();
    contacts[contactIndex].setLastName();
    contacts[contactIndex].setNickName();
    contacts[contactIndex].setPhoneNumber();
    contacts[contactIndex].setDarkestSecret();
    contactIndex++;
}

void PhoneBook::deleteContact()
{
    //delete a contact based on number 1 - 8
    //which is array index 0 - 7
}

void PhoneBook::printPhoneBook(int page)
{
    page -= 1;
    {
        std::cout << "Contact information:\n"
              << "First Name: " << contacts[page].getFirstName() << "\n"
              << "Last Name: " << contacts[page].getLastName() << "\n"
              << "Nickname: " << contacts[page].getNickName() << "\n"
              << "Phone Number: " << contacts[page].getPhoneNumber() << "\n"
              << "Darkest Secret: " << contacts[page].getDarkestSecret() << "\n";
    }
}

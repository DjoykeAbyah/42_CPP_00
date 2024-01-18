/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 21:01:05 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/18 15:50:30 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook():contactIndex(0){};

PhoneBook::~PhoneBook(){};

void PhoneBook::searchContact()
{
    //search for a contact based on number 1 - 8
    //which is array index 0 - 7
}

void PhoneBook::addContact()
{
    //if user tries to add 9th,
    //it will replace the first
    // dont loop but add on call 
    //and remember the index of last call
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

void PhoneBook::printPhoneBook()
{
    //only need to print number user gives as input
    // is number -1
    // for (int i = 0; i < 8; i++)
    {
        //need to check if it is empty at index.
        // if (contacts[i])
        std::cout << "Contact information:\n"
              << "First Name: " << contacts[i].getFirstName() << "\n"
              << "Last Name: " << contacts[i].getLastName() << "\n"
              << "Nickname: " << contacts[i].getNickName() << "\n"
              << "Phone Number: " << contacts[i].getPhoneNumber() << "\n"
              << "Darkest Secret: " << contacts[i].getDarkestSecret() << "\n";
    }
}

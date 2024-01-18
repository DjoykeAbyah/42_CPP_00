/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 21:01:05 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/18 22:13:22 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook():contactIndex(0){};

PhoneBook::~PhoneBook(){};

/**
 * @todo 
 * give error message if user inputs non-numeric char
 * or numeric char < 0 or > 8
 * ◦ Display the saved contacts as a list of 4 columns: index, first name, last 
 * name and nickname.
 * ◦ Each column must be 10 characters wide. A pipe character (’|’) separates
 * them. The text must be right-aligned. If the text is longer than the column,
 * it must be truncated and the last displayable character must be replaced by a
 * dot (’.’).
 * ◦ Then, prompt the user again for the index of the entry to display. If the index
 * is out of range or wrong, define a relevant behavior. Otherwise, display the
 * contact information, one field per line
 */ 
void PhoneBook::searchContact()
{
    std::string pageNum;
    
    displayContacts();
    std::cout << "Which page do you want to see?\n";
    std::cout << "please give a number 1 - 8\n";
    std::cin >> pageNum;
    int number = std::stoi(pageNum);
    printContact(number);
}

int PhoneBook::getContactIndex() const
{
    return contactIndex;
}

/**
 * @todo 
 * 1. parsing checks on correct input of each field
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
 * @todo add user input parsing checks
 */ 
void PhoneBook::printContact(int page)
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

void PhoneBook::displayContacts() //const so the function can't modify the content
{
   for (int index = 0; index < 8; index++)
    {
        std::cout << std::setw(10) << contacts[index].getFirstName() << " | "
                    << std::setw(10) << contacts[index].getLastName() << " | " 
                    << std::setw(10) << contacts[index].getPhoneNumber() << " | "
                    << std::setw(10) << contacts[index].getDarkestSecret() << std::endl;
    }
}


/**
 * @todo make the method
 */ 
void PhoneBook::printPhoneBook()
{
    
}

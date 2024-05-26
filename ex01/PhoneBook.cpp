/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 21:01:05 by dreijans      #+#    #+#                 */
/*   Updated: 2024/05/26 17:11:37 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Utils.hpp"

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
 * check's if phoneBook is empty
 */ 
bool PhoneBook::isEmpty()
{
    for (int i = 0; i < 8; ++i)
    {
        if (!contacts[i].getFirstName().empty())
            return false; // At least one contact is not empty
    }
    return true; // All contacts are empty
}

bool PhoneBook::isValidPageIndex(int index)
{
    return index >= 1 && index <= 8;
}

bool PhoneBook::printContactIfNotEmpty(int index)
{
    int arrayIndex = index - 1;

    if (contacts[arrayIndex].getFirstName().empty())
    {
        std::cout << RED << "\nEntry is empty\n\n" << RESET << std::endl;
        return false;
    }
    printContact(index);
    return true;
}

/**
 * Searches a contact based on the index number of the phonebook
 */ 
void PhoneBook::searchContact()
{
    std::string pageNum;
    
    printPhoneBook();
    if (isEmpty())
    {
        std::cout << BLUE "\nPhoneBook is empty\n\n\n" << RESET << std::endl;
        return ;
    }
    std::cout << "\nWhich page do you want to see?";
    while (true)
    {
        std::cout << " Please choose a number between 1 - 8: ";
        std::cin >> pageNum;
        std::cout <<"\n                           you chose: [" BOLD_TEXT CYAN << pageNum << RESET "]" << std::endl;
        if (isNumeric(pageNum))
        {
            int number = std::stoi(pageNum);
            if (isValidPageIndex(number))
            {
                if (printContactIfNotEmpty(number))
                    break ;
            }
            else
                std::cout << RED "\nPlease enter a number between 1 and 8.\n\n" RESET << std::endl;
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
 */
void PhoneBook::addContact()
{
    std::string answer;
    bool isValidInput = false;
    
    if (contactIndex == 8)
    {
        std::cout << BOLD_TEXT << "\n you're about to overwrite the first contact, are you sure?\n" << RESET <<std::endl;
        while (!isValidInput)
        {
            std::cout << "type yes or no in lowercase: \n";
            if (!safeGetLine(answer))
                return ;
            std::cout << "                           you chose: [" BOLD_TEXT << answer << RESET "]" << std::endl;
            std::cout << std::endl;
            if (answer == "no")
                return ;
            if (answer == "yes")
            {
                isValidInput = true;
                contactIndex = 0;    
            }
        }
    }
    contacts[contactIndex].setFirstName();
    contacts[contactIndex].setLastName();
    contacts[contactIndex].setNickName();
    contacts[contactIndex].setPhoneNumber();
    contacts[contactIndex].setDarkestSecret();
    contactIndex++;
    std::cout << GREEN "you've successfully added a new contact!\n\n\n" << RESET <<std::endl;
}

/**
 * deletes contact and contact info on specific index of the array
 */
void PhoneBook::deleteContact()
{
    std::string pageNum;
    
    printPhoneBook();
    if (isEmpty())
    {
        std::cout << BLUE "\nPhoneBook is empty\n\n\n" << RESET << std::endl;
        return ;
    }
    std::cout << "\nWhich contact do you want to delete? ";
    while (true)
    {
        std::cout << "Please give a number 1 - 8: ";
        std::cin >> pageNum;
        std::cout << "                           you chose: [" BOLD_TEXT  CYAN<< pageNum << RESET "]" << std::endl;
        if (isNumeric(pageNum))
        {
            int number = std::stoi(pageNum);
            if (number >= 1 && number <= 8)
            {
                number -= 1;
                if (contacts[number].getFirstName().empty())
                {
                   std::cout << RED "\nthis entry does not exist\n\n\n" << RESET << std::endl;
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                   continue; 
                }
                contacts[number].resetContact();
                std::cout << GREEN "\nYou've successfully deleted entry nr." << pageNum << "\n\n\n" RESET << std::endl;
                break;
            }
            else
                std::cout << RED "\nPlease enter a number between 1 and 8.\n\n" RESET << std::endl;
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
        std::cout << BOLD_TEXT << "\nContact information:\n\n" << RESET
              << "First Name: " YELLOW << contacts[page].getFirstName() << RESET "\n"
              << "Last Name: " YELLOW << contacts[page].getLastName() << RESET "\n"
              << "Nickname: " YELLOW << contacts[page].getNickName() << RESET "\n"
              << "Phone Number: " YELLOW << contacts[page].getPhoneNumber() << RESET "\n"
              << "Darkest Secret: " YELLOW << contacts[page].getDarkestSecret() << RESET"\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\n\n\n" << std::endl;
}

/**
 * displays all entered contacts and truncates entries longer than with 10
 */ 
void PhoneBook::printPhoneBook()
{
    int pageIndex = 1; // Starting page index

    for (int index = 0; index < 8; index++)
    {
        std::cout << std::setw(5) << std::right << YELLOW << pageIndex++ <<  RESET " | "
                  << std::setw(10) << std::right << truncateInput(contacts[index].getFirstName()) << " | "
                  << std::setw(10) << std::right << truncateInput(contacts[index].getLastName()) << " | " 
                  << std::setw(10) << std::right << truncateInput(contacts[index].getPhoneNumber()) << " | "
                  << std::setw(10) << std::right << truncateInput(contacts[index].getDarkestSecret()) << std::endl;
    }
}

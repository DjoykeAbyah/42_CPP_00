/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 21:01:05 by dreijans      #+#    #+#                 */
/*   Updated: 2024/05/28 21:20:14 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Utils.hpp"
#include "UI.hpp"

PhoneBook::PhoneBook():contactIndex(0){};

PhoneBook::~PhoneBook(){};

/**
 * Contact Index getter
 */
int PhoneBook::getContactIndex() const
{
    return contactIndex;
}

/**
 * links enum to input
 */
UserChoice getChoice(const std::string& input) 
{
    if (input == "ADD") 
		return ADD;
    if (input == "SEARCH") 
		return SEARCH;
    if (input == "DELETE") 
		return DELETE;
    if (input == "EXIT") 
		return EXIT;
    return INVALID;
}

/**
 * @brief   checks if input is numeric
 * @return  false is not digits and number is not
 *          between 0 and 9 
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
 * @brief   check's if phoneBook is empty
 * @return  false if at least one contact is not empty
 *          false if all contacts are empty
 */ 
bool PhoneBook::isEmpty()
{
    for (int i = 0; i < 8; ++i)
    {
        if (!contacts[i].getFirstName().empty())
            return false;
    }
    return true;
}

/**
 * @brief   check's input index is a valid index
 * @return  index is it's between 1 and 8
 */ 
bool PhoneBook::isValidPageIndex(int index)
{
    return index >= 1 && index <= 8;
}

/**
 * @brief   prints contact if not an empty entry
 * @param   int index
 * @return  false if entry is empty
 *          true is entry exists
 */ 
bool PhoneBook::printContactIfNotEmpty(int index)
{
    int arrayIndex = index - 1;

    if (contacts[arrayIndex].getFirstName().empty())
    {
        std::cout << UI::RED << "\nEntry is empty\n\n" << UI::RESET << std::endl;
        return false;
    }
    printContact(index);
    return true;
}

/**
 * @brief   searches a contact based on the index number of the phonebook
 *          gives error message if user input is not index 1 till 8.
 *          checks if contact is empty or not and shows prompt again if input is faulty
 */ 
void PhoneBook::searchContact()
{
    std::string pageNum;
    
    printPhoneBook();
    if (isEmpty())
    {
        UI::isEmpty();
        return ;
    }
    std::cout << "\nWhich page do you want to see?";
    while (true)
    {
        UI::numericOptions();
        std::cin >> pageNum;
        UI::showChoice(pageNum); 
        if (isNumeric(pageNum))
        {UI::invalidInput();
            int number = std::stoi(pageNum);
            if (isValidPageIndex(number))
            {
                if (printContactIfNotEmpty(number))
                    break ;
            }
            else
                UI::introduceOptions();
        }
    }
}

/**
 * adds contact and contact info to the array
 */
void PhoneBook::addContact()
{
    std::string answer;
    bool isValidInput = false;
    
    if (contactIndex == 8 || repeat == true)
    {
        std::cout << UI::BOLD_TEXT << "\nyou're about to overwrite your oldest contact, are you sure?" << UI::RESET <<std::endl;
        while (!isValidInput)
        {
            std::cout << "type yes or no in lowercase: ";
            if (!safeGetLine(answer))
                return ;
            UI::showChoice(answer);
            std::cout << std::endl;
            if (answer == "no")
                return ;
            if (answer == "yes")
            {
                isValidInput = true;
                contactIndex = 0;
                repeat = true;   
            }
        }
    }
    contacts[contactIndex].setFirstName();
    contacts[contactIndex].setLastName();
    contacts[contactIndex].setNickName();
    contacts[contactIndex].setPhoneNumber();
    contacts[contactIndex].setDarkestSecret();
    contactIndex++;
    std::cout << UI::GREEN << "you've successfully added a new contact!\n\n\n" << UI::RESET <<std::endl;
}

/**
 * deletes contact and contact info on specific index of the array
 * @todo does this mess up the contactindex?
 */
void PhoneBook::deleteContact()
{
    std::string pageNum;
    
    printPhoneBook();
    if (isEmpty())
    {
        UI::isEmpty();
        return ;
    }
    std::cout << "\nWhich contact do you want to delete? ";
    while (true)
    {
        UI::numericOptions();
        std::cin >> pageNum;
        UI::showChoice(pageNum);
        if (isNumeric(pageNum))
        {
            int number = std::stoi(pageNum);
            if (number >= 1 && number <= 8)
            {
                number -= 1;
                if (contacts[number].getFirstName().empty())
                {
                   std::cout << UI::RED << "\nthis entry does not exist\n\n\n" << UI::RESET << std::endl;
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                   continue; 
                }
                contacts[number].resetContact();
                contactIndex--;
                std::cout << UI::GREEN << "\nYou've successfully deleted entry nr." << pageNum << "\n\n\n" << UI::RESET << std::endl;
                break;
            }
            else
                UI::introduceOptions();
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
        std::cout << UI::BOLD_TEXT << "\nContact information:\n\n" << UI::RESET
              << "First Name: " << UI::YELLOW << contacts[page].getFirstName() << UI::RESET << "\n"
              << "Last Name: " << UI::YELLOW << contacts[page].getLastName() << UI::RESET << "\n"
              << "Nickname: " << UI::YELLOW << contacts[page].getNickName() << UI::RESET << "\n"
              << "Phone Number: " << UI::YELLOW << contacts[page].getPhoneNumber() << UI::RESET << "\n"
              << "Darkest Secret: " << UI::YELLOW << contacts[page].getDarkestSecret() << UI::RESET << "\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\n\n" << std::endl;
}

/**
 * displays all entered contacts and truncates entries longer than with 10
 */ 
void PhoneBook::printPhoneBook()
{
    int pageIndex = 1; // Starting page index

    for (int index = 0; index < 8; index++)
    {
        std::cout << std::setw(5) << std::right << UI::YELLOW << pageIndex++ << UI::RESET << " | "
                  << std::setw(10) << std::right << truncateInput(contacts[index].getFirstName()) << " | "
                  << std::setw(10) << std::right << truncateInput(contacts[index].getLastName()) << " | " 
                  << std::setw(10) << std::right << truncateInput(contacts[index].getPhoneNumber()) << " | "
                  << std::setw(10) << std::right << truncateInput(contacts[index].getDarkestSecret()) << std::endl;
    }
}

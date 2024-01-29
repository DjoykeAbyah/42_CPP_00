/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 23:01:58 by djoyke        #+#    #+#                 */
/*   Updated: 2024/01/29 17:36:29 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cctype>
# include <string>
# include <iomanip> 
# include "Contact.hpp"

/**
 * PhoneBook class represents a simple phone book with a limited number of contacts.
 * @param contacts: Private array to store Contact objects, with a fixed size of 8.
 * @param contactIndex: Private variable to track the current index in the contacts array.
 */
class PhoneBook
{
	private:
		Contact contacts[8];
		int contactIndex;

	public:
		/**
		 * Constructor for the PhoneBook class.
		 */
		PhoneBook();
		
		/**
		 * Destructor for the PhoneBook class.
		 */
		~PhoneBook();

	void searchContact();
	void addContact();
	int getContactIndex() const;
	void deleteContact();
	void printContact(int page);
	void printPhoneBook();
	std::string truncateInput(const std::string& input);
	bool isNumeric(std::string& pageNum);
	bool isEmpty();
	bool isValidPageIndex(int index);
	bool printContactIfNotEmpty(int index);
};

#endif
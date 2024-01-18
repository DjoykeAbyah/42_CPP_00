/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 23:01:58 by djoyke        #+#    #+#                 */
/*   Updated: 2024/01/18 16:59:41 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include <string>
#include "Contact.hpp"

//class
class PhoneBook
{
	private:
		Contact contacts[8];
		int contactIndex;

	public:
		PhoneBook();//constructor
		~PhoneBook();//deconstructor
	
	void setPhoneBook();
	void getPhoneBook();//need this?

	void searchContact();
	void addContact();
	int getContactIndex() const;//why const here?
	void deleteContact();
	void printPhoneBook(int page);
};

#endif
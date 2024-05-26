/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 23:13:19 by djoyke        #+#    #+#                 */
/*   Updated: 2024/03/13 13:10:10 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <cctype>
# include <limits>

//class
class Contact
{
	private:
		std::string _firstName;//change this
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:
		Contact();//constructor
		~Contact();//deconstructor
		
		void setFirstName();
		void setLastName();
		void setNickName();
		void setPhoneNumber();
		void setDarkestSecret();
		
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
	
		bool isAlphabetic(const std::string str);
		void nameCheck(std::string& input, const std::string& prompt);
		void phoneNumberCheck();
		bool digitCheck(std::string& input);
		void resetContact();
};

#endif
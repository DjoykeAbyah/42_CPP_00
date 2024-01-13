/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 18:38:39 by djoyke        #+#    #+#                 */
/*   Updated: 2024/01/13 22:55:25 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>


/**
 * @param argc argument count
 * @param argv argument strings
 * @brief transforms lowercase arguments to uppercasse
 * if no args presented besides executor displays Loud and unbearable noice
 * @todo do I need to return error if numeric characters?
 */
int main(int argc, char **argv)
{   
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE NOICE *" <<std::endl;
        return (0);
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            std::string word(argv[i]);
            for (int j = 0; j < word.size(); j++)
            {
                char& alphachar = word[j];
                std::cout << static_cast<char>(std::toupper(alphachar));
            }
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
    return (0);
}
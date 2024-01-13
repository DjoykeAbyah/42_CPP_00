/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 18:38:39 by djoyke        #+#    #+#                 */
/*   Updated: 2024/01/13 21:19:02 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

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
                if (std::isalpha(alphachar))
                    std::cout << static_cast<char>(std::toupper(alphachar));
            }
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
    return (0);
}
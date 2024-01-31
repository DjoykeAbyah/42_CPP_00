/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 17:08:26 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/31 17:29:31 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>


int main() {
    const int numberOfAccounts = 3;

    // Declare an array of Account objects and initialize them with the parameterized constructor
    Account accounts[numberOfAccounts] = 
	{
        Account(1000),  // initialize with initial deposit 1000
        Account(1500),  // initialize with initial deposit 1500
        Account(2000)   // initialize with initial deposit 2000
    };

    // Access and perform operations on each account
    accounts[0].makeDeposit(500);
    accounts[1].makeWithdrawal(200);

    // Display account information
    for (int i = 0; i < numberOfAccounts; ++i) {
        accounts[i].displayStatus();
    }

    // Display overall account information
    Account::displayAccountsInfos();

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 18:25:35 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/30 21:01:26 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit){};

Account::Account(){};

Account::~Account(){};

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	//how to create total number of deposits?
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

/**
 * @todo add timestamp
 * [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
*/
void Account::displayAccountsInfos()
{
    std::cout << " accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals() << std::endl;
}

/**
 * make disposit so
 * _amount
 * _nbDeposits
 * 
*/
void Account::makeDeposit(int deposit)
{
	deposit += _amount;
	_nbDeposits += 1;
	deposit += _totalAmount;
	_totalNbDeposits += 1;
}

bool Account::makeWithdrawal(int withdrawal)
{
	withdrawal -= _amount;
	_nbWithdrawals += 1;
	withdrawal -= _totalAmount;
	_totalNbWithdrawals += 1;
	return true;
}

int Account::checkAmount()const
{
	return _totalAmount;
}

/**
 * @todo add timestamp
 * [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
*/
void Account::displayStatus()const
{
	
}

void Account::_displayTimestamp()
{
	
}
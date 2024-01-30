/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 18:25:35 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/30 21:13:30 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

//google declaring static fields in c++
//non-member attributes
	static int	_nbAccounts = 0;
	static int	_totalAmount = 0;
	static int	_totalNbDeposits = 0;
	static int	_totalNbWithdrawals = 0;

//you gotta make this first duh
Account::Account(int initial_deposit)
{
	//first time has to be 0;
	_accountIndex = _nbAccounts;//its not always 0
	_amount = 0;
	_nbDeposits = initial_deposit;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	static int	_totalNbDeposits = 0;
	static int	_totalNbWithdrawals = 0;
	
}

//you gotta make this first duh
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
	_amount += deposit;
	_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_amount -= withdrawal;
	_nbWithdrawals += 1;
	_totalAmount -= withdrawal;
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
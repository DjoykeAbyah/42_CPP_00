/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 18:25:35 by dreijans      #+#    #+#                 */
/*   Updated: 2024/01/30 19:22:26 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

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
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits += 1;//or
	_totalNbDeposits += 1;
	deposit += _totalAmount;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_nbWithdrawals += 1;//or
	_totalNbWithdrawals += 1;
	withdrawal -= _totalAmount;
}

int Account::checkAmount()const
{
	return _totalAmount;
}

void Account::displayStatus()const
{
	
}

void Account::_displayTimestamp()
{
	
}
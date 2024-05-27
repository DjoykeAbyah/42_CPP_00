/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 18:25:35 by dreijans      #+#    #+#                 */
/*   Updated: 2024/05/27 17:03:42 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

//google declaring static fields in c++
//non-member attributes
int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/**
 * @todo add timestamp
 * [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
*/
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	// _displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account()
{
	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;	
	_nbAccounts++;
}

/**
 * @todo add timestamp
 * [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
*/
Account::~Account()
{
	// _displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

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
 * @todo add timestamp
 * [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
*/
void Account::makeDeposit(int deposit)
{
	int _pAmount = _amount;
	
	_amount += deposit;
	_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	std::cout << " index:" << _accountIndex << ";p_amount:" << _pAmount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

/**
 * @todo add timestamp
 * [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
*/
bool Account::makeWithdrawal(int withdrawal)
{
	int _pAmount = _amount;
	
	if (_amount < withdrawal)
	{
		std::cout << " index:" << _accountIndex << ";p_amount:" << _pAmount << ";withdrawal:" << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals += 1;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	std::cout << " index:" << _accountIndex << ";p_amount:" << _pAmount << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
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
	std::cout << " index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "deposits:" << _nbDeposits << ";"
			<< "withdrawals:" << _nbWithdrawals << std::endl;
}

/**
 * @todo add timestamp
 * [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
*/
void Account::_displayTimestamp()
{
	
}
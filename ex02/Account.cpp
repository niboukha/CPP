/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:42:57 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/31 16:01:52 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(nullptr);
	std::tm calendar_time = *std::localtime( std::addressof(now) );
	std::cout << '[' << calendar_time.tm_year + 1900 << calendar_time.tm_mon + 1 
			<< calendar_time.tm_mday << '_' << calendar_time.tm_hour
			<< calendar_time.tm_min << calendar_time.tm_sec << ']' << std::flush;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();

	std::cout << ' ' << "accounts:" <<  getNbAccounts() << ";total:" << Account::getTotalAmount()
				<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
	_totalAmount = 0;
}

Account::Account(int initial_deposit) :
		_accountIndex(_nbAccounts++),
		_amount(initial_deposit),
		_nbDeposits(_totalNbDeposits),
		_nbWithdrawals(_totalNbWithdrawals)
{
	_displayTimestamp();
	_totalAmount += _amount;
	std::cout << ' ' << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << ' ' << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	_nbDeposits = 1;
	_totalNbDeposits += 1;
	std::cout << ' ' << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposits:" << deposit << std::flush;
	_amount += deposit;
	_totalAmount += _amount;
	std::cout << ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

int	Account::checkAmount( void ) const
{
	if (_amount < 0)
		return (1);
	return (0);
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << ' ' << "index:" << _accountIndex
			<< ";p_amount:" << _amount << std::flush;
	_amount -= withdrawal;
	if (checkAmount())
	{
		_amount += withdrawal;
		_totalAmount += _amount                 ;
		std::cout << ";withdrawal:" << "refused" << std::endl;
		return (false);
	}
	_totalAmount += _amount;
	_nbWithdrawals = 1;
	_totalNbWithdrawals += 1;
	std::cout << ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return (true);
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << ' ' << "index:" << _accountIndex << ';'
				<< "amount:" << _amount << ';'
				<< "closed" << std::endl;
}




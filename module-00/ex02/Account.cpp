#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;



void stampCreation(int index, int amount)
{
    std::cout << "index:" << index << ";amount:" << amount << ";created" << std::endl;
}

Account::Account( int initial_deposit )
{
    static int index = 0;
    static int totalAm = 0;

    _displayTimestamp();
    stampCreation(index, initial_deposit);
    this->_amount = initial_deposit;
    totalAm += this->_amount;
    this->_accountIndex = index++;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_nbAccounts = index;
    this->_totalAmount = totalAm;
    this->_totalNbDeposits = 0;
    this->_totalNbWithdrawals = 0;

}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
};

int Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int Account::getTotalAmount( void )
{
    return _totalAmount;
}

int Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void)
{
	char		buffer[19];
	time_t		t;
	struct tm	*tm;

	t = time(0);
	tm = localtime(&t);
	strftime(buffer, 19, "[%Y%m%d_%H%M%S] ", tm);
	std::cout << buffer;
}

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    _amount += deposit;
    if (deposit > 0)
    {
        _nbDeposits++;
        _totalNbDeposits++;
        _totalAmount += deposit;
    }
    std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(  int withdrawal  )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    if (_amount < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (true);
    }
    _amount -=withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (false);
}

int Account::checkAmount( void ) const
{
    return (0);
}

void Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

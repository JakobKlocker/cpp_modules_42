#include "Account.hpp"
#include <iostream>

Account::Account(int deposit)
{
    static int index = 0;
    Account::_accountIndex = index;
    Account::_amount = deposit;
    Account::_nbDeposits = 0;
    Account::_nbWithdrawals = 0;
    index++;
}

static void	displayAccountsInfos( void )
{
    std::cout << "accounts:" <<

}
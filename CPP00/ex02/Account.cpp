/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:42:54 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/18 22:32:49 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
    this->_accountIndex = this->_nbAccounts;
    this->_nbAccounts++;
    this->_amount = initial_deposit;
    this->_totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void) {
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void) {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void) {
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void) {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
    if (withdrawal > this->_amount) {
        std::cout << "refused" << std::endl;
        return (false);
    }
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount(void) const {
    return (this->_amount);
}

void Account::displayStatus(void) const {
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
        << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::cout << "[" << ltm->tm_year + 1900 << std::setw(2) << std::setfill('0')
        << ltm->tm_mon + 1 << std::setw(2) << std::setfill('0') << ltm->tm_mday
        << "_" << std::setw(2) << std::setfill('0') << ltm->tm_hour << std::setw(2)
        << std::setfill('0') << ltm->tm_min << std::setw(2) << std::setfill('0') << ltm->tm_sec << "] ";
}
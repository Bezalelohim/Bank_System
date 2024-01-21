#include "account.h"
#include "database_operations.h"


Account::Account(int accountId, int customerId, double balance, const std::string& type)
    : accountId(accountId), customerId(customerId), balance(balance), type(type) {}

int Account::getAccountId() const {
    return accountId;
}

int Account::getCustomerId() const {
    return customerId;
}

double Account::getBalance() const {
    return balance;
}

std::string Account::getType() const {
    return type;
}

void Account::updateBalance(double newBalance) {
    balance = newBalance;
}

void Account::displayInfo() const {
    std::cout << "Account ID: " << accountId << " Customer ID: " << customerId << " Balance: " << balance << " Type: " << type << std::endl;
}


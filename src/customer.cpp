#include "customer.h"
#include "database_operations.h"
#include<iostream>

Customer::Customer(int customerId, const std::string& name, const std::string& address, const std::string& contactInfo, double bankBalance)
    : customerId(customerId), name(name), address(address), contactInfo(contactInfo), bankBalance(bankBalance) {}

int Customer::getCustomerId() const {
    return customerId;
}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getAddress() const {
    return address;
}

std::string Customer::getContactInfo() const {
    return contactInfo;
}

double Customer::getBankBalance() const {
    return bankBalance;
}

void Customer::updateInfo(const std::string& newAddress, const std::string& newContactInfo) {
    address = newAddress;
    contactInfo = newContactInfo;
}

void Customer::displayInfo() const {
    std::cout << "Customer ID: " << customerId << " Name: " << name << " Balance: " << bankBalance << std::endl;
}

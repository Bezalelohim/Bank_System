#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
public:
    // Constructor with account type
    Account(int accountId, int customerId, double balance, const std::string& type);
    Account() : accountId(0), customerId(0), balance(0.0), type("") {}

    // Getter methods
    int getAccountId() const;
    int getCustomerId() const;
    double getBalance() const;
    std::string getType() const;

    // Setter method
    void updateBalance(double newBalance);

    // Display account information
    void displayInfo() const;

 
 
private:
    int accountId;
    int customerId;
    double balance;
    std::string type;
};

#endif

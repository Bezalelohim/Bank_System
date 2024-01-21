#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    Customer(int customerId, const std::string& name, const std::string& address, const std::string& contactInfo, double bankBalance);
    Customer() : customerId(0), name(""), address(""), contactInfo(""), bankBalance(0.0) {}

    // Getter methods
    int getCustomerId() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getContactInfo() const;
    double getBankBalance() const;

    // Setter methods
    void updateInfo(const std::string& newAddress, const std::string& newContactInfo);

    // Display customer information
    void displayInfo() const;

  
private:
    int customerId;
    std::string name;
    std::string address;
    std::string contactInfo;
    double bankBalance;
};

#endif

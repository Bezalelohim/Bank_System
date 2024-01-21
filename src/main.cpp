
#include <iostream>
#include <limits>
#include "database_operations.h"
#include "customer.h"
#include "account.h"
#include "transaction.h"




bool databaseConnection (bool databaseConnected)
{   std::string host,user,password,schema;
    std::cout<<"Enter Host Name: "<<std::endl;
    std::cin>>host;

    std::cout<<"Enter User Name: "<<std::endl;
    std::cin>>user;

    std::cout<<"Enter Password: "<<std::endl;
    std::cin>>password;

    std::cout<<"Enter Schema: "<<std::endl;
    std::cin>>schema;

    DatabaseOperations::initializeDatabase(host,user,password,schema,databaseConnected);
    return databaseConnected;

}
void displayMainMenu() {
    std::cout << "\nBank System Main Menu" << std::endl;
    std::cout << "1. Customer Operations" << std::endl;
    std::cout << "2. Account Operations" << std::endl;
    std::cout << "3. Transaction Operations" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

void customerMenu(){
    std::cout << "\nCustomer Operations Menu" << std::endl;
    std::cout << "1. Create Customer " << std::endl;
    std::cout << "2. Delete  Customer " << std::endl;
    std::cout << "3. Display  Customer Details " << std::endl;
}

void accountMenu(){
    std::cout << "\nAccount Operations Menu" << std::endl;
    std::cout << "1. Create Account " << std::endl;
    std::cout << "2. Delete  Account " << std::endl;
    std::cout << "3. Display  Account Details " << std::endl;
}

void transactionMenu(){
    std::cout << "\nTransaction Operations Menu" << std::endl;
    std::cout << "1. Create Transaction " << std::endl;
    std::cout << "2. Delete  Transaction " << std::endl;
    std::cout << "3. Display  Transaction Details " << std::endl;
}

int getInput(const std::string& prompt, int min, int max) {
    int input;
    while (true) {
        std::cout << prompt;
        if (!(std::cin >> input) || input < min || input > max) {
            std::cout << "Invalid input! Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return input;
        }
    }
}

void handleCustomerOperations() {
    int customerId;
    std::string name, address, contactInfo;
    double bankBalance;

    std::cout << "Enter Customer Details\n";
    std::cout << "Customer ID: ";
    std::cin >> customerId;
    std::cin.ignore(); // Ignore newline left in the input buffer

    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Address: ";
    std::getline(std::cin, address);

    std::cout << "Contact Info: ";
    std::getline(std::cin, contactInfo);

    std::cout << "Bank Balance: ";
    std::cin >> bankBalance;

    Customer customer(customerId, name, address, contactInfo, bankBalance);
    // Add logic to save the customer to the database
}

// Function to handle deleting a customer
void handleCustomerOperations(int delcustomerId,bool kill) {

    std::cout << "Customer ID: ";
    std::cin >> delcustomerId;
    std::cin.ignore(); // Ignore newline left in the input buffer

    DatabaseOperations::deleteCustomer(delcustomerId);
}
void handleCustomerOperations(int customerId) {

    std::cout << "Customer ID: ";
    std::cin >> customerId;
    std::cin.ignore(); // Ignore newline left in the input buffer

   DatabaseOperations::readCustomer(customerId);
}



void handleAccountOperations() {
    int accountId;
    int customerId;
    std::string type;
    double bankBalance;

    std::cout << "Enter Customer Details\n";
    std::cout << "Account ID: ";
    std::cin >> accountId;
    std::cin.ignore(); // Ignore newline left in the input buffer

    std::cout << "Customer ID: ";
    std::cin >> customerId;
    std::cin.ignore(); // Ignore newline left in the input buffer

    std::cout << "Account Type: ";
    std::getline(std::cin, type);


    std::cout << "Bank Balance: ";
    std::cin >> bankBalance;

    Account account(accountId, customerId, bankBalance, type);
    DatabaseOperations::createAccount(account);

}
void handleAccountOperations(int delaccountId,bool kill) {

    std::cout << "Account ID: ";
    std::cin >> delaccountId;
    std::cin.ignore(); // Ignore newline left in the input buffer

    DatabaseOperations::deleteAccount(delaccountId);
}

void handleAccountOperations(int accountId) {

    std::cout << "Account ID: ";
    std::cin >> accountId;
    std::cin.ignore(); // Ignore newline left in the input buffer

   DatabaseOperations::readAccount(accountId);
}

void handleTransactionOperations() {

    int transactionId;
    int senderAccountId;
    int receiverAccountId;
    std::string type;
    double amount;

    std::cout << "Enter Transaction Details\n";
    std::cout << "Transaction ID: ";
    std::cin >> transactionId;
    std::cin.ignore(); // Ignore newline left in the input buffer

    std::cout << "Sender Account ID: ";
    std::cin >> senderAccountId;
    std::cin.ignore(); // Ignore newline left in the input buffer


    std::cout << "Receiver Account ID: ";
    std::cin >> receiverAccountId;
    std::cin.ignore(); // Ignore newline left in the input buffer


    std::cout << "Transaction Type: ";
    std::getline(std::cin, type);


    std::cout << "Bank Balance: ";
    std::cin >> amount;

    Transaction transaction(transactionId,senderAccountId, receiverAccountId, amount, type);
    DatabaseOperations::createTransaction(transaction);

}

void handleTransactionOperations(int deltransactionid,bool kill) {

    std::cout << "Transaction ID: ";
    std::cin >> deltransactionid;
    std::cin.ignore(); // Ignore newline left in the input buffer

    DatabaseOperations::deleteTransaction(deltransactionid);
}

void handleTransactionOperations(int transactionid) {

    std::cout << "Transaction ID: ";
    std::cin >> transactionid;
    std::cin.ignore(); // Ignore newline left in the input buffer

    DatabaseOperations::readTransaction(transactionid);
}


int main() {

    bool databaseConnected = false;
    int subChoice;

    databaseConnected = databaseConnection (databaseConnected);

    while (databaseConnected) {
        displayMainMenu();
        int choice = getInput("Enter your choice: ", 1, 4);

        switch (choice) { 
           case 1:
            customerMenu();
             subChoice = getInput("Enter your choice: ", 1, 3);
            switch (subChoice) {
                case 1: 
                    handleCustomerOperations(); // For creating a new customer
                    break;

                case 2:
                    {
                    int delCustomerId;
                    bool kill;
                    std::cout << "Enter Customer ID to delete: ";
                    std::cin >> delCustomerId;
                    handleCustomerOperations(delCustomerId,kill=true); // For deleting a customer
                    break;
                }

                case 3:{
                    int customerId;
                    std::cout << "Enter Customer ID to delete: ";
                    std::cin >> customerId;
                    handleCustomerOperations(customerId);
                    break;
                }

                default: 
                std::cout<<"Invalid Response"<<std::endl;
            }
                break;

            case 2:
            accountMenu();
            subChoice = getInput("Enter your choice: ", 1, 3);
            switch (subChoice) {
                case 1: 
                    handleAccountOperations(); // For creating a new customer
                    break;

                case 2:
                    {
                    int delAccountId;
                    bool kill;
                    std::cout << "Enter Customer ID to delete: ";
                    std::cin >> delAccountId;
                    handleAccountOperations(delAccountId,kill=true); // For deleting a customer
                    break;
                }

                case 3:{
                    int AccountId;
                    std::cout << "Enter Customer ID to delete: ";
                    std::cin >> AccountId;
                    handleAccountOperations(AccountId);
                    break;
                }

                default: 
                std::cout<<"Invalid Response"<<std::endl;
            }
                break;

            case 3:
            transactionMenu();
             subChoice = getInput("Enter your choice: ", 1, 3);
            switch (subChoice) {
                case 1: 
                    handleTransactionOperations(); // For creating a new customer
                    break;

                case 2:
                    {
                    int deltransactionId;
                    bool kill;
                    std::cout << "Enter Customer ID to delete: ";
                    std::cin >> deltransactionId;
                    handleTransactionOperations(deltransactionId,kill=true); // For deleting a customer
                    break;
                }

                case 3:{
                    int transactionId;
                    std::cout << "Enter Customer ID to delete: ";
                    std::cin >> transactionId;
                    handleTransactionOperations(transactionId);
                    break;
                }

                default: 
                std::cout<<"Invalid Response"<<std::endl;
            }
                break;
            case 4:
                std::cout << "Exiting the system." << std::endl;
                return 0;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
}


#ifndef DATABASEOPERATIONS_H
#define DATABASEOPERATIONS_H

#include "mysqlx/xdevapi.h"
#include "customer.h"
#include "account.h"
#include "transaction.h"
#include <iostream>

class DatabaseOperations {
private:
    static std::string dbHost;
    static std::string dbUser;
    static std::string dbPassword;
    static std::string dbSchema;

    static void handleException(const mysqlx::Error& e);
    static mysqlx::Session createSession();

public:
    static void initializeDatabase(const std::string& host, const std::string& user, const std::string& password, const std::string& schema, bool& databaseConnected); 

    // Customer operations
    static void createCustomer(const Customer& customer);
    static Customer readCustomer(int customerId);
    static void deleteCustomer(int customerId);

    // Account operations
    static void createAccount(const Account& account);
    static Account readAccount(int accountId);
    static void deleteAccount(int accountId);

    // Transaction operations
    static void createTransaction(const Transaction& transaction);
    static Transaction readTransaction(int transactionId);
    static void deleteTransaction(int transactionId);
};

#endif // DATABASEOPERATIONS_H

#include "database_operations.h"

std::string DatabaseOperations::dbHost = "";
std::string DatabaseOperations::dbUser = "";
std::string DatabaseOperations::dbPassword = "";
std::string DatabaseOperations::dbSchema = "";

 void DatabaseOperations::initializeDatabase(const std::string& host, const std::string& user, const std::string& password,  const std::string& schema, bool& databaseConnected) {
   
    dbHost = host;
    dbUser = user;
    dbPassword = password;
    dbSchema = schema;
    try {
        mysqlx::Session session(host, user, password, schema);
        databaseConnected = true;
    } catch (const mysqlx::Error& e) {
        databaseConnected = false;
        handleException(e);
    }
}

 void DatabaseOperations::createCustomer(const Customer& customer) {
    try {
        auto session = createSession();
        auto table = session.getSchema(dbSchema).getTable("customers");

        table.insert("customerId", "name", "address", "contactInfo", "bankBalance")
            .values(customer.getCustomerId(), customer.getName(), customer.getAddress(), customer.getContactInfo(), customer.getBankBalance())
            .execute();
    } catch (const mysqlx::Error& e) {
        handleException(e);
    }
}

 void DatabaseOperations::deleteCustomer(int customerId) {
    try {
        auto session = createSession();
        auto table = session.getSchema(dbSchema).getTable("customers");

        table.remove().where("customerId = :id").bind("id", customerId).execute();
    } catch (const mysqlx::Error& e) {
        handleException(e);
    }
}

Customer DatabaseOperations::readCustomer(int customerId) {
    try {
        auto session = createSession();
        auto table = session.getSchema(dbSchema).getTable("customers");
        auto result = table.select("customerId", "name", "address", "contactInfo", "bankBalance")
                           .where("customerId = :id")
                           .bind("id", customerId)
                           .execute();

        auto row = result.fetchOne();
        return Customer(row[0].get<int>(), row[1].get<std::string>(), row[2].get<std::string>(),
                        row[3].get<std::string>(), row[4].get<double>());
    } catch (const mysqlx::Error& e) {
        handleException(e);
        return Customer(); // return an empty Customer object in case of error
    }
}

 void DatabaseOperations::createAccount(const Account& account) {
    try {
        auto session = createSession();
        auto table = session.getSchema(dbSchema).getTable("accounts");

        table.insert("accountId", "customerId", "balance", "type")
            .values(account.getAccountId(), account.getCustomerId(), account.getBalance(), account.getType())
            .execute();
    } catch (const mysqlx::Error& e) {
        handleException(e);
    }
}

Account DatabaseOperations::readAccount(int accountId) {
    try {
        auto session = createSession();
        auto table = session.getSchema(dbSchema).getTable("accounts");
        auto result = table.select("accountId", "customerId", "balance", "type")
                           .where("accountId = :id")
                           .bind("id", accountId)
                           .execute();

        auto row = result.fetchOne();
        return Account(row[0].get<int>(), row[1].get<int>(), row[2].get<double>(), row[3].get<std::string>());
    } catch (const mysqlx::Error& e) {
        handleException(e);
        return Account(); // return an empty Account object in case of error
    }
}



void DatabaseOperations::deleteAccount(int accountId) {
    try {
        auto session = createSession();
        auto table = session.getSchema(dbSchema).getTable("accounts");

        table.remove().where("accountId = :id").bind("id", accountId).execute();
    } catch (const mysqlx::Error& e) {
        handleException(e);
    }
}

 void DatabaseOperations::createTransaction(const Transaction& transaction) {
    try {
        auto session = createSession();
        auto table = session.getSchema(dbSchema).getTable("transactions");

        table.insert("transactionId", "senderAccountId", "receiverAccountId", "amount", "type", "timestamp")
            .values(transaction.getTransactionId(), transaction.getSenderAccountId(), transaction.getReceiverAccountId(), transaction.getAmount(), transaction.getType(), transaction.getTimestamp())
            .execute();
    } catch (const mysqlx::Error& e) {
        handleException(e);
    }
}


Transaction DatabaseOperations::readTransaction(int transactionId) {
    try {
        auto session = createSession();
        auto table = session.getSchema(dbSchema).getTable("transactions");
        auto result = table.select("transactionId", "senderAccountId", "receiverAccountId", "amount", "type", "timestamp")
                           .where("transactionId = :id")
                           .bind("id", transactionId)
                           .execute();

        auto row = result.fetchOne();
        Transaction transaction(row[0].get<int>(), row[1].get<int>(), row[2].get<int>(), row[3].get<double>(), row[4].get<std::string>());
        transaction.timestamp = row[5].get<std::string>();
        return transaction;
    } catch (const mysqlx::Error& e) {
        handleException(e);
        return Transaction(); // return an empty Transaction object in case of error
    }
}

 void DatabaseOperations::deleteTransaction(int transactionId) {
    try {
        auto session = createSession();
        auto table = session.getSchema(dbSchema).getTable("transactions");

        table.remove().where("transactionId = :id").bind("id", transactionId).execute();
    } catch (const mysqlx::Error& e) {
        handleException(e);
    }
}

 void DatabaseOperations::handleException(const mysqlx::Error& e) {
    std::cerr << "MySQL Connector/C++ error: " << e.what() << std::endl;
}

mysqlx::Session DatabaseOperations::createSession() {

    return mysqlx::Session(dbHost, dbUser, dbPassword, dbSchema);
}

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <chrono>

class Transaction {
public:
    // Constructor with additional parameters for time, sender account ID, and receiver account ID
    Transaction(int transactionId, int senderAccountId, int receiverAccountId, double amount, const std::string& type);
    Transaction() : transactionId(0), senderAccountId(0), receiverAccountId(0), amount(0.0), type("""") {}

    // Getter methods
    int getTransactionId() const;
    int getSenderAccountId() const;
    int getReceiverAccountId() const;
    double getAmount() const;
    std::string getType() const;
    std::string getTimestamp() const;
    std::string timestamp;

    // Display transaction information
    void displayInfo() const;

private:
    int transactionId;
    int senderAccountId;
    int receiverAccountId;
    double amount;
    std::string type;
 

    // Private method to generate timestamp using system time
    std::string getCurrentTimestamp() const;
};

#endif

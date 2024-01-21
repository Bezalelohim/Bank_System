#include "transaction.h"
#include "database_operations.h"
#include <ctime>
#include <iostream>

Transaction::Transaction(int transactionId, int senderAccountId, int receiverAccountId, double amount, const std::string& type )
    : transactionId(transactionId), senderAccountId(senderAccountId), receiverAccountId(receiverAccountId), amount(amount), type(type), timestamp(getCurrentTimestamp()) {}

int Transaction::getTransactionId() const {
    return transactionId;
}

int Transaction::getSenderAccountId() const {
    return senderAccountId;
}

int Transaction::getReceiverAccountId() const {
    return receiverAccountId;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getType() const {
    return type;
}

std::string Transaction::getTimestamp() const {
    return timestamp;
}

void Transaction::displayInfo() const { 
std::cout << "Transaction ID: " << transactionId << " Sender Account ID: " << senderAccountId << " Receiver Account ID: " << receiverAccountId << " Amount: " << amount << " Type: " << type << " Timestamp: " << timestamp << std::endl;

}


std::string Transaction::getCurrentTimestamp() const {
    // Get the current timestamp using std::chrono and std::ctime
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    return std::ctime(&currentTime);
}

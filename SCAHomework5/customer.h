//
// Created by Иван Доронин on 16.12.2021.
//

//------------------------------------------------------------------------------
// customer.h - содержит описание отдела магазина и его интерфейса.
//------------------------------------------------------------------------------

#ifndef SCAHOMEWORK5_CUSTOMER_H
#define SCAHOMEWORK5_CUSTOMER_H
#define SCAHOMEWORK5_CUSTOMER_H

#include "iostream"

// Class customer.
class Customer {
private:
    // Name of customer.
    char name_[10];
    // Customers balance.
    int balance_;
public:
    // Constructor.
    explicit Customer(int balance);

    // Getter for balance.
    int getBalance();

    // Getter for name.
    char *getName();

    // Setter for balance.
    void setBalance(int balance);

    // Generator random name.
    void generatorRandomName(char *content, int size);
};


#endif //SCAHOMEWORK5_CUSTOMER_H

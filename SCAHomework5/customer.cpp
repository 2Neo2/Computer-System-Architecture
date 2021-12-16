//
// Created by Иван Доронин on 16.12.2021.
//

//------------------------------------------------------------------------------
// customer.cpp - содержит функции обработки контейнера.
//------------------------------------------------------------------------------

#include "customer.h"

// Constructor.
Customer::Customer(int balance) {
    this->balance_ = balance;
    generatorRandomName(name_, 10);
}

// Generator random name.
void Customer::generatorRandomName(char *content, int size) {
    content[0] = toupper(char('a' + rand() % 26));
    for (int i = 1; i < size; ++i) {
        content[i] = char('a' + rand() % 26);
    }
    content[size] = '\0';
}

// Getter for name.
char *Customer::getName() {
    return name_;
}

// Getter for balance.
int Customer::getBalance() {
    return balance_;
}

// Setter for balance.
void Customer::setBalance(int balance) {
    this->balance_ = balance;
}


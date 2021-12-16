//
// Created by Иван Доронин on 16.12.2021.
//

//------------------------------------------------------------------------------
// store.cpp - содержит функции обработки отдела магазина.
//------------------------------------------------------------------------------

#include "store.h"
#include <thread>

std::mutex mtx_;

// Constructor.
Store::Store(int size) {
    randName(name_, 10);
}

// Getter for name.
char *Store::getName() {
    return name_;
}

// Main method buy.
void Store::buy(Customer &customer) {
    mtx_.lock();
    std::cout << "------------------The buyer makes a purchase" << "\n";
    int count_of_buy = 0;
    int buy = rand() % 12 + 1;
    while (count_of_buy != buy) {
        int count_write_off = getRndSumOnBuy();
        std::cout << count_of_buy << " purchase was " << count_write_off << "\n";
        customer.setBalance(customer.getBalance() - count_write_off);
        ++count_of_buy;
        std::cout << count_of_buy << " purchase is end.\n";
    }
    std::cout << "------------------The buyer has finished a purchase" << "\n";
    mtx_.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000 + 1000));
}

// Get random balance for buy.
int Store::getRndSumOnBuy() {
    return rand() % 150 + 1;
}

// Generate random.
void Store::randName(char *content, int size) {
    content[0] = toupper(char('a' + rand() % 26));
    for (int i = 1; i < size; ++i) {
        content[i] = char('a' + rand() % 26);
    }
    content[size] = '\0';
}

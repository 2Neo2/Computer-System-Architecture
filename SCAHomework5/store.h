//
// Created by Иван Доронин on 16.12.2021.
//

//------------------------------------------------------------------------------
// store.h - содержит описание отдела магазина и его интерфейса.
//------------------------------------------------------------------------------

#ifndef SCAHOMEWORK5_STORE_H
#define SCAHOMEWORK5_STORE_H

#include "iostream"
#include "queue"
#include "customer.h"
#include <mutex>
#include <chrono>

// Class Store.
class Store {
private:
    // Name of store.
    char name_[10];
public:
    // Constructor.
    explicit Store(int size);

    // Main method buy.
    void buy(Customer &customer);

    // Getter for name.
    char *getName();

    // Get random balance for buy.
    int getRndSumOnBuy();

    // Generate random.
    void randName(char *content, int size);
};


#endif //SCAHOMEWORK5_STORE_H

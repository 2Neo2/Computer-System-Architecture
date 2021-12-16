#include <iostream>
#include <vector>
#include "store.h"
#include <thread>

//------------------------------------------------------------------------------
// main.cpp - содержит функции для запуска программы.
//------------------------------------------------------------------------------

int count_of_customers_ = 0;
std::string input_;
std::vector<Customer> customers_;
std::vector<Store> stores_;
std::vector<std::thread> threads_;

// Method generate random store for customer.
void playCustomer(Customer &customer) {
    Store store = stores_[rand() % stores_.size()];
    store.buy(customer);
}

// Welcome or error information.
void welcomeOrError() {
    std::cout << "Если хотите сгенерировать данные случайно введите:r" << "\n";
    std::cout << "Если вы хотите сгенерировать данные через ввод с клавиатуры введите:i" << "\n";
}

// Generate random balance for customer.
int generatorRandomBalance() {
    return rand() % 1000 + 1500;
}

// input count of customers.
void startFilling() {
    std::cout << "Start filling" << "\n";
    while (true) {
        std::cout << "Input count of customers";
        std::cin >> count_of_customers_;
        if (count_of_customers_ <= 0) {
            std::cout << "Input number > 0";
        } else {
            break;
        }
    }
}

// Input data.
void input() {
    welcomeOrError();
    while (true) {
        std::getline(std::cin, input_);
        if (input_[0] == 'r') {
            count_of_customers_ = rand() % 100 + 2;
            break;
        } else if (input_[0] == 'i') {
            startFilling();
            break;
        } else {
            welcomeOrError();
        }
    }
}

// Object initialization.
void init() {
    stores_.push_back(*new Store(4));
    stores_.push_back(*new Store(3));
    stores_.push_back(*new Store(10));
    for (int i = 0; i < count_of_customers_; ++i) {
        customers_.push_back(*new Customer(generatorRandomBalance()));
    }
}

// Write in file before buy.
void writeInFileBefore() {
    FILE *fp;
    fp = fopen("/Users/ivandoronin/CLionProjects/SCAHomework5/beforeBuy.txt", "w+");
    fprintf(fp, "Stores:\n");
    for (int i = 0; i < stores_.size(); ++i) {
        fprintf(fp, "It is Store:\n"
                    "name %s.\n", stores_[i].getName());
    }
    for (int i = 0; i < customers_.size(); ++i) {
        fprintf(fp, "It is Customer:\n"
                    "name: %s.\n"
                    "balance: %d \n", customers_[i].getName(), customers_[i].getBalance());
    }
    fclose(fp);
}

// Write data after buy in file.
void writeInFileAfter() {
    FILE *fp;
    fp = fopen("/Users/ivandoronin/CLionProjects/SCAHomework5/afterBuy.txt", "w+");
    fprintf(fp, "Stores:\n");
    for (int i = 0; i < stores_.size(); ++i) {
        fprintf(fp, "It is Store:\n"
                    "name %s.\n", stores_[i].getName());
    }
    for (int i = 0; i < customers_.size(); ++i) {
        fprintf(fp, "It is Customer:\n"
                    "name: %s.\n"
                    "balance: %d \n", customers_[i].getName(), customers_[i].getBalance());
    }
    fclose(fp);
}

int main() {
    input();
    std::cout << "Count of customers:   " << count_of_customers_ << "\n";
    init();
    std::cout << "Start write in file " << "\n";
    writeInFileBefore();

    for (Customer &customer: customers_) {
        std::thread first_state(playCustomer, std::ref(customer));
        threads_.push_back(std::move(first_state));
    }

    for (int i = 0; i < threads_.size(); ++i) {
        threads_[i].join();
    }

    writeInFileAfter();
    std::cout << "End of game! \n";
    return 0;
}

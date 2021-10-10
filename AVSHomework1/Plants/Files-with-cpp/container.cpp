//
// Created by Иван Доронин on 08.10.2021.
//
#include "../Files-with-h/container.h"

// Инициализация данных.
void init(container &container) {
    container.length = 0;
}

// Отчистка данных.
void clear(container &container) {
    for (int i = 0; i < container.length; i++) {
        delete container.data[i];
    }
    container.length = 0;
}

// Ввод данных в поток.
void in(container &container, std::ifstream &inputFStream) {
    while (!inputFStream.eof()) {
        if ((container.data[container.length] = in(inputFStream)) != 0) {
            container.length++;
        }
    }
}

// Ввод случайных данных в форматируемый поток.
void inRnd(container &container, int size) {
    while (container.length < size) {
        container.data[container.length] = inRnd();
        if (container.data[container.length] != nullptr) {
            container.length++;
        }
    }
}

// Вывод данных.
void out(container &container, std::ofstream &outFStream) {
    outFStream << "Container contains " << container.length << " elements.\n";
    for (int i = 0; i < container.length; i++) {
        outFStream << i << ": ";
        out(*(container.data[i]), outFStream);
    }
}

// Меняем местами элементы.
void swap(plant *a, plant *b) {
    plant plant= *a;
    *a = *b;
    *b = plant;
}

// Реализация сортировки.
void heapify(container &container, int n, int i)
{
    // Initialize largest as root.
    int largest = i;
    // Left.
    int l = 2 * i + 1;
    // Right.
    int r = 2 * i + 2;

    // If left child is larger than root.
    if (l < n && comparisonParameter(*container.data[l]) > comparisonParameter(*container.data[largest])) {
        largest = l;
    }

    // If right child is larger than largest so far.
    if (r < n && comparisonParameter(*container.data[r]) > comparisonParameter(*container.data[largest])) {
        largest = r;
    }


    // If largest is not root.
    if (largest != i) {
        swap(container.data[i], container.data[largest]);

        // Recursively heapify the affected sub-tree.
        heapify(container, n, largest);
    }
}

// Упорядочить элементы контейнера по убыванию используя сортировку с помощью «дерева» (Heap Sort).
// В качестве ключей для сортировки и других действий используются результаты функции, общей для всех альтернатив.
void heapSort(container &container, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(container, n, i);

    // One by one extract an element from heap.
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end.
        swap(container.data[0], container.data[i]);
        // Call max heapify on the reduced heap.
        heapify(container, i, 0);
    }
}

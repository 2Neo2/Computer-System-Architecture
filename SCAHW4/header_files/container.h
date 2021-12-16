//
// Created by Иван Доронин on 02.12.2021.
//

#ifndef SCAHW4_CONTAINER_H
#define SCAHW4_CONTAINER_H
#include "plant.h"

struct container {
    int count;
    struct plant *data[MAX_LEN];
};

void init(struct container *container);

void clear(struct container *container);

void fillRnd(struct container *container, int count);

void fill(struct container *container, FILE *in);

void out(struct container *container, FILE *out);

extern void swap(struct plant *a, struct plant *b);

extern void heapify(struct container *c, int n, int i);

extern void heapSort(struct container *container);
#endif //SCAHW4_CONTAINER_H

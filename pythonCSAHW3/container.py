# ------------------------------------------------------------------------------
# container.py - Container handling functions.
# ------------------------------------------------------------------------------

import random
from extender import *


# ------------------------------------------------------------------------------
# Input data from file.
def in_from_file(cont, plants_data):
    for plant in plants_data:
        type_of_plant = plant[0]
        if type_of_plant == '1':
            tree_arr = []
            tree.in_from_file(tree_arr, plant)
            cont.append(tree_arr)
        if type_of_plant == '2':
            flower_arr = []
            flower.in_from_file(flower_arr, plant)
            cont.append(flower_arr)
        if type_of_plant == '3':
            shrub_arr = []
            shrub.in_from_file(shrub_arr, plant)
            cont.append(shrub_arr)


# ------------------------------------------------------------------------------
# Random filling container.
def in_rnd(cont, size):
    for _ in range(size):
        type_of_plant = random.randint(1, 3)
        if type_of_plant == 1:
            tree_arr = []
            tree.in_rnd(tree_arr)
            cont.append(tree_arr)
        if type_of_plant == 2:
            flower_arr = []
            flower.in_rnd(flower_arr)
            cont.append(flower_arr)
        if type_of_plant == 3:
            shrub_arr = []
            shrub.in_rnd(shrub_arr)
            cont.append(shrub_arr)


# ------------------------------------------------------------------------------
# Output in file.
def out(cont, out_stream):
    out_stream.write(f"Container contains {len(cont)} elements:\n")
    count = 0
    for plant in cont:
        count += 1
        out_stream.write(f"{count}: It is a {plant[0]}, ")

        if plant[0] == "Tree":
            out_stream.write(f"name = {plant[1]}, age = {plant[2]}, ")
        elif plant[0] == "Shrub":
            out_stream.write(f"name = {plant[1]}, flowering month = {plant[2]}, ")
        elif plant[0] == "Flower":
            out_stream.write(f"name = {plant[1]}, type of flower = {plant[2]}")

        out_stream.write(f" comparison parameter = {plant[len(plant) - 1]}\n")


# ------------------------------------------------------------------------------
# Helpful method for heap_sort.
def heapify(plant_arr, n, i):
    largest = i  # Initialize largest as root
    l = 2 * i + 1  # left = 2*i + 1
    r = 2 * i + 2  # right = 2*i + 2

    # See if left child of root exists and is
    # greater than root
    if l < n and plant_arr[i][3] < plant_arr[l][3]:
        largest = l

    # See if right child of root exists and is
    # greater than root
    if r < n and plant_arr[largest][3] < plant_arr[r][3]:
        largest = r

    # Change root, if needed
    if largest != i:
        plant_arr[i], plant_arr[largest] = plant_arr[largest], plant_arr[i]  # swap

        # Heapify the root.
        heapify(plant_arr, n, largest)


# ------------------------------------------------------------------------------
# Heap sorting.
def heap_sort(cont):
    n = len(cont)

    for i in range(n // 2 - 1, -1, -1):
        heapify(cont, n, i)

    # One by one extract elements
    for i in range(n - 1, 0, -1):
        cont[i], cont[0] = cont[0], cont[i]
        heapify(cont, i, 0)
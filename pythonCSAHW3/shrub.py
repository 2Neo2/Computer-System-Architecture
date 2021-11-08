# ------------------------------------------------------------------------------
# shrub.py - description shrub functions.
# ------------------------------------------------------------------------------
import random
from random import choice
from string import ascii_letters


# ------------------------------------------------------------------------------
# Filling shrub objects with values from file.
def in_from_file(shrub_arr, command):
    str_arr = command.split(' ')
    shrub_arr.append("Shrub")
    shrub_arr.append(str_arr[2])
    flowering_month_of_shrubs = float(str_arr[1]) % 12
    if flowering_month_of_shrubs == 0:
        shrub_arr.append("JANUARY")
    elif flowering_month_of_shrubs == 1:
        shrub_arr.append("FEBRUARY")
    elif flowering_month_of_shrubs == 2:
        shrub_arr.append("MARCH")
    elif flowering_month_of_shrubs == 3:
        shrub_arr.append("APRIL")
    elif flowering_month_of_shrubs == 4:
        shrub_arr.append("MAY")
    elif flowering_month_of_shrubs == 5:
        shrub_arr.append("JULE")
    elif flowering_month_of_shrubs == 6:
        shrub_arr.append("JULY")
    elif flowering_month_of_shrubs == 7:
        shrub_arr.append("AUGUST")
    elif flowering_month_of_shrubs == 8:
        shrub_arr.append("SEPTEMBER")
    elif flowering_month_of_shrubs == 9:
        shrub_arr.append("OCTOBER")
    elif flowering_month_of_shrubs == 10:
        shrub_arr.append("NOVEMBER")
    elif flowering_month_of_shrubs == 11:
        shrub_arr.append("DECEMBER")
    shrub_arr.append(comparison_param(shrub_arr))


# ------------------------------------------------------------------------------
# Filling shrub objects to random values.
def in_rnd(shrub_arr):
    shrub_arr.append("Shrub")
    shrub_arr.append(''.join(choice(ascii_letters) for i in range(12)))
    flowering_month_rand = random.randint(0, 11)
    if flowering_month_rand == 0:
        shrub_arr.append("JANUARY")
    elif flowering_month_rand == 1:
        shrub_arr.append("FEBRUARY")
    elif flowering_month_rand == 2:
        shrub_arr.append("MARCH")
    elif flowering_month_rand == 3:
        shrub_arr.append("APRIL")
    elif flowering_month_rand == 4:
        shrub_arr.append("MAY")
    elif flowering_month_rand == 5:
        shrub_arr.append("JULE")
    elif flowering_month_rand == 6:
        shrub_arr.append("JULY")
    elif flowering_month_rand == 7:
        shrub_arr.append("AUGUST")
    elif flowering_month_rand == 8:
        shrub_arr.append("SEPTEMBER")
    elif flowering_month_rand == 9:
        shrub_arr.append("OCTOBER")
    elif flowering_month_rand == 10:
        shrub_arr.append("NOVEMBER")
    elif flowering_month_rand == 11:
        shrub_arr.append("DECEMBER")
    shrub_arr.append(comparison_param(shrub_arr))


# ------------------------------------------------------------------------------
# Comparison parameter for heap sort.
def comparison_param(shrub_arr):
    vowel_letters_count = 0
    name = shrub_arr[1]
    for i in name:
        if i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u' or i == 'y' or i == 'A' or i == 'E' or i == 'I' or i == 'O' or i == 'U' or i == 'Y':
            vowel_letters_count += 1
    return vowel_letters_count / float(len(name))
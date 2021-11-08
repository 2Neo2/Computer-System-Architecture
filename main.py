# ------------------------------------------------------------------------------
# main.py - contains main function for testing functional.
# ------------------------------------------------------------------------------

import sys
import time
from extender import *


def error_message1():
    print ("Incorrect input!\n"
           "Waited:\n"
           "python main -f infile outfile1 outfile2\n"
           "Or:\n"
           "python main -n number outfile1 outfile2\n")


def error_message2():
    print ("Incorrect number of plants! Set 0 < number <= 10000.\n")


def error_message3():
    print("Incorrect qualifier values in command!\n"
          "Waited:\n"
          "python main -f infile outfile1 outfile2\n"
          "Or:\n"
          "python main -n number outfile1 outfile2\n")


# ------------------------------------------------------------------------------
if __name__ == '__main__':
    if len(sys.argv) != 5:
        error_message1()
        exit(1)
    time_start = time.time()
    print("Start -_-")
    cont = []

    if sys.argv[1] == '-f':
        in_file = open(sys.argv[2], 'r')
        plants_array = in_file.read().split("\n")
        in_file.close()
        print("From file start")
        container.in_from_file(cont, plants_array)
        print("From file end")
    elif sys.argv[1] == '-n':
        size = int(sys.argv[2])

        if size < 1 or size > 10000:
            error_message2()
            exit(3)
        print ("Rnd Start")
        container.in_rnd(cont, size)
        print ("Rnd finish.")
    else:
        error_message2()
        exit(2)

    out_file = open(sys.argv[3], 'w+')
    print (f" Start filling file {sys.argv[3]}")
    container.out(cont, out_file)
    out_file.close()
    print (f" Finish filling file {sys.argv[3]}")
    print ("Start heap sort")
    container.heap_sort(cont)
    print ("End heap sort")

    print (f" Start filling file {sys.argv[4]}")
    out_file_sorted_container = open(sys.argv[4], 'w+')
    container.out(cont, out_file_sorted_container)
    out_file_sorted_container.close()
    print (f" Start filling file {sys.argv[4]}")

    time_end = time.time()
    print("CPU time used: " + str(time_end - time_start) + " seconds.")
    print('End -_-')



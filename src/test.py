#!/usr/bin/env python3

import os
import sys

if __name__ == "__main__":

    operation = 5
    delimitors = 5

    me = 0
    him = 0

    for i in range(delimitors):
        sys.stdout.write("#")
        sys.stdout.flush()
    sys.stdout.write("\n")
    sys.stdout.flush()
    for i in range(operation):
        launch_ls = os.system(
            "resources/filler_vm -f src/resources/maps/map02"
            " -p1 resources/players/superjeannot.filler -p2"
            " exports/okurache.filler > 1.txt")
        with open("1.txt", "r") as file:
            containment = file.read().split()
            if int(containment[len(containment) - 5]) \
                    > int(containment[len(containment) - 1]):
                him += 1
            else:
                me += 1
        if i % (operation / delimitors) == 0:
            sys.stdout.write("#")
            sys.stdout.flush()
    sys.stdout.write("\n")
    sys.stdout.flush()
    print("player 1 : " + str(him))
    print("player 2 : " + str(me))

    os.remove("1.txt")
    os.remove("filler.trace")
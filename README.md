# Operating-Systems-Project-2
Repository for the Banker's Algorithm Operating Systems Project

# Description 
    Language: c++

    This is a solution to the Banker's Algorithm Problem in Operating systems. Banker's Algorithm is a solution to deadlock for a systems with multiple processes and multiple instances of multiple resources. Bankers Algoithm fins a safe way to allocate resources within a given system such that deadlock does not occur. This is achived by searching for a sequence of processes where the amount of resources being allocated never exceeds the amount of resources available for all processes in a system. 
# Compilation Commands
    Compiles using the following commands:
    $ g++ b_algorithm.cpp -pthread -lrt -o b_algorithm
    $ ./b_algorithm
# Commit "Problem Within The Algorithm" 
    At this point I have implemented the Banker's Algorithm according to the class lecture notes and the Example from Reference 1. There is a problem within my implementation of the algorithm where it loops through the data set to find a sequence that satisifies the following conditions:
        finish[i] = false;
        work[i] <= available[i]; 
    As written currently the code compiles but Prints out "Unsafe!" Despite the data set containing a safe solution. It does not seem to reach line 87 for all "i" in the array correct_sequence. I am not sure why it has encountered this issue. It may be that it is not asssesing the propper values at the propper points within the nested for loops. 
# References: 
    1: Tutorial Article on GeeksForGeeks Website titled  "Banker's Algorithm in Operating Systems", last
    updated Sept. 2023
    link: https://www.geeksforgeeks.org/bankers-algorithm-in-operating-system-2/

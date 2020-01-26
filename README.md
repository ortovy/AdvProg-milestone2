# AdvProg-milestone2
made by: omer abarzel, or tovy

#summary

in AdvProg-milestone2 we create a problem solution service running by servers,
we are able to open a server ask it a question and get an answer through multithreading.
in our milestone our problem will be finding shortest path in a graph, this will help us in further milestones,
we will be able to give our plane a graph and tell it to fly to X point.
we created the problem and solution objects generic so we can use them in all kinds of ways,
we have a lot of ways defining a graph and a lot of algorithms to search with, because of the generic behaviour of the project we
will be able to expand our project easily to every need we want.

**********************
#how to run the project-

open terminal from the project folder and compile with this command:
g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread

**********************
#clientHandler interface-

this interface will help us manage all the different types of clients we will encounter
in the project. this interface will help us maintain single responsibility and open/close.
the client handler will recieve a protocol and work with it.
for exemple: finding paths in matrix's, and reversing a string.
each client handler will also have a server type

**********************
-serial server-
a serial server will be handled one client at a time.

**********************
-parallel server-
parallel server can handle multiple clients at a time via multithreading.
each time we open a client handler we will inject it a server type.
for exemple: if we will want the client handler to work with one client at a time we will inject 
serial server,

**********************
#searchable interface-

searchable interface will help us generalize graphes.
in our program the searchable we use is a matrix.
to help every matrix contains states(which is a generic interface to nodes)

**********************
#searcher interface-

searcher interface will help us generalize searching algorithems in graphs.
out searchers will be BFS DFS Astar and BESTFS algorithms 
each searcher has the abillity to use search() function on every "searchable" we desire.

**both searcher and searchable generic objects are conneted through an object called adapter,
this object helps us seperate both generic classes

**********************
#myPQueue-

in order to implement certain pathfinding algorithms we use a special implementation of priority queue.
this PQ can compare states and push the "smallest state" to the top of the queue.

**********************
#chacheManager-

in order to not spend extra time on solving a solution we created a cahce manager that saves every solution of a problem in a hashmap
so if we have a problem we already solved we can now return the solution in o(1) time.


*********************************
----our empirical experiment----
in this project we use a parallel client server in order to conduct an experiment.
our goal is to find the most efficient accurate path finding algorithm.
we try each algorithm over 10 matrix's to find what searching algorithm is the best.
the results of the experemint are added in a seperate pdf file.



#gitHub link

https://github.com/omerabargel8/AdvProg-milestone2

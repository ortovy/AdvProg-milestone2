# AdvProg-milestone2

in AdvProg-milestone2 we create a problem solution service running by servers,
we are able to open a server ask it a question and get an answer through multithreading.
in our milestone our problem will be finding shortest path in a graph, this will help us in further milestones,
we will be able to give our plane a graph and tell it to fly to X point.
we created the problem and solution objects generic so we can use them in all kinds of ways,
we have a lot of ways defining a graph and a lot of algorithms to search with, because of the generic behaviour of the project we
will be able to expand our project easily to every need we want.

**********************
#searchable interface
searchable interface will help us generalize graphes.
in our program the searchable we use is a matrix.
to help every matrix contains states(which is a generic interface to nodes)
**********************
#searcher interface
searcher interface will help us generalize searching algorithems in graphs.
out searchers will be BFS DFS Astar and BESTFS algorithms 
each searcher has the abillity to use search() function on every "searchable" we desire.

**both searcher and searchable generic objects are conneted through an object called adapter,
this object helps us seperate both generic classes

--myPQueue--
in order to implement certain pathfinding algorithms we use a special implementation of priority queue.
this PQ can compare states and push the "smallest state" to the top of the queue.

--chacheManager
in order to not spend extra time on solving a solution we created a cahce manager that saves every solution of a problem in a hashmap
so if we have a problem we already solved we can now return the solution in o(1) time.

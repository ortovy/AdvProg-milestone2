//
// Created by omer on 16/01/2020.
//

#include "BFS.h"
string BFS::search(Searchable<pair<int, int>> s) {
    // Mark all the vertices as not visited
    vector<pair<int, int>> visited;
    /**
    for(int i = 0; i < visited.size(); i++)
        visited[i] = false;
*/
    // Create a queue for BFS
    list<pair<int, int>> queue;

    // Mark the current node as visited and enqueue it
    visited.push_back(s.getInitialState());
    queue.push_back(s.getInitialState());

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<pair<int, int>>::iterator i;
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        pair<int, int> p  = queue.front();
        //cout << s << " ";
        queue.pop_front();
        list<pair<int, int>> adjList = s.getAllPossibleStates(p);
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adjList.begin(); i != adjList.end(); i++)
        {
            //we need to add here condition about clocking cell
            if (!count(visited.begin(), visited.end(), i))
            {
                visited.push_back(*i);
                queue.push_back(*i);
            }
            if (s.isGoalState(*i)) {
                //continue create the solution
            }
        }
    }
}

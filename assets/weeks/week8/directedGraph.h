#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class directedGraph
{
private:
    class vertex
    {
    public:
        string name;
        vertex* breadcrumb;
        vector<vertex*> neighbors;

        vertex(string x)
        {
            name = x;
            breadcrumb = nullptr;
        }
    };

    // Find a vertex by name. Assumes it was already added.
    unordered_map<string, vertex*> vertexMap;

public:
    void addVertex(string x)
    {
        // Do not replace an existing vertex and lose its edges.
        if (vertexMap.find(x) == vertexMap.end())
            vertexMap[x] = new vertex(x);
    }

    void addDirectedEdge(string from, string to)
    {
        vertex* cur = vertexMap.at(from);
        vertex* nbr = vertexMap.at(to);
        cur->neighbors.push_back(nbr);
    }

    void printAdjacencyList()
    {
        // entry is an iterator with is essentially a key-value pair in the unordered map
        for (const auto& entry : vertexMap)
        {
            cout << entry.first << ": ";
            for (vertex* neighbor : entry.second->neighbors)
                cout << neighbor->name << " ";
            cout << endl;
        }
    }
    
    vector<string> shortestPath(string from, string to)
    {
        vertex* start = vertexMap.at(from);
        vertex* goal = vertexMap.at(to);
        
        // Queue holds vertices waiting to be explored.
        queue<vertex*> q;
        // visited stops one vertex entering the queue twice.
        unordered_map<string, bool> visited;
        
        // BFS begins at the starting vertex.
        visited[start->name] = true;
        q.push(start);
        
        while (!q.empty())
        {
            // Take the oldest vertex from the queue.
            vertex* cur = q.front();
            q.pop();
            
            // First visit to goal uses the fewest edges.
            if (cur == goal)
                break;
            
            addNeighbors(cur, q, visited);
        }
        
        // An unvisited goal cannot be reached from start.
        if (!visited[goal->name])
            return {};
        
        return backtrack(start, goal);
    }

    void addNeighbors(vertex* cur, queue<vertex*>& q, unordered_map<string, bool>& visited)
    {
        // Add every new neighbor to the back of the queue.
        for (vertex* neighbor : cur->neighbors)
        {
            if (!visited[neighbor->name])
            {
                visited[neighbor->name] = true;
                // Save this vertex to rebuild the path later.
                neighbor->breadcrumb = cur;
                q.push(neighbor);
            }
        }
    }

    vector<string> backtrack(vertex* start, vertex* goal)
    {
        vector<string> path;
        // Walk backward: goal, parent, grandparent, ..., start.
        vertex* cur = goal;
        while(cur != start)
        {
            path.push_back(cur->name);
            cur = cur->breadcrumb;
        }
        path.push_back(start->name);
        
        // It was built backward, so swap matching ends.
        int length = path.size();
        for (int i = 0; i < length / 2; i++)
        {
            int mirror = length - 1 - i;
            swap(path[i], path[mirror]);
        }

        return path;
    }
};
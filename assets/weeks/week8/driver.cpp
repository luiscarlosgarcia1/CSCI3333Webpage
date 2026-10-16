
#include "directedGraph.h"
using namespace std;

void printPath(const vector<string>& path)
{
    if (path.empty())
    {
        cout << "No path exists." << endl;
        return;
    }

    for (int i = 0; i < static_cast<int>(path.size()); ++i)
    {
        if (i > 0)
            cout << " -> ";
        cout << path[i];
    }
    cout << endl;
}

int main()
{
    directedGraph G;

    for (string name : {"A", "B", "C", "D", "E", "F", "G"})
        G.addVertex(name);

    G.addDirectedEdge("A", "B");
    G.addDirectedEdge("A", "C");
    G.addDirectedEdge("A", "D");
    G.addDirectedEdge("B", "E");
    G.addDirectedEdge("C", "D");
    G.addDirectedEdge("D", "F");
    G.addDirectedEdge("E", "F");
    G.addDirectedEdge("E", "G");
    G.addDirectedEdge("F", "G");

    cout << "Adjacency list:\n";
    G.printAdjacencyList();

    cout << "\nBFS shortest path from A to G:\n";
    printPath(G.shortestPath("A", "G"));

    cout << "\nBFS shortest path from C to G:\n";
    printPath(G.shortestPath("C", "G"));

    cout << "\nBFS shortest path from B to D:\n";
    printPath(G.shortestPath("B", "D"));
}

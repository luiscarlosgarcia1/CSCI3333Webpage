
#include <vector>
using namespace std;

int step = 0;
int mid = 0;


void functionA(int n)
{
    for (int i = 1; i < n; i *= 2)
    {
        step++;
    }
    
}


void functionB(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n*n; ++j)
        {
            for (int k = 0; k < j; ++k)
            {
                step++;
            }
        }
    }
}


// Problem:
// Complete recBinarySearch
// Find it's recursive equation
// Build recursive tree
// Use tree to find asymtoptic notation
int recBinarySearch(vector<int> &V, int start, int end, double key)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (key == V[mid])
        return mid;
    else if (key < V[mid])
        return recBinarySearch(V, start, mid - 1, key);
    else if (key > V[mid])
        return recBinarySearch(V, mid + 1, end, key);
}
#include <iostream>
#include <utility>

int step;

// Analyze the big-Oh runtime for each function with respect to n:
void A(int n)
{
    if (n < 10)
        step++;
    else
    {
        for (int i = 0; i < n; i++)
            step++;

        A(n - 2);
    }
}

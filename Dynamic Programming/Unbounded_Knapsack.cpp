#include <bits/stdc++.h>
using namespace std;

// Unbounded Knapsack is another type of knapsack problem where the items can have multiple occurences which was not the case in the 0-1 Knapsack Problem.

int main()
{
    // Over all the logic is same as that of 0-1 Knapsack Problem

    // Inputs are same
    vector<int> weights{1, 2, 3, 4}, values{8, 1, 2, 7};
    int n = weights.size();
    int W = 9;

    // step i: Creating a Table of n+1 rows and W+1 columns
    vector<vector<int>> t(n + 1, vector<int>(W + 1));

    // step ii: Initialization (which is according to the question)
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {

            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    // step iii: Evaluate the other sub problem
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (weights[i - 1] <= j)
            {                                                                         
                // here is the minor difference that we have in Unbounded Knapsack
                t[i][j] = max(values[i - 1] + t[i][j - weights[i - 1]], t[i - 1][j]); 
                
                // here we wrote t[i] insted of t[i-1] because when we included the value then we can include it multiple times so we will not reduce the array and start from that element only
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return 0;
}
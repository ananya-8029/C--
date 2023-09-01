#include <bits/stdc++.h>
using namespace std;

// Problem Statement: We have given an array and we have to return a bool output whether the array can be partitioned in a way that both the subsets sum is equal
// This problem has similarity with the SUBSET_SUM problem.

bool isPresent(vector<int> &arr, int sum)
{
    int n = arr.size();

    vector<vector<bool>> t(n + 1, vector<bool>(sum + 1));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = false;
            }
            if (j == 0)
            {
                t[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {

            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{
    // Inputs
    vector<int> arr{1, 5, 11, 5};

    int sum = 0;
    for (int i : arr)
    {
        sum += i;
    }

    // If the sum of the array is odd then it is never possible to partition the array in such a way that it has equal sum
    if (sum % 2 != 0)
    {
        cout << "There is no possible partition possible.";
    }
    else
    {
        // If sum is even then also there is a possibility whether it can be partitioned or not.
        // If sum/2 is present in the subset then it is evident that the array can be partitioned into 2 subsets

        int s = sum / 2;
        // We can find whether there is any subset that sums to s or not. => SUBSET_SUM Problem
        if (isPresent(arr, s))
            cout << "Partition is possible.";
        else
            cout << "Partition is not possible.";
    }

    return 0;
}
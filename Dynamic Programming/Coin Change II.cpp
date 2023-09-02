#include <bits/stdc++.h>
using namespace std;

// Problem statement: We have given an array of coins and a sum. We need to find the minimum number of coins used to get the desired sum.

// This problem has an exception

int main()
{
    // Inputs
    vector<int> coins{3, 5, 2};
    int sum = 4;

    // step i: Create a table of n+1 columns and sum+1 rows
    int n = coins.size();
    vector<vector<int>> t(n + 1, vector<int>(sum + 1));

    // step ii: Initialization
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {

            // for 0th row we initialize it with infinite i.e. we need infinite coins to make the sum equal to the given sum
            t[0][j] = INT_MAX - 1;
            // for 0th column we initialize it with 0 i.e. we need no coin inorder to have sum equal to 0
            t[i][0] = 0;
        }
    }

    // Here's the exception
    for (int i = 1; i < sum + 1; i++)
    {

        // we have to also fill the 1th row of the table
        // The below code is checking whether the first coin can be used to form the given sum or not
        if (i % coins[0] == 0)
        { // This means that coin can be used to aquire given sum
            t[1][i] = i / coins[0];
        }
        else
        { // This means that we can not use coin to get the desired sum then we will initialise it with infinite value
            t[1][i] = INT_MAX - 1;
        }
    }

    //step iii: Now evaluate the rest sub problems 
    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){

            if(coins[i-1]<=j)
                t[i][j]=min(t[i][j-coins[i-1]]+1, t[i-1][j]);
            else
                t[i][j]=t[i-1][j];
        }

    }

    cout<<t[n][sum];

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long maximumSumSubarray(int K, vector<int> &Arr, int N)
    {

        int w_start = 0;
        int w_end = 0;
        long sum = 0;
        long ans = 0;
        while (w_end < N)
        {
            // addition
            sum += Arr[w_end];

            // window hit
            if (w_end - w_start + 1 == K)
            {
                // comparison
                ans = max(ans, sum);
                // subtraction
                sum -= Arr[w_start];
                w_start++;
            }
            w_end++;
        }
        return ans;
    }
};

int main()
{
    int n,k;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter a number: ";
    cin>>k;

    cout<<"Enter elements of the array:"<<endl;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }

    Solution ob;
    cout<<ob.maximumSumSubarray(k,nums,n);

    return 0;
}
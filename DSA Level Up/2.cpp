//Time complexity - O(n)
//Space complexity - O(1)
#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> arr)
{
    int n = arr.size();

    int maximumSoFar = INT_MIN, maximumEndingHere = 0;

    for (int i = 0; i < n; i++)
    {
        maximumEndingHere += arr[i];

        if (maximumEndingHere > maximumSoFar)    maximumSoFar = maximumEndingHere;
        if (maximumEndingHere < 0)   maximumEndingHere = 0;
    }

    if (maximumSoFar < 0)    return 0;
    return maximumSoFar;
}
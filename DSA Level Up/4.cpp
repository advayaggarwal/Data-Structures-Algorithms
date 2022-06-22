#include<bits/stdc++.h>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr) {

    //Create an output Array
    int n = arr.size();
    vector<int> output(n, 1);

    //update the output array and return
    //complete the code
    int leftProduct = 1, rightProduct = 1;

    for (int i = 0; i < n; i++)
    {
        output[i] *= leftProduct;
        leftProduct *= arr[i];

        output[n - i - 1] *= rightProduct;
        rightProduct *= arr[n - i - 1];
    }

    return output;
}
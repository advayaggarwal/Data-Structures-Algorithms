#include<bits/stdc++.h>
using namespace std;

bool compare(int &a, int &b)
{
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string concatenate(vector<int> numbers)
{
    sort(numbers.begin(), numbers.end(), compare);

    string res;
    for (int i = 0; i < numbers.size(); i++)
    {
        res += to_string(numbers[i]);
    }

    return res;
}
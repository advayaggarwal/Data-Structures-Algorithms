#include<bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(const string &str)
{
    string output;
    int n = str.size();
    for (int i = 0; i < n; )
    {
        int count = 1;
        char c = str[i];
        int j = i + 1;
        while (j < n && str[j] == str[i])
        {
            count++;
            j++;
        }

        i = j;
        output += c + to_string(count);
    }

    return output.size() < n ? output : str;
}
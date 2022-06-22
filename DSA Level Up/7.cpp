#include<bits/stdc++.h>
using namespace std;

string convert_to_digital_time(int minutes)
{
    string hr = to_string(minutes / 60);
    string mn = to_string(minutes % 60);
    if (mn.size() <= 1)  mn = '0' + mn;

    return hr + ":" + mn;
}
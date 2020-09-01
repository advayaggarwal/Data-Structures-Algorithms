/*
    AUTHOR:         ADVAY AGGARWAL
    INSTITUTION:    IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod     1000000007 //1e9+7  ans%mod
#define ll  long long
#define test_cases(x)   int x; cin>>x; while(x--)

void starter()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("input.txt", "r", stdin);
    //for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    starter();
    test_cases(t)
    {
        int n, i;
        int k;
        cin >> n >> k;
        int p[n];
        vector<int>multiples;
        for (i = 0; i < n; i++)
        {
            cin >> p[i];
            if (k % p[i] == 0)   multiples.push_back(i);
        }
        if (multiples.size() == 0) cout << -1 << endl;
        else
        {
            for (i = 0; i < multiples.size(); i++)
            {
                multiples[i] = k / p[multiples[i]];
            }
            sort(multiples.begin(), multiples.end());
            if (multiples[0] != 0)    cout << k / multiples[0] << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}
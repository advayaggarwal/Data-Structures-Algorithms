/*
    AUTHOR:         ADVAY AGGARWAL
    INSTITUTION:    IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod     1000000007 //1e9+7  ans%mod
#define ll  long long
#define test_cases(x)   int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"

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

bool comparator(pair<int, int>a, pair<int, int>b)
{
    return a.second > b.second;
}

int main()
{
    starter();
    test_cases(t)
    {
        int n, k, x, y;
        cin >> n >> k >> x >> y;
        k %= 4;
        vector<pair<int, int>> points;
        if (x == y)
        {
            cout << n << " " << n << endl;
            continue;
        }
        else if (x > y)
        {
            //points.push_back(make_pair(x-y,0));
            points.push_back(make_pair(0, x - y));
            points.push_back(make_pair(n, y + n - x));
            points.push_back(make_pair(y + n - x, n));
            sort(points.begin(), points.end(), greater<>());
        }
        else if (y > x)
        {
            points.push_back(make_pair(y - x, 0));
            //points.push_back(make_pair(0,y-x));
            points.push_back(make_pair(n, x + n - y));
            points.push_back(make_pair(x + n - y, n));
            sort(points.begin(), points.end(), comparator);
        }
        if (k == 0)
        {
            if (x > y) cout << x - y << " " << 0 << endl;
            else cout << 0 << " " << y - x << endl;
            continue;
        }
        else
        {
            cout << points[k - 1].first << " " << points[k - 1].second << endl;
        }
    }
    return 0;
}
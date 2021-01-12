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

int permutations[100000];

void set_permutations(int permutations[], int n)
{
    int i;
    for (i = 0; i < n; i++)  permutations[i] = i + 1;
    permutations[0] = 2, permutations[1] = 3, permutations[2] = 1, permutations[3] = 5, permutations[4] = 4;
    for (i = 5; i < n; i++)
    {
        if (!((i + 1)&i))
        {
            int temp = permutations[i];
            permutations[i] = permutations[i + 1];
            permutations[i + 1] = temp;
        }
    }
}

int main()
{
    starter();
    set_permutations(permutations, 100000);
    test_cases(t)
    {
        int n;
        cin >> n;
        if (n == 1)    cout << n << endl;
        else if (!(n & (n - 1)))  cout << -1 << endl;
        else
        {
            for (int i = 0; i < n; i++)  cout << permutations[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
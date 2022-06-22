#include<bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n)
{
	return n > 0 && (n & (n - 1)) == 0 && ((n & 1431655765) == n);
}
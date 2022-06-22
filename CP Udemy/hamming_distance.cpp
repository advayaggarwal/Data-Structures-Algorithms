//Hamming distance is equal to number of set bits in x^y (ith bit will be 1 if ith bit differs in x and y)
#include<bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y)
{
	int xr = x ^ y;
	return __builtin_popcount(xr);
}
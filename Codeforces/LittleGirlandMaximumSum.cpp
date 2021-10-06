#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void file_i_o() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	file_i_o();
	int n, q;
	cin >> n >> q;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> v(n, 0);
	for (int i = 0; i < q; i++) {
		int q1, q2;
		cin >> q1 >> q2;
		v[q1 - 1]++;
		if (q2 < n) v[q2]--;
	}
	for (int i = 1; i < n; i++) v[i] += v[i - 1];
	sort(a, a + n);
	sort(v.begin(), v.end());

	ll sol = 0;
	for (int i = 0; i < n; i++) {
		sol += a[i] * 1LL * v[i] ;
	}
	cout << sol;

	return 0;
}
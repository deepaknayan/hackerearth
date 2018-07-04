#include <bits/stdc++.h>

using namespace std;

int main () {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);			// for getting input from input.txt
    freopen("output.txt", "w", stdout);			// for writing output to output.txt
	#endif
	int n, q;
	cin >> n >> q;

	int store[n], query[q][3];
	for (int i = 0; i < n; ++i)
		cin >> store[i];
	for (int i = 0; i < q; ++i)
		cin >> query[i][0] >> query[i][1] >> query[i][2];

	for (int i = 0; i < q; ++i) {
		if (query[i][0] == 1)
			store[query[i][1]] = query[i][2];
		else {
			long long sum = 0;
			if ((query[i][1] < 0) || (query[i][2] > n))
				cout << -1 << endl;
			else {
				for (int j = query[i][1]; j <= query[i][2]; ++j)
					sum += store[j];
			}
			cout << sum << endl;
		}
	}
	
	return 0;
}
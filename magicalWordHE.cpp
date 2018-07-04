#include <bits/stdc++.h>

using namespace std;

vector <int> prime;

int customSearch(int elem) {
	int mid = 0;
	for (mid = 0; mid < prime.size(); ++mid) {
		if (prime[mid] > elem)
			break;
	}
	return mid;
}

int main () {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);			// for getting input from input.txt
    freopen("output.txt", "w", stdout);			// for writing output to output.txt
	#endif

	prime.push_back(2);

	for (int i = 3; i < 130; i += 2) {
		bool isPrime = true;
		for (int j : prime) {
			if (sqrt(j) > i)
				break;
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) 
			prime.push_back(i);
	}

	map < int, char > store;
	for (int i = 0; i < 68; ++i)
		store[i] = 'C';
	for (int i = 113; i < 256; ++i)
		store[i] = 'q';
	for (int i = 68; i < 113; ++i) {
		if (binary_search(prime.begin(), prime.end(), i))
			store[i] = char(i);
		else {
			int j = customSearch(i);
			char primeCh = (prime[j] - i) >= (i - prime[j - 1]) ? prime[j - 1] : prime[j];
			store[i] = primeCh;
		}
	}

	int tc, n;	string s, res;
	cin >> tc;

	while (tc--) {
		cin >> n >> s;
		res = "";
		for (unsigned i = 0; i < s.length(); ++i) {
			res += store[int(s[i])];
		}
		cout << res << endl;
	}
	
	return 0;
}

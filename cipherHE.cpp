#include <bits/stdc++.h>

using namespace std;

int main () {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);			// for getting input from input.txt
    freopen("output.txt", "w", stdout);			// for writing output to output.txt
	#endif

	string s, res = ""; int k;
	cin >> s >> k;

	for (unsigned i = 0; i < s.length(); ++i) {
		char ch = s[i];
		if (isalnum(ch)) {
			if (isdigit(ch)) {
				if ((ch + k % 10) > '9')
					ch = '0' - ('9' - ch) + (k % 10 - 1);
				else
					ch += k % 10;
			}
			else if (islower(ch)) {
				if ((ch + k % 26) > 'z')
					ch = 'a' - ('z' - ch) + (k % 26 - 1);
				else
					ch += k % 26;
			}
			else {
				if ((ch + k % 26) > 'Z')
					ch = 'A' - ('Z' - ch) + (k % 26 - 1);
				else
					ch += k % 26;
			}
		}
		res += ch;
	}
	cout << res << endl;

	return 0;
}

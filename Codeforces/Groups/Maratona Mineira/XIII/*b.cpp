#include <bits/stdc++.h>
using namespace std;
 
void computeJump (int st, vector <int> & memo, string & s, int n) {
 
	int blockSize = 0;
	for (int i = 0; i + st < memo.size(); ++i) {
		if (s[st + i] == 'x') {
			++blockSize;
		} else {
			break;
		}
	}
 
	int ans = 0x3F3F3F3F;
	int firstHole = st + blockSize;
 
	if (firstHole >= n) {
		ans = 0;
	} else {
		for (int i = 0; i < blockSize; ++i) {
			if (s[i + firstHole] == 'x') {
				ans = min (ans, 1 + memo[i + firstHole]);
			}
 
			if (i + firstHole == n) break;
		}
	}
 
 
	for (int i = 0; i < blockSize; ++i) {
		memo[st + i] = ans;
	}
 
}
 
void solveTC () {
	int n;
	cin >> n;
 
	string s;
	cin >> s;
 
	vector <int> memo (n + 1);
	memo[n] = 0;
	memo[n - 1] = 0;
 
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == 'x' && (i == 0 || s[i - 1] == '.')) {
			computeJump (i, memo, s, n);
		}
	}
 
	cout << ((memo[0] > n) ? -1 : memo[0]) << '\n';
}
 
int main () {
 
	ios :: sync_with_stdio (false); cin.tie (0);
 
	int tc;
	cin >> tc;
 
	while (tc--) {
		solveTC ();
	}
 
	return 0;
}
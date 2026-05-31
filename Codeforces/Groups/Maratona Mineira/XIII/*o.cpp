#include <bits/stdc++.h>
using namespace std;
 
long long MOD = 1e9 + 7;
 
int main () {
 
	ios :: sync_with_stdio (false); cin.tie (0);
 
	int n;
	cin >> n;
 
	long long currSum = 0;
	long long currMul = 1;
	for (int i = 0; i < n; ++i) {
		string op; long long x;
		cin >> op >> x;
 
		if (op[0] == '+') {
			currSum += x;
			currSum %= MOD;
		} else if (op[0] == '*') {
			currMul *= x;
			currSum *= x;
 
			currMul %= MOD;
			currSum %= MOD;
		} else {
 
			long long ans = x * currMul + currSum;
			ans %= MOD;
 
			cout << ans << '\n';
		}
	}
 
	return 0;
}
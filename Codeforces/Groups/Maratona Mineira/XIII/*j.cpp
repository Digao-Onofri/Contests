#include <bits/stdc++.h>
using namespace std;
 
const int MAXV = 1123456;
 
int freq[MAXV];
int ans[MAXV];
int main () {
 
	ios :: sync_with_stdio (false); cin.tie (0);
 
	int n;
	cin >> n;
 
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
 
		freq[x]++;
	}
 
	for (int i = 2; i < MAXV; ++i) {
		for (int j = i; j < MAXV; j += i) {
			ans[i] += freq[j];
		}
	}
 
	int maxAns = 0;
	int who = 0;
	for (int i = 2; i < MAXV; ++i) {
		if (ans[i] > maxAns) {
			who = i;
			maxAns = ans[i];
		}
	}
 
	cout << who << endl;
}
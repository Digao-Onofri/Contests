#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
		
	vector<pair<int, pair<int, int>>> num;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		num.push_back({a, {-b, -(i+1)}});
	}
	
	sort(num.rbegin(), num.rend());
	
	cout << -num[0].second.second << endl;
		
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	
	long long int l, r, mid, res;
	string s;
	
	l = 1;
	r = 1000000000;
	for(int i = 0; i < 30; i++){
		mid = (l+r)/2;
		cout << "? " << mid << endl;
		cin >> s;
		if(s == "QUENTE"){
			l = mid + 1;
		} else{
			r = mid;
			res = mid;
		}
	}
	cout << "! " << res << endl;

	return 0;
}
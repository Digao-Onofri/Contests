#include <bits/stdc++.h>
using namespace std;

int main(){
	long long sum, last;
	int sub, v;
	multiset<int> values;
	bool first = false;
	
	cin >> sub;
	
	for(int i = 0; i < sub; i++){
		cin >> v;
		values.insert(v);
	}
		
	sum = 0;
	for(auto jt : values){
		if(first){
			sum += last + jt;
			last += jt;
		} else{
			sum = last = jt;
			first = true;
		}
	}
	
	cout << sum << endl;

	return 0;
}
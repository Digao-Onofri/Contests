#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a, b, c;
	
	cin >> a >> b >> c;
	
	if(a > b){
		cout << "Time Limit Exceeded" << endl;
	} else if(c){
		cout << "Accepted" << endl;
	} else{
		cout << "Wrong Answer" << endl;
	}
		
	return 0;
}
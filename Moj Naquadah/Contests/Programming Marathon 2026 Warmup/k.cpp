#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	
	cin >> a >> b;
	
	if((a == -1) && (a == b)){
		cout << "NINGUEM" << endl;
	} else if((a == -1) || ((a > b) && (b != -1))){
		cout << "B" << endl;
	} else if ((b == -1) || (b > a)){
		cout << "A" << endl;
	} else{
		cout << "EMPATE" << endl;
	}

	return 0;
}
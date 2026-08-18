#include <bits/stdc++.h>
using namespace std;

int main(){
	map<int, int> pen;
	int n, k, p, m, v, sum, sol;
	set<int> solved;
	
	cin >> n >> k;
	sum = sol = 0;
	while(n--){
		cin >> p >> m >> v;
		
		if(v && (solved.find(p) == solved.end())){
			sol++;
			solved.insert(p);
			sum += m + 20 * pen[p];
		} else{
			pen[p]++;
		}
	}
	
	cout << sol << " " << sum << endl;
	
	return 0;
}
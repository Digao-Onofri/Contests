#include <bits/stdc++.h>
using namespace std;

vector<long long> values;
long long solve(int n){
    vector<long long> sum(n + 1);

    sum[0] = 0;
    sum[1] = values[0];
    for(int i = 1; i < n; i++){
        if((values[i] & 0x1) == (values[i - 1] & 0x1)){
            sum[i + 1] = sum[i] + values[i];
        } else{
            sum[i + 1] = max(sum[i], values[i] + sum[i - 1]);
        }
    }

    return sum[n];
}

int main(){
    int n;
    long long ol, sum;
    cin >> n;

    sum = 0;
    for(int i = 0; i < n;i++){
        long long v;
        cin >> v;
        sum += v;
        values.push_back(v);
    }

    long long ed = solve(n);
    ol = sum - ed;

    if(ol == ed){
        cout << "Empate" << endl;
    } else if(ed * 2 > sum){
        cout << "Edmilson" << endl;
    } else{
        cout << "Olmes" << endl;
    }

    return 0;
}
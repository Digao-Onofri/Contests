/*
    Name: Divisible Permutation
    Link: https://codeforces.com/contest/2188/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, p[110];
    int size, i;
    
    set<int> values;

    cin >> cases;
    while(cases--){
        cin >> size;
        memset(p, 0, sizeof(p));
        cout << ++p[0];
        for(i = 1; i <= size; i++){
            cout << " " << ++p[i];
        }
    }
    
    return 0;
}
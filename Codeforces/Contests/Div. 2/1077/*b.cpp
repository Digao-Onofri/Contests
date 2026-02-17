/*
    Name: Seats
    Link: https://codeforces.com/contest/2188/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, size, add, i;
    char bin[100010];

    cin >> cases;
    while(cases--){
        cin >> size;
        add = 0;
        for(i = 0; i < size; i++){
            cin >> bin[i];
            if(bin[i] == '1'){
                add++; 
            }
        }

        for(i = 0; i < size; i++){
            if(bin[i] == '0' && (bin[(i + 2) % size] == '0' && bin[(i + 3) % size] == '0') && (bin[(i - 1) % size] == '0' && bin[(i + 1) % size] == '0')){
                bin[i] = '1';
                add++;
            }
        }

        cout << bin << endl;

        if(size == 1){
            cout << 1 << endl;
        } else{
            cout << add << endl;
        }
    }

    return 0;
}
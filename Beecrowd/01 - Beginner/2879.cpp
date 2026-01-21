/*
    Name: Desvendando Monty Hall
    Link: https://judge.beecrowd.com/en/problems/view/2863
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    int value, sum = 0;

    cin >> cases;
    while(cases--){
        cin >> value;
        if(value > 1){
            sum++;
        }
    }

    cout << sum << endl;

    return 0;
}
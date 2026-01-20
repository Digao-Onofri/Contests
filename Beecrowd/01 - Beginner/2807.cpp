/*
    Name: Iccanobif
    Link: https://judge.beecrowd.com/en/problems/view/2807
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int size, i, ic[44];

    cin >> size;
    ic[size] = 1;
    ic[size - 1] = 1;
    for(i = size - 2; i > 0; i--){
        ic[i] = ic[i + 1] + ic[i + 2];
    }

    for(i = 1; i <= size; i++){
        if(i == 1){
            cout << ic[i];
        } else{
            cout << " " << ic[i];
        }
    }
    cout << endl;

    return 0;
}
/*
    Name: Se liga na cifra
    Link: https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/C
    Tinha errado por causa de long long
*/

#include <bits/stdc++.h>
using namespace std;

vector <long long int> vet, memo;

long long int calc(int size){
    int i;

    memo.push_back(vet[0]);
    memo.push_back(max(vet[0], vet[1]));
    for(i = 2; i < size; i++){
        memo.push_back(max(memo[i - 1], vet[i] + memo[i - 2]));
    }

    return memo[size - 1];
}

int main(){
    long long int value;
    int size, i;
    
    cin >> size;
    for(i = 0; i < size; i++){
        cin >> value;
        vet.push_back(value);
    }

    cout << calc(size) << endl;

    return 0;
}
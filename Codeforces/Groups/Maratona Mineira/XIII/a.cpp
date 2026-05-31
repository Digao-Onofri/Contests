#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, vet[1001];
    cin >> a;

    vet[1] = 3;
    for(int i = 2; i <= 1000; i++){
        vet[i] = vet[i - 1] + 1;
    }
    
    int sum = 0;
    for(int i = 1; i <= a; i++){
        sum += vet[i];
    }

    cout << sum << endl;

    return 0;
}
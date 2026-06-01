#include <bits/stdc++.h>
using namespace std;

int main(){
    long long value, pot, count;
    int n;

    cin >> n;

    while(n--){
        cin >> value;
        count = 0;
        pot = 5;
        while(pot <= value){
            count += value / pot;
            pot *= 5;
        }

        cout << count << endl;
    }

    return 0;
}
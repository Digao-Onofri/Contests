/*
    Name: The Two Towers
    Link: https://judge.beecrowd.com/en/problems/view/2950
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int distance, d1, d2;
    
    cin >> distance >> d1 >> d2;
    cout << fixed << setprecision(2) << (double) distance / (d1 + d2) << endl;

    return 0;
}
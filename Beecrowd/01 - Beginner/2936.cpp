/*
    Name: How Much Cassava?
    Link: https://judge.beecrowd.com/en/problems/view/2936
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, e;
    int sum = 225;

    cin >> a >> b >> c >> d >> e;

    sum += a * 300;
    sum += b * 1500;
    sum += c * 600;
    sum += d * 1000;
    sum += e * 150;

    cout << sum << endl;

    return 0;
}
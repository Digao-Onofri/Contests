/*
    Name: Hour for a Run
    Link: https://judge.beecrowd.com/en/problems/view/2968
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int laps, signs;

    cin >> laps >> signs;

    cout << static_cast<int> (ceil((laps * signs) * 0.1));
    cout << " " << static_cast<int> (ceil((laps * signs) * 0.2));
    cout << " " << static_cast<int> (ceil((laps * signs) * 0.3));
    cout << " " << static_cast<int> (ceil((laps * signs) * 0.4));
    cout << " " << static_cast<int> (ceil((laps * signs) * 0.5));
    cout << " " << static_cast<int> (ceil((laps * signs) * 0.6));
    cout << " " << static_cast<int> (ceil((laps * signs) * 0.7));
    cout << " " << static_cast<int> (ceil((laps * signs) * 0.8));
    cout << " " << static_cast<int> (ceil((laps * signs) * 0.9)) << endl;

    return 0;
}
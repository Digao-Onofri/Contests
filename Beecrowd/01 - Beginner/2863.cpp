/*
    Name: Umil Bolt
    Link: https://judge.beecrowd.com/en/problems/view/2863
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    float lowest, value;
    bool first;

    while(cin >> cases){
        first = true;
        while(cases--){
            cin >> value;
            if(first){
                lowest = value;
                first = false;
            } 

            if(lowest >= value){
                lowest = value;
            }
        }
        cout << fixed << setprecision(2) << lowest << endl;
    }

    return 0;
}
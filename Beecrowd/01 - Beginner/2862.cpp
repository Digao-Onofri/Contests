/*
    Name: Insect!
    Link: https://judge.beecrowd.com/en/problems/view/2862
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    int energy;

    cin >> cases;

    while(cases--){
        cin >> energy;

        if(energy <= 8000){
            cout << "Inseto!" << endl;
        } else{
            cout << "Mais de 8000!" << endl;
        }
    }

    return 0;
}
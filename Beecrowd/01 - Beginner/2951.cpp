/*
    Name: The Return of The King
    Link: https://judge.beecrowd.com/en/problems/view/2951
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> message;
    int runes, golem, amount, worth;
    string str;

    cin >> runes >> golem;
    while(runes--){
        cin >> str >> amount;
        message[str] = amount;
    }

    cin >> amount;
    worth = 0;
    while(amount--){
        cin >> str;
        worth += message[str];
    }

    if(worth >= golem){
        cout << worth << endl << "You shall pass!" << endl;
    } else{
        cout << worth << endl << "My precioooous" << endl;
    }

    return 0;
}
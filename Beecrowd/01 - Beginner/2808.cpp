/*
    Name: Knights Again
    Link: https://judge.beecrowd.com/en/problems/view/2808
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int i, j;
    char posi, posj;


    cin >> posi >> i >> posj >> j;

    if(((int) posj == posi + 2 && j == i + 1) || ((int) posj == posi + 1 && j == i + 2)){
        cout << "VALIDO" << endl;
        return 0;
    }

    if(((int) posj == posi + 2 && j == i - 1) || ((int) posj == posi + 1 && j == i - 2)){
        cout << "VALIDO" << endl;
        return 0;
    }

    if(((int) posj == posi - 1 && j == i + 2) || ((int) posj == posi - 2 && j == i + 1)){
        cout << "VALIDO" << endl;
        return 0;
    }

    if(((int) posj == posi - 1 && j == i - 2) || ((int) posj == posi - 2 && j == i - 1)){
        cout << "VALIDO" << endl;
        return 0;
    }

    cout << "INVALIDO" << endl;

    return 0;
}
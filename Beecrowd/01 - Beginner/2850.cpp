/*
    Name: Polyglot Parrot
    Link: https://judge.beecrowd.com/en/problems/view/2850
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string command;

    while(getline(cin, command)){
        if(command == "esquerda"){
            cout << "ingles" << endl;
        } else if(command == "direita"){
            cout << "frances" << endl;
        } else if(command == "nenhuma"){
            cout << "portugues" << endl;
        } else{
            cout << "caiu" << endl;
        }
    }

    return 0;
}
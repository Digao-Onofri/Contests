/*
    Name: Final Thesis of Christmas Depression
    Link: https://judge.beecrowd.com/en/problems/view/2863
    Wrong answer(20%)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int deliver, deadline;

    if(cin >> deliver >> deadline){
        if(abs(deliver - deadline) >= 3){
                cout << "Muito bem! Apresenta antes do Natal!" << endl;
        } else{
            cout << "Parece o trabalho do meu filho!" << endl;
            if(deliver + 2 < 24){
                cout << "TCC Apresentado!" << endl;
            } else{
                cout << "Fail! Entao eh nataaaaal!" << endl;
            }
        }
    } else{
        cout << "Eu odeio a professora!" << endl;
    }

    return 0;
}
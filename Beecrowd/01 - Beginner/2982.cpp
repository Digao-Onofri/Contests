/*
    Name: The Strike Stops or Continues?
    Link: https://judge.beecrowd.com/en/problems/view/2982
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, value, expenses, funds;
    char c;

    cin >> cases;
    expenses = funds = 0;
    while(cases--){
        cin >> c >> value;
        if(c == 'G'){
            expenses += value;
        } else{
            funds += value;
        }
    }

    cout << (funds >= expenses ? "A greve vai parar." : "NAO VAI TER CORTE, VAI TER LUTA!") << endl;

    return 0;
}
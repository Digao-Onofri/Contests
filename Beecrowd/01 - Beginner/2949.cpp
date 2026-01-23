/*
    Name: The Fellowship of the Ring
    Link: https://judge.beecrowd.com/en/problems/view/2949
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, ho, hu;
    int el, dw, ma;
    string name, type;

    cin >> cases;
    ho = hu = el = dw = ma = 0;
    while(cases--){
        cin >> name >> type;
        if(type == "A"){
            dw++;
        } else if(type == "E"){
            el++;
        } else if(type == "H"){
            hu++;
        } else if(type == "M"){
            ma++;
        } else{
            ho++;
        }
    }

    cout << ho << " Hobbit(s)" << endl;
    cout << hu << " Humano(s)" << endl;
    cout << el << " Elfo(s)" << endl;
    cout << dw << " Anao(oes)" << endl;
    cout << ma << " Mago(s)" << endl;

    return 0;
}
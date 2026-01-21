/*
    Name: Lexical
    Link: https://judge.beecrowd.com/en/problems/view/2826
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    string::iterator it, jt;

    cin >> a >> b;

    it = a.begin();
    jt = b.begin();

    while(*it == *jt){
        it++;
        jt++;
    }

    if(*it <= *jt){
        cout << a << endl << b << endl;
    } else{
        cout << b << endl << a << endl;
    }

    return 0;
}
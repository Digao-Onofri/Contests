#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;

    cin >> a >> b;

    if((a > 13 || b > 13) || (a == b && (a < 13 || b < 13))){
        cout << "DATA SEGURA" << endl;
    } else {
        cout << "DATA INCERTA" << endl;
    }

    return 0;
}
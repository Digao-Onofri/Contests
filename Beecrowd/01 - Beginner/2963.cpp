/*
    Name: Buffoon
    Link: https://judge.beecrowd.com/en/problems/view/2963
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int amount, value, carlos;
    bool first = true, elected = true;

    cin >> amount;
    while(amount--){
        cin >> value;
        if(first){
            carlos = value;
            first = false;
        }

        if(carlos < value){
            elected = false;
        }
    }

    cout << (elected ? "S" : "N") << endl;
    
    return 0;
}
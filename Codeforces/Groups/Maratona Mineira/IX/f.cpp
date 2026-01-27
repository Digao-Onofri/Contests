/*
    Name: Caindo de Paraquedas
    Link: https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/F
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int value, d, e, sum, maxdir, maxesq;
    string navegation;
    string::iterator it;
    bool possible = false;

    cin >> value >> navegation;
    sum = d = e = maxdir = maxesq = 0;
    for(it = navegation.begin(); it != navegation.end(); it++){
        if(*it == 'D'){
            sum += value;
            d++;
            e = 0;
            if(maxdir <= sum){
                maxdir = sum;
            }
        } else{
            d = 0;
            e++;
            sum -= value;
            if(maxesq >= sum){
                maxesq = sum;
            }
        }

        if(abs(sum) >= 360 || d * value + e * value >= 360 || d * value >= 360 || e * value >= 360 || maxdir + abs(maxesq) >= 360){
            possible = true;
            break;
        }
    }

    if(possible){
        cout << "S" << endl;
    } else{
        cout << "N" << endl;
    }

    return 0;
}
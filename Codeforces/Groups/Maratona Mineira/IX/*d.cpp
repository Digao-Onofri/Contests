/*
    Name: Crise da Chuva
    Link: https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

int mat[410][410];
 
int main(){
    long long int time;
    int r, c, side, cities;
    int posx, posy;
    bool colapsed = false;

    memset(mat, 0, sizeof(mat));

    cin >> r >> c >> side >> cities;

    while(cities--){
        cin >> posx >> posy >> time;
        mat[posx][posy] = 1;
        if(!colapsed && check(posx, posy, side)){
            cout << time << endl;
            colapsed = true;
        }
    }

    if(!colapsed){
        cout << -1 << endl;
    }

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
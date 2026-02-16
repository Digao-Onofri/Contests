/*
    Name: Crise da Chuva
    Link: https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/D
*/

#include <bits/stdc++.h>
#define n 410
using namespace std;

int mat[n][n], memoc[n][n], memol[n][n];
 
int main(){
    long long int time;
    int r, c, side, cities, value;
    int posx, posy, i, j, l, res;

    memset(mat, 0, sizeof(mat));
    memset(memoc, 0, sizeof(memoc));
    memset(memol, 0, sizeof(memol));

    cin >> r >> c >> side >> cities;

    while(cities--){
        cin >> posx >> posy >> time;
        mat[posx - 1][posy - 1] = time;
    }

    for(i = 0; i < r; i++){
        for(j = 0; j < c + side; j++){
            value = 0;
            for(l = 0; l < side; l++){
                value = max(value, mat[i][j + l]);
            }
            memoc[i][j] = value;
        }
    }

    for(i = 0; i < r + side; i++){
        for(j = 0; j < c + side; j++){
            value = 0;
            for(l = 0; l < side; l++){
                value = max(value, memoc[i + l][j]);
            }
            memol[i][j] = value;
            res = min(res, memol[i][j]);
        }
    }

    if(res == 0){
        cout << -1 << endl;
    } else{
        cout << res << endl;
    }

    return 0;
}
/*
    Name: Bagunça da Madalena
    Link: https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

int mat[410][410];

int check(int posx, int posy, int side){
    int i = 1;
    int lusquare, rusquare, ldsquare, rdsquare; 
    lusquare = rusquare = ldsquare = rdsquare = 0;
    //function just in 2x2 matrix
    while(posx - i >= 1 && posy - i >= 1 && posx + i <= side && posy + i <= side){
        if(mat[posx][posy - i] && mat[posx - i][posy - i] && mat[posx - i][posy]){
            lusquare++;
        }

        if(mat[posx - i][posy] && mat[posx - i][posy + i] && mat[posx][posy + i]){
            rusquare++;
        }

        if(mat[posx][posy - i] && mat[posx + i][posy - i] && mat[posx + 1][posy]){
            ldsquare++;
        }

        if(mat[posx][posy + i] && mat[posx + i][posy + i] && mat[posx + i][posy]){
            rdsquare++;
        }

        if(lusquare == side || rusquare == side || ldsquare == side || rdsquare == side){
            return 1;
        }

        i++;
    }

    return 0;
}
 
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
        if(check(posx, posy, side) && !colapsed){
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
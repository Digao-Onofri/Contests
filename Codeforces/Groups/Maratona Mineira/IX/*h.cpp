/*
    Name: Bagunça da Madalena
    Link: https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/H
    wrong answer on test 5
*/

#include <bits/stdc++.h>
using namespace std;

long long int mat[510][510], l, c;
int maxi, maxj;

int possible(int posi, int posj){
    int pos = 0;

    if((posi >= 0 && posi < l) && (posj - 1 >= 0 && posj - 1 < c)){
        pos++;
    }

    if((posi - 1 >= 0 && posi - 1 < l) && (posj - 1 >= 0 && posj - 1 < c)){
        pos++;
    }

    if((posi - 1 >= 0 && posi - 1 < l) && (posj >= 0 && posj < c)){
        pos++;
    }
    
    if((posi - 1 >= 0 && posi - 1 < l) && (posj + 1 >= 0 && posj + 1 < c)){
        pos++;
    }

    if((posi >= 0 && posi < l) && (posj + 1 >= 0 && posj + 1 < c)){
        pos++;
    }

    if((posi + 1 >= 0 && posi + 1 < l) && (posj + 1 >= 0 && posj + 1 < c)){
        pos++;
    }

    if((posi + 1 >= 0 && posi + 1 < l) && (posj >= 0 && posj < c)){
        pos++;
    }

    if((posi + 1 >= 0 && posi + 1 < l) && (posj - 1 >= 0 && posj - 1 < c)){
        pos++;
    }

    return pos;
}

void add(int posi, int posj, int amount){

    if((posi >= 0 && posi < l) && (posj - 1 >= 0 && posj - 1 < c)){
        mat[posi][posj - 1] += amount;
    }

    if((posi - 1 >= 0 && posi - 1 < l) && (posj - 1 >= 0 && posj - 1 < c)){
        mat[posi - 1][posj - 1] += amount;
    }

    if((posi - 1 >= 0 && posi - 1 < l) && (posj >= 0 && posj < c)){
        mat[posi - 1][posj] += amount;
    }
    
    if((posi - 1 >= 0 && posi - 1 < l) && (posj + 1 >= 0 && posj + 1 < c)){
        mat[posi - 1][posj + 1] += amount;
    }

    if((posi >= 0 && posi < l) && (posj + 1 >= 0 && posj + 1 < c)){
        mat[posi][posj + 1] += amount;
    }

    if((posi + 1 >= 0 && posi + 1 < l) && (posj + 1 >= 0 && posj + 1 < c)){
        mat[posi + 1][posj + 1] += amount;
    }

    if((posi + 1 >= 0 && posi + 1 < l) && (posj >= 0 && posj < c)){
        mat[posi + 1][posj] += amount;
    }

    if((posi + 1 >= 0 && posi + 1 < l) && (posj - 1 >= 0 && posj - 1 < c)){
        mat[posi + 1][posj - 1] += amount;
    }

}

void next(int posi, int posj){
    bool first = true;

    if((posi >= 0 && posi < l) && (posj - 1 >= 0 && posj - 1 < c)){
        if(first){
            maxi = posi;
            maxj = posj - 1;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi][posj - 1]){
                maxi = posi;
                maxj = posj - 1;
            }
        }
    }

    if((posi - 1 >= 0 && posi - 1 < l) && (posj - 1 >= 0 && posj - 1 < c)){
        if(first){
            maxi = posi - 1;
            maxj = posj - 1;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi - 1][posj - 1]){
                maxi = posi - 1;
                maxj = posj - 1;
            }
        }
    }

    if((posi - 1 >= 0 && posi - 1 < l) && (posj >= 0 && posj < c)){
        if(first){
            maxi = posi - 1;
            maxj = posj;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi - 1][posj]){
                maxi = posi - 1;
                maxj = posj;
            }
        }
    }
    
    if((posi - 1 >= 0 && posi - 1 < l) && (posj + 1 >= 0 && posj + 1 < c)){
        if(first){
            maxi = posi - 1;
            maxj = posj + 1;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi - 1][posj + 1]){
                maxi = posi - 1;
                maxj = posj + 1;
            }
        }
    }

    if((posi >= 0 && posi < l) && (posj + 1 >= 0 && posj + 1 < c)){
        if(first){
            maxi = posi;
            maxj = posj + 1;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi][posj + 1]){
                maxi = posi;
                maxj = posj + 1;
            }
        }
    }

    if((posi + 1 >= 0 && posi + 1 < l) && (posj + 1 >= 0 && posj + 1 < c)){       
        if(first){
            maxi = posi + 1;
            maxj = posj + 1;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi + 1][posj + 1]){
                maxi = posi + 1;
                maxj = posj + 1;
            }
        }
    }

    if((posi + 1 >= 0 && posi + 1 < l) && (posj >= 0 && posj < c)){
        if(first){
            maxi = posi + 1;
            maxj = posj;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi + 1][posj]){
                maxi = posi + 1;
                maxj = posj;
            }
        }
    }

    if((posi + 1 >= 0 && posi + 1 < l) && (posj - 1 >= 0 && posj - 1 < c)){
        if(first){
            maxi = posi + 1;
            maxj = posj - 1;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi + 1][posj - 1]){
                maxi = posi + 1;
                maxj = posj - 1;
            }
        }
    }
}

int main(){
    long long int amount;
    int i, j, max;
    int posi, posj, pos;
    int played = 0;

    cin >> l >> c;

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            cin >> mat[i][j];
        }
    }

    //if just one pos is possible don`t pass because of division by zero
    if(l == 1 && c == 1){
        cout << mat[0][0] << endl;
        return 0;
    }

    cin >> posi >> posj;
    posi--;
    posj--;
    //very important to reduce because the input consider first position as 1 1 
    while(played < l + c + 1){
        pos = 0;
        pos = possible(posi, posj);

        amount = mat[posi][posj] / pos; 
        add(posi, posj, amount);
        mat[posi][posj] -= (amount * pos);

        next(posi, posj);
        posi = maxi;
        posj = maxj;
        played++;
    }

    max = mat[0][0];
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(max < mat[i][j]){
                max = mat[i][j];
            }
        }
    }

    cout << max << endl;

    return 0;
}
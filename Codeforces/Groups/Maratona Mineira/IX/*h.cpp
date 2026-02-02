/*
    Name: Se liga na cifra
    Link: https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/H
    nada que eu faço faz com que pegue a posição correta
*/

#include <bits/stdc++.h>
using namespace std;


int mat[510][510], l, c;
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
    int max = 0;

    if((posi >= 0 && posi < l) && (posj - 1 >= 0 && posj - 1 < c)){
        if(first){
            max = mat[posi][posj - 1];
            maxi = posi;
            maxj = posj - 1;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi][posj - 1]){
                if(max != mat[posi][posj - 1]){
                }else{
                    max = mat[posi][posj - 1];
                    maxi = posi;
                    maxj = posj - 1;
                }
            }
        }
    }

    if((posi - 1 >= 0 && posi - 1 < l) && (posj - 1 >= 0 && posj - 1 < c)){
        if(first){
            max = mat[posi - 1][posj - 1];
            maxi = posi - 1;
            maxj = posj - 1;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi - 1][posj - 1]){
                if(max == mat[posi - 1][posj - 1]){
                }else{
                    max = mat[posi - 1][posj - 1];
                    maxi = posi - 1;
                    maxj = posj - 1;
                }
            }
        }
    }

    if((posi - 1 >= 0 && posi - 1 < l) && (posj >= 0 && posj < c)){
        if(first){
            max = mat[posi - 1][posj];
            maxi = posi - 1;
            maxj = posj;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi - 1][posj]){
                if(max == mat[posi - 1][posj]){
                }else{
                    max = mat[posi - 1][posj];
                    maxi = posi - 1;
                    maxj = posj;
                }
            }
        }
    }
    
    if((posi - 1 >= 0 && posi - 1 < l) && (posj + 1 >= 0 && posj + 1 < c)){
        if(first){
            max = mat[posi - 1][posj + 1];
            maxi = posi - 1;
            maxj = posj + 1;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi - 1][posj + 1]){
                if(max == mat[posi - 1][posj + 1]){
                }else{
                    max = mat[posi - 1][posj + 1];
                    maxi = posi - 1;
                    maxj = posj + 1;
                }
            }
        }
    }

    if((posi >= 0 && posi < l) && (posj + 1 >= 0 && posj + 1 < c)){
        if(first){
            max = mat[posi][posj + 1];
            maxi = posi;
            maxj = posj + 1;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi][posj + 1]){
                if(max == mat[posi][posj + 1]){
                }else{
                    max = mat[posi][posj + 1];
                    maxi = posi;
                    maxj = posj + 1;
                }
            }
        }
    }

    if((posi + 1 >= 0 && posi + 1 < l) && (posj + 1 >= 0 && posj + 1 < c)){       
        if(first){
            max = mat[posi + 1][posj + 1];
            maxi = posi + 1;
            maxj = posj + 1;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi + 1][posj + 1]){
                if(max == mat[posi + 1][posj + 1]){
                }else{
                    max = mat[posi + 1][posj + 1];
                    maxi = posi + 1;
                    maxj = posj + 1;
                }
            }
        }
    }

    if((posi + 1 >= 0 && posi + 1 < l) && (posj >= 0 && posj < c)){
        if(first){
            max = mat[posi + 1][posj];
            maxi = posi + 1;
            maxj = posj;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi + 1][posj]){
                if(max == mat[posi + 1][posj]){
                } else{
                    max = mat[posi + 1][posj];
                    maxi = posi + 1;
                    maxj = posj;
                }
            }
        }
    }

    if((posi + 1 >= 0 && posi + 1 < l) && (posj - 1 >= 0 && posj - 1 < c)){
        if(first){
            max = mat[posi + 1][posj - 1];
            maxi = posi + 1;
            maxj = posj - 1;
            first = false;
        } else{
            if(mat[maxi][maxj] < mat[posi + 1][posj - 1]){
                if(max == mat[posi + 1][posj - 1]){
                } else{
                    max = mat[posi + 1][posj - 1];
                    maxi = posi + 1;
                    maxj = posj - 1;
                }
            }
        }
    }

}

int main(){
    int i, j, amount, max;
    int posi, posj, pos;
    int played = 0;

    cin >> l >> c;

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            cin >> mat[i][j];
        }
    }

    cin >> posi >> posj;
    while(played < l + c + 1){
        pos = 0;
        pos = possible(posi, posj);
        cout << pos << endl;

        amount = mat[posi][posj] / pos;
        cout << amount << endl;
        add(posi, posj, amount);
        mat[posi][posj] -= amount;

        next(posi, posj);
        posi = maxi;
        posj = maxj;
        played++;
        cout << posi << " " << posj << endl;
        for(i = 0; i < l; i++){
            for(j = 0; j < c; j++){
                cout << mat[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
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
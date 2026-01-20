/*
    Name: Pyramid
    Link: https://judge.beecrowd.com/en/problems/view/2785
    Wrong answer (70%)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, mat[110][110];
    int i, j, sum, count, value;

    cin >> n;

    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            cin >> mat[i][j];
        }
    }

    sum = 0;
    for(i = 1; i <= n; i++){
        count = i;
        value = 1;
        for(j = n; j >= 1; j--){
            if(count && j == n - value){
                count--;
                value++;
                sum += mat[i][j];
            } else if(i == n){
                sum += mat[i][j];
            }

            if(!count){
                break;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
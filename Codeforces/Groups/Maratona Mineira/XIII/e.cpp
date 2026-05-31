#include <bits/stdc++.h>
using namespace std;

int mat[502][502];

int main(){
    int n, m, t, va, vb, gi, ar, i, j;
    vector<pair<int,int>> g(250010), a(250010);
    set<pair<int,int>> posg, posa;

    memset(mat, 0, sizeof(502));

    cin >> n >> m >> t;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cin >> mat[i][j];
        }
    }

    for(i = 1; i <= t; i++){
        cin >> va >> vb;
        g[i] = {va, vb};
    }

    for(j = 1; j <= t; j++){
        cin >> va >> vb;
        a[j] = {va, vb};
    }

    gi = ar = 0;
    for(i = 1; i <= t; i++){
        posg.clear();
        posa.clear();
        posg.insert({g[i].first, g[i].second});
        posg.insert({g[i].first + 1, g[i].second});
        posg.insert({g[i].first - 1, g[i].second});
        posg.insert({g[i].first, g[i].second + 1});
        posg.insert({g[i].first, g[i].second - 1});
        posa.insert({a[i].first, a[i].second});
        posa.insert({a[i].first + 1, a[i].second});
        posa.insert({a[i].first - 1, a[i].second});
        posa.insert({a[i].first, a[i].second + 1});
        posa.insert({a[i].first, a[i].second - 1});

        for(auto it : posg){
            if(!posa.count(it)){
                gi += mat[it.first][it.second];
                mat[it.first][it.second] = 0;
            }
        }

        for(auto it : posa){
            if(!posg.count(it)){
                ar += mat[it.first][it.second];
                mat[it.first][it.second] = 0;
            }
        }
    }

    cout << gi << " " << ar << endl;

    return 0;
}
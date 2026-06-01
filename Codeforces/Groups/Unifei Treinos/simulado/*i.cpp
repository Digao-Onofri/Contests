#include <bits/stdc++.h>
#define N 27
#define INF 0X3F3F3F3F
using namespace std;

int mat[27][27];
int custo[N];
int pred[N];

void dijkstra(int s){
    memset(custo, 0x3f, sizeof(custo));
    priority_queue<pair<int,int>> q;
    memset(pred, -1, sizeof(pred));
    for(int i = 0; i < N; i++){
        custo[i] = mat[s][i];
        q.push({-custo[i], i});
        if(custo[i] != INF) pred[i] = s;
    }

    while(!q.empty()){
        int a = q.top().second;
        q.pop();

        for(int i = 0; i < N; i++){
            if(pred[a] == -1){
                if(custo[a] + mat[a][i] < custo[i]){
                    custo[i] = custo[a] + mat[a][i];
                    pred[i] = a;
                    q.push({-custo[i], i});
                }
            } else{
                if(custo[a] + mat[a][i] - 1 < custo[i]){
                    custo[i] = custo[a] + mat[a][i] - 1;
                    pred[i] = a;
                    q.push({-custo[i], i});
                }
            }
        }
    }
}

int main(){
    int n, q;
    string a, b;

    cin >> n >> q;
    memset(mat, 0x3f, sizeof(mat));

    while(n--){
        cin >> a;
        if(mat[a[0] - 'a'][a[a.size() - 1] - 'a'] > a.size()){
            mat[a[0] - 'a'][a[a.size() - 1] - 'a'] = a.size();
        }
    }

    while(q--){
        cin >> a >> b;
        
        dijkstra(a[0] - 'a');

        cout << (custo[b[0] - 'a'] != INF ? custo[b[0] - 'a'] : -1) << endl;
    }

    return 0;
}
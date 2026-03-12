/*
    Name: Cut
    Link: https://codeforces.com/group/Ohoz9kAFjS/contest/266572/problem/B
*/

#include <bits/stdc++.h>
#define MAX 110
#define INF 0x3f3f3f3f
using namespace std;

struct edge{
    int to;
    int cap;
};

vector<int> g[MAX];
vector<edge> edges;
vector<edge>::iterator it;

int vis[MAX], anterior[MAX], aresta[MAX];

int BFS(int ini, int fim){ // 1 se tiver caminho, 0 caso nao
    queue<int> fila;
    memset(vis, 0, sizeof(vis));
    fila.push(ini); vis[ini] = 1; anterior[ini] = -1;
    while (!fila.empty()){
        for (auto i: g[fila.front()]){
            int to = edges[i].to;
            int cap = edges[i].cap;
            if(!vis[to] && cap > 0){
                //fila.front() just show
                anterior[to] = fila.front();
                aresta[to] = i;
                fila.push(to);
                vis[to] = 1;            
                if(to == fim){
                    return 1;
                }
            }
        }
        fila.pop();
    }
    return 0;
}

set<int> a, b, arestas;
int minCut(int nodes){
    int count = 0;
    for(int i = 1; i <= nodes; i++){
        if(vis[i]){
            a.insert(i);
        } else{
            b.insert(i);
        }
    }

    for(auto i: a){
        for(auto j: g[i]){
            if(b.find(edges[j].to) != b.end()){
                count++;
                arestas.insert((j / 2) + 1);
                arestas.insert((j / 2) + 1);
            }
        }
    }

    return count;
}

int fordFulkerson(int ini, int fim){
    int u, v;
    int fluxo = 0;
    int bot;
    
    while (BFS(ini, fim)){
        bot = INF;
        for (v = fim; v != ini; v = anterior[v]){
            bot = min(bot, edges[aresta[v]].cap);
        }
        for (v = fim; v != ini; v = anterior[v]){
            u = anterior[v];
            edges[aresta[v]].cap -= bot; 
            edges[aresta[v]^1].cap += bot; 
        }
        fluxo += bot;
    }

    return fluxo;

}

void addEdge(int a, int b, int cap){
    g[a].push_back(edges.size());
    edges.push_back({b, cap});
    g[b].push_back(edges.size());
    edges.push_back({a, cap});
}

int main(){
    int nodes, pipes, a, b, cap;

    cin >> nodes >> pipes;

    while(pipes--){
        cin >> a >> b >> cap;
        addEdge(a, b, cap);
    }

    int mflow = fordFulkerson(1, nodes);
    cout << minCut(nodes) << " " << mflow << endl;

    for(auto i: arestas){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
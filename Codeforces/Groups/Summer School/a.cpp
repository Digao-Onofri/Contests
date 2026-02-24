/*
    Name: Maximum Flow
    Link: https://codeforces.com/group/Ohoz9kAFjS/contest/266572/problem/A
*/

#include <bits/stdc++.h>
#define MAX 110;
using namespace std;


struct edge{
    int to;
    int cap;
    int flow;
}

vector<int> g[MAX];
vector<edge> edges;
vector<edge>::iterator it;

int fordFulkerson(){
    
}

void addEdge(int a, int b, int cap){
    g[a].push_back(edges.size());
    edges.push_back(edge(b, cap));
    g[b].push_back(edges.size());
    edges.push_back(edge(a, cap));
}

int main(){
    int nodes, pipes, a, b, cap;

    cin >> nodes >> pipes;

    while(pipes--){
        cin >> a >> b >> cap;
        addEdge(a, b, cap);
    }

    cout << fordFulkerson() << endl;

    it = edges.begin();
    while(it != edges.end()){
        if(it[0] > it[1]){
            cout << "-" << it[2] << endl;
        } else{
            cout << it[2] << endl;
        }
        it++;
    }

    return 0;
}
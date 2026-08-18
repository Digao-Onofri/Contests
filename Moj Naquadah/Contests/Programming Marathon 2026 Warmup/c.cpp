#include <bits/stdc++.h>
#define INF 10e15
#define N 200010
using namespace std;

vector<pair<long long, long long>> adj[N];
vector<long long> dist(N, INF);
vector<long long> pred(N, -1);
vector<long long> visitado(N, 0);
priority_queue<pair<long long,long long>> q;

void dijkstra(long long s){
	dist[s] = 0;
	q.push({0, s});
	
	while(!q.empty()){
		long long a = q.top().second;
		q.pop();
		
		if(visitado[a]) continue;
		
		visitado[a] = 1;
		
		for(auto u : adj[a]){
			long long b = u.first;
			long long w = u.second;
			
			if(dist[a] + w < dist[b]){
				dist[b] = dist[a] + w;
				pred[b] = a;
				q.push({-dist[b], b});
			}
		}
	}
}

int main(){
	int n, m, u, v, t, i;
	long long sum;
	
	cin >> n >> m;
	
	while(m--){
		cin >> u >> v >> t;

		adj[u].push_back({v, t});
		adj[v].push_back({u, t});	
		
	}
	
	dijkstra(n);
	
	if(dist[1] == INF){
		cout << -1 << endl;
	} else{
		cout << dist[1] << endl;
	}
	
	return 0;
}
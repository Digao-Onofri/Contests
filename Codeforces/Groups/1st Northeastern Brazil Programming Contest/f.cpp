#include <bits/stdc++.h>
#define N 1000010
#define INF 0x3f3f3f3f3f
using namespace std;

typedef struct dots{
    double x;
    double y;
    double r;
}dots;

vector<pair<long long, double>> adj[N];
vector<double> dist(N, INF);
vector<long long> pred(N, -1);
vector<long long> visitado(N, 0);
priority_queue<pair<double,double>> q;
vector<dots> d;

void dijkstra(long long s){
	dist[s] = 0;
	q.push({0, s});
	
	while(!q.empty()){
		long long  a = q.top().second;
		q.pop();
		
		if(visitado[a]) continue;
		
		visitado[a] = 1;
		
		for(auto u : adj[a]){
			long long b = u.first;
			double w = u.second;
			
			if(dist[a] + w < dist[b]){
				dist[b] = dist[a] + w;
				pred[b] = a;
				q.push({-dist[b], b});
			}
		}
	}
}

double dist_dots(double i, double j){
    return max(0.0 , (sqrt(((d[j].x - d[i].x) * (d[j].x - d[i].x)) + ((d[j].y - d[i].y) * (d[j].y - d[i].y))) - (d[i].r + d[j].r)));
}

int main(){
    int n, h, x, y, r, i, j;
    cin >> n >> h;
    dots podouble;

    d.clear();
    for(i = 0; i < n; i++){
        cin >> x >> y >> r;

        podouble.x = x;
        podouble.y = y;
        podouble.r = r;
        d.push_back(podouble);
    }

    for(i = 0; i < n; i++){
        adj[i].push_back({n, max(0.0,(d[i].y - d[i].r))});
        adj[n].push_back({i, max(0.0,(d[i].y - d[i].r))});
        adj[i].push_back({n+1, max(0.0, h - (d[i].y + d[i].r))});
        adj[n+1].push_back({i, max(0.0, h - (d[i].y + d[i].r))});
    }

    adj[n].push_back({n+1, h - 0});
    adj[n+1].push_back({n, h - 0});

    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            adj[i].push_back({j, dist_dots(i, j)});
            adj[j].push_back({i, dist_dots(i, j)});
        }
    }

    dijkstra(n);
    cout << fixed << setprecision(10) << dist[n+1] << endl;
    return 0;
}
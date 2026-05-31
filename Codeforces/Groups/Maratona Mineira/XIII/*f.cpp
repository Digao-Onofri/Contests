#include <bits/stdc++.h>
using namespace std;
 
const int MAXV = 6123;
 
struct Edge {
	int to, cap;
	Edge(int a, int b) { to = a; cap = b; }
};
 
vector<int> adj[MAXV];
vector<Edge> edges;
int ptr[MAXV], dinic_dist[MAXV];
 
inline void addEdge(int u, int v, int cap) {
	adj[u].push_back(edges.size());
	edges.push_back(Edge(v, cap));
	adj[v].push_back(edges.size());
	edges.push_back(Edge(u, 0));
}
 
bool dinic_bfs(int _s, int _t) {
	memset(dinic_dist, -1, sizeof dinic_dist);
	dinic_dist[_s] = 0;
	queue<int> q;
	q.push(_s);
 
	while (!q.empty() && dinic_dist[_t] == -1) {
		int v = q.front();
		q.pop();
		for (int a = 0; a < adj[v].size(); ++a) {
			int ind = adj[v][a];
			int nxt = edges[ind].to;
			if (dinic_dist[nxt] == -1 && edges[ind].cap) {
				dinic_dist[nxt] = dinic_dist[v] + 1;
				q.push(nxt);
			}
		}
	}
 
	return dinic_dist[_t] != -1;
}
 
int dinic_dfs(int v, int _t, int flow) {
	if (v == _t) return flow;
	for (int &a = ptr[v]; a < (int) adj[v].size(); ++a) {
		int ind = adj[v][a];
		int nxt = edges[ind].to;
		if (dinic_dist[nxt] == dinic_dist[v] + 1 && edges[ind].cap) {
			int got = dinic_dfs(nxt, _t, min(flow, edges[ind].cap));
			if (got) {
				edges[ind].cap -= got;
				edges[ind ^ 1].cap += got;
				return got;
			}
		}
	}
 
	return 0;
}
 
int dinic(int _s, int _t) {
	int ret = 0, got;
	while (dinic_bfs(_s, _t)) {
		memset(ptr, 0, sizeof ptr);
		while ((got = dinic_dfs(_s, _t, 0x3F3F3F3F))) ret += got;
	}
 
	return ret;
}
 
inline void dinic_clear() {
	for (int a = 0; a < MAXV; ++a) adj[a].clear();
	edges.clear();
}
 
int getEdgeId (int n, int i, bool in) {
	if (in) {
		return n + 2 * i;
	}
 
	return n + 2 * i + 1;
}
 
int solve (int n, int m, vector <pair <int, int> > vp, int a1, int a2, int b1, int b2) {
	dinic_clear ();
 
	for (int i = 0; i < m; ++i) {
		int x = vp[i].first, y = vp[i].second;
 
		addEdge (getEdgeId (n, i, 1), getEdgeId (n, i, 0), 1);
		
		addEdge (x, getEdgeId (n, i, 1), 1);
		addEdge (y, getEdgeId (n, i, 1), 1);
		addEdge (getEdgeId (n, i, 0), x, 1);
		addEdge (getEdgeId (n, i, 0), y, 1);
	}
 
	int src = n + m + m;
	int sink = src + 1;
	addEdge (src, a1, 2123);
	addEdge (src, b1, 2123);
	addEdge (a2, sink, 2123);
	addEdge (b2, sink, 2123);
 
	return dinic (src, sink);
}
 
int main () {
 
	int n, m;
	cin >> n >> m;
 
	vector <pair <int, int> > vp;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
 
		vp.push_back (make_pair (--x, --y));
	}
 
	int a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	--a1; --a2; --b1; --b2;
 
	cout << min (solve (n, m, vp, a1, a2, b1, b2), solve (n, m, vp, a1, b1, b2, a2)) << endl;
 
	return 0;
}
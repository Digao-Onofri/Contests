#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 11234;
const int MAXM = 30;
const int MAXNODE = MAXN * MAXM + MAXM;
 
vector <int> languages[MAXN];
vector <int> nodeIndex[MAXN];
 
vector <pair <int, int> > g[MAXNODE];
 
int dist[30][MAXNODE];
 
int lazyQuery[30][MAXN];
 
void getDist (int originalLanguage) {
	
	deque <pair <int, int> > q;
	q.push_back (make_pair (originalLanguage, 0));
	dist[originalLanguage][originalLanguage] = 0;
 
	while (!q.empty()) {
		int x = q.front().first;
		int d = q.front().second;
		q.pop_front();
		if (dist[originalLanguage][x] < d) continue;
	
		for (int i = 0; i < g[x].size(); ++i) {
			int y = g[x][i].first;
			int nd = d + g[x][i].second;
 
			if (dist[originalLanguage][y] > nd) {
				dist[originalLanguage][y] = nd;
				
				if (d == nd) {
					q.push_front (make_pair (y, nd));
				} else {
					q.push_back (make_pair (y, nd));
				}
			}
		}
	}
}
 
int main () {
 
	memset (dist, 0x3F, sizeof dist);
 
	ios :: sync_with_stdio (false); cin.tie (0);
 
	int n, m, q;
	cin >> n >> m >> q;
 
	int currNodeIndex = m;
 
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
 
		languages[i] = vector <int> (x);
		nodeIndex[i] = vector <int> (x);
		// cout << i << ": ";
		for (int j = 0; j < x; ++j) {
			cin >> languages[i][j];
			--languages[i][j];
			nodeIndex[i][j] = currNodeIndex++;
			// cout << "(" << languages[i][j] << ", " << nodeIndex[i][j] << ") "; 
		}
		// cout << endl;
	}
 
	for (int i = 0; i < n; ++i) {
		int sz = languages[i].size ();
		for (int j = 0; j < sz; ++j) {
			int nd1 = nodeIndex[i][j];
			g[nd1].push_back (make_pair (languages[i][j], 0));
			g[languages[i][j]].push_back (make_pair (nd1, 0));
			for (int k = j + 1; k < sz; ++k) {
				int nd2 = nodeIndex[i][k];
 
				g[nd1].push_back (make_pair (nd2, 1));
				g[nd2].push_back (make_pair (nd1, 1));
			}
		}
	}
 
	for (int i = 0; i < m; ++i) {
		getDist (i);
	}
 
 
	memset (lazyQuery, 0x3F, sizeof lazyQuery);
 
	for (int lang = 0; lang < m; ++lang) {
		for (int i = 0; i < n; ++i) {
			for (int id : nodeIndex[i]) {
				if (lang == 4 && i == 0) {
					// cout << i << " -> " << id << endl;
				}
				lazyQuery[lang][i] = min (lazyQuery[lang][i], dist[lang][id]);
			}
		}
	}
 
	while (q--) {
		int a, b;
		cin >> a >> b;
		--a; --b;
 
		int ans = 0x3F3F3F3F;
		for (int id : languages[a]) {
			ans = min (ans, lazyQuery[id][b]);
		}
 
		if (ans == 0x3F3F3F3F) {
			cout << -1 << '\n';
		} else {
			cout << ans << '\n';
		}
	}
 
 
	return 0;
}
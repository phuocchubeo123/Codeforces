#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef complex<double> cd;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))

const int maxn = 600;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1ll<<32;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

/*
    Ford-Fulkerson algorithm:
    - Using dfs to find augmented path
    - Complexity O(m * max flow)
    - Quite slow but could be useful when max flow is small

    Edmond-Karp: 
    - Implements FF using bfs
    - Complexity O(V * E^2)

    Remember when reading input, we need to add capacity instead of cin capacity
*/

int n;  // Number of vertices
ll capacity[maxn][maxn];  // Flow capacity
vector<vector<int>> adj(maxn); // Adjacency

ll bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, ll>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(int s, int t) {
    ll flow = 0;
    vector<int> parent(maxn);
    ll new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}


void solve(){
    int m;
        int s, t;
    cin >> n >> m >> s >> t;
    s--; t--;

    // s = 0; t = n-1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            capacity[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        capacity[u][v] += w;
        capacity[v][u] += 0;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << maxflow(s, t) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
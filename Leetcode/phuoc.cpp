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

const int maxn = 500;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;
const int maxedge = 4e4+500;

struct FlowEdge{
    int v, u;
    int cap, flow = 0;
    FlowEdge(){}
    FlowEdge(int u, int v, int cap): v(v), u(u), cap(cap){}
};

struct Dinic{
    FlowEdge edges[maxedge];
    vector<int> adj[maxn];
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t): n(n), s(s), t(t){
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int u, int v, int cap){
        edges[m] = FlowEdge(u, v, cap);
        edges[m+1] = FlowEdge(v, u, 0);
        adj[u].push_back(m);
        adj[v].push_back(m+1);
        m += 2;
    }

    bool bfs(){
        // reconstruct the layered graph
        while (!q.empty()){
            int u = q.front();
            q.pop();
            for (int id: adj[u]){
                if (edges[id].cap - edges[id].flow < 1){
                    continue;
                }
                if (level[edges[id].v] != -1){
                    continue;
                }
                level[edges[id].v] = level[u] + 1;
                q.push(edges[id].v);
            }
        }
        // cout << 5 << "\n";
        // cout.flush();
        return level[t] != -1;
    }

    int dfs(int u, int pushed){
        if (pushed == 0){
            return 0;
        }
        if (u == t){
            return pushed;
        }

        for (int& cid = ptr[u]; cid < (int) adj[u].size(); cid++){
            int id = adj[u][cid];
            int v = edges[id].v;
            if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1){
                continue;
            }
            int tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;
            edges[id].flow += tr;
            edges[id^1].flow -= tr;
            // cout << tr << endl;
            // cout.flush();
            return tr;
        }
        return 0;
    }

    int flow(){
        int f = 0;
        while (true){
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs()){
                break;
            }
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, INF)){
                f += pushed;
            }

            // cout << f << "\n";
            // cout.flush();
        }
        return f;
    }   

    void mincut(){
        ll f = flow();
        queue<int> q;
        q.push(s);
        vector<int> sset(n, 0);
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            sset[cur] = 1;
            // cout << cur << "\n";
            for (int id: adj[cur]){
                // cout << edges[id].u << " " << edges[id].v << " " << edges[id].cap << "\n";
                if (id & 1) continue;
                if (edges[id].flow == edges[id].cap) continue;
                q.push(edges[id].v);
            }
        }
        
        // for (int i = 0; i < n; i++) cout << sset[i] << " ";
        // cout << "\n";

        for (int i = 0; i < n; i+=2){
            if (sset[edges[i].u] != sset[edges[i].v]) cout << i/2 + 1 << " ";
        }
        cout << "\n";
    }
};


void solve(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    Dinic d(2*n, s, t);
    vector<ll> cst(n);
    for (int i = 0; i < n; i++) cin >> cst[i];

    for (int i = 0; i < n; i++){
        d.add_edge(i, i+n, cst[i]);
    }

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        d.add_edge(u+n, v, INF);
        d.add_edge(v+n, u, INF);
    }

    d.mincut();

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
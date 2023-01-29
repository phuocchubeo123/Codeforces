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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

struct dsu{
    vi p;

    dsu(){}
    dsu(int n){p.resize(n); forn(i, n) p[i] = i;}

    int get(int u){
        return (u == p[u]) ? u : (p[u] = get(p[u]));
    }
    bool unite(int u, int v){
        u = get(u); v = get(v);
        if (u != v){ p[u] = v; return true;}
        return false;
    }
};


void solve(){  
    int n, m; cin >> n >> m;
    int p, b; cin >> p >> b;
    vi token(n, 0), bonus(n, 0);
    forn(i, p){
        int x; cin >> x; x--; token[x] = 1;
    }
    forn(i, b){
        int x; cin >> x; x--; bonus[x] = 1;
    }

    vi u(m), v(m);
    forn(i, m){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
    }

    dsu d(n);
    forn(i, m) if (bonus[u[i]] == 1 && bonus[v[i]] == 1) d.unite(u[i], v[i]);

    vvi adj(n);
    forn(i, m){
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }

    vi can(n, 0);
    can[d.get(0)] = 1;
    for (int x: adj[0]){
        if (bonus[x] == 1) can[d.get(x)] = 1;
    }

    if (token[0] == 1){ cout << "YES\n"; return;}
    for (int x: adj[0]) if (token[x] == 1){ cout << "YES\n"; return;}

    vi reach;
    forn(i, n){
        if (token[i] == 1){
            if (bonus[i] == 1 && can[d.get(i)] == 1){ reach.push_back(i); continue;}
            bool flag = false;
            for (int x: adj[i]){
                if (bonus[x] == 1 && can[d.get(x)] == 1) flag = true;
            }
            if (flag) reach.push_back(i);
        }
    }

    if (reach.size() == 0){ cout << "NO\n"; return;}

    vi large(n, 0);
    forn(i, n){
        if (bonus[i] == 1) large[d.get(i)]++;
    }

    vi two;
    forn(i, n){
        if (token[i] == 1){
            if (bonus[i] == 1 && large[d.get(i)] >= 2){ two.push_back(i); continue;}
            bool flag = false;
            for (int x: adj[i]){
                if (bonus[x] == 1 && large[d.get(x)] >= 2) flag = true;
            }
            if (flag) two.push_back(i);
        }
    }

    // forn(i, n){
    //     if (token[i] == 1){
    //         for (int x: adj[i]) cout << x << " ";
    //         cout << "\n";
    //     }
    // }

    // for (int x: two) cout << x << " ";
    // cout << "\n";

    if (two.size() >= 2){ cout << "YES\n"; return;}
    if (two.size() == 1){
        for (int x: reach) if (x != two[0]){ cout << "YES\n"; return;}
    }

    queue<int> q;
    q.push(0);
    vi dis(n, 2*n);
    dis[0] = 0;
    vi vis(n, 0);
    vis[0] = 1;
    while (!q.empty()){
        int x = q.front(); q.pop();
        for (int y: adj[x]){
            if (vis[y] == 1) continue;
            if (bonus[y] == 1){ dis[y] = dis[x] + 1; q.push(y); vis[y] = 1; continue;}
            if (token[y] == 1){ dis[y] = dis[x] + 1; vis[y] = 1; continue;}
        }
    }

    int mx = 2 * n, cur;
    forn(i, n){
        if (token[i] == 1){
            if (dis[i] < mx){
                cur = i; mx = dis[i];
            }
        }
    }

    int one = 0;
    forn(i, n){
        if (token[i] == 1){
            for (int x: adj[i]) if (bonus[x] == 1){ one++; break;}
        }
    }
    if (one >= mx){ cout << "YES\n"; return;}
    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
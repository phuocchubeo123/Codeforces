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

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vvi adj(maxn);
vi par(maxn, -1);
vvi chi(maxn);
vi dep(maxn, 0);
vi cyc;

void find_par(int u){
    for (int v: adj[u]){
        if (par[u] == v) continue;
        par[v] = u;
        chi[u].push_back(v);
        find_par(v);
    }
}

void find_dep(int u){
    for (int v: chi[u]){
        dep[v] = dep[u] + 1;
        find_dep(v);
    }
}

void traverse(int u){
    cyc.push_back(u);
    if (dep[u] == 0){
        vi sz_one, sz_two;
        for (int v: adj[u]){
            if (adj[v].size() == 1) sz_one.push_back(v);
            else sz_two.push_back(v);
        }

        if (sz_two.size() == 0){
            for (int v: sz_one) cyc.push_back(v);
            return;
        }

        int rt = sz_two[0];
        for (int v: adj[rt]) if (adj[v].size() == 1) cyc.push_back(v);
        int new_rt = -1;
        for (int v: adj[rt]) if (adj[v].size() > 1) new_rt = v;
        if (new_rt != -1) traverse(new_rt);
        cyc.push_back(rt);
        for (int v: sz_one) cyc.push_back(v);

        if (sz_two.size() == 1) return;

        traverse(sz_two[1]);
        return;
    }


}

void solve(){
    int n; cin >> n;
    forn(i, n-1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi cnt(n+1, 0);
    
    rep(i, 1, n){
        for (int j: adj[i]){
            if (adj[j].size() > 1) cnt[i]++;
        }
        if (cnt[i] > 2){
            cout << "No\n";
            return;
        }
    }

    // extract into odd depth and even depth
    // try to connect one odd depth with one even depth

    int root = 1;
    rep(i, 1, n) if (adj[i].size() > 1) root = i;

    find_par(root);
    rep(i, 1, n) cout << par[i] << " ";

    find_dep(root);

    traverse(root);
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
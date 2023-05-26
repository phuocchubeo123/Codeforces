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

vvi adj(maxn);
vi deg(maxn, 0);
vi sz(maxn, 1);
vi vis(maxn, 0);

void solve(){
    int n; cin >> n;
    forn(i, n-1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    if (n % 2 == 1){
        cout << -1 << "\n";
        return;
    }

    set<pair<int, int>> nodes;
    rep(i, 1, n){
        nodes.insert({deg[i], i});
    }

    // for (pii p: nodes){
    //     cout << p.first << " " << p.second << "; ";
    // }
    // cout << "\n";
    // rep(i, 1, n) cout << sz[i] << " ";
    // cout << "\n";

    int ans = 0;
    while (!nodes.empty()){
        pii p = *nodes.begin();
        nodes.erase({p.first, p.second});
        int dg = p.first, nd = p.second;
        vis[nd] = 1;
        if (sz[nd] % 2 == 0){
            for (int x: adj[nd]){
                if (vis[x] == 0){
                    nodes.erase({deg[x], x});
                    deg[x]--;
                    nodes.insert({deg[x], x});
                    ans++;
                }
            }
        }
        else{
            for (int x: adj[nd]){
                if (vis[x] == 0){
                    nodes.erase({deg[x], x});
                    deg[x]--;
                    nodes.insert({deg[x], x});
                    sz[x] += sz[nd];
                }
            }
        }

        // for (pii p: nodes){
        //     cout << p.first << " " << p.second << "; ";
        // }
        // cout << "\n";
        // rep(i, 1, n) cout << sz[i] << " ";
        // cout << "\n";
        // cout << "ans: " << ans << "\n";
    }

    cout << ans << "\n";
    return;
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
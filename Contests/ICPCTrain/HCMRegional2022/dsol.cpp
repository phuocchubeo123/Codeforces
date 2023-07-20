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
vi vis(maxn, 0);
vi odd(maxn, 0), even(maxn, 0);
vi par(maxn, 0);
vvi odds(maxn), evens(maxn), both(maxn);

// void find_connected(int u){
//     if (vis[u] == 1) return;
//     vis[u] = 1;
//     for (int v: adj[u]){
//         find_connected()
//     }
// }

void solve(){
    int n; cin >> n;
    int m; cin >> m;
    forn(i, m){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    rep(i, 1, n){
        if (odd[i] == 1 || even[i] == 1) continue;
        queue<pair<int, int>> q;
        q.push({i, 0});
        while (!q.empty()){
            // queue<pair<int, int>> q2 = q;
            // while (!q2.empty()){
            //     cout << q2.front().first << " ";
            //     q2.pop();
            // }
            // cout << "\n";
            int u = q.front().first;
            int dis = q.front().second;
            par[u] = i;
            q.pop();
            for (int v: adj[u]){
                if (dis == 0){
                    if (odd[v] == 0){
                        odd[v] = 1;
                        q.push({v, 1});
                    }
                }
                else{
                    if (even[v] == 0){
                        even[v] = 1;
                        q.push({v, 0});
                    }
                }
            }
        }
    }

    // cout << "par: ";
    // rep(i, 1, n) cout << par[i] << " ";
    // cout << "\n";

    rep(i, 1, n){
        if (odd[i] == 1 && even[i] == 1){
            both[par[i]].push_back(i);
        }
        else if (odd[i] == 1){
            odds[par[i]].push_back(i);
        }
        else if (even[i] == 1){
            evens[par[i]].push_back(i);
        }
    }

    ll ans = 0;
    rep(i, 1, n){
        ans += 1ll * both[i].size() * (odds[i].size() + evens[i].size() + both[i].size());
        ans += 1ll * odds[i].size() * odds[i].size();
        ans += 1ll * evens[i].size() * evens[i].size();
    }

    cout << ans << "\n";
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
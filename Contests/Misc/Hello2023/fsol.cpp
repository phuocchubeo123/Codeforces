#include <bits/stdc++.h>
using namespace std;

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

vi a(maxn+1);
vi p(maxn+1); 
vi des(maxn+1);
bool can2[32];
vector<vi> chi(maxn+1);
vector<vi> par(maxn, vi(32, 0));
vector<vector<bool>> can(maxn, vector<bool>(32, false)); 

void numDescendants(int u){
    des[u] = 1;
    if (chi[u].empty()) return;
    for (int v: chi[u]){ numDescendants(v); des[u] += des[v];}
}

void dfs(int u){
    if (chi[u].empty()){ can[u][a[u]] = true; return;}

    if (chi[u].size() == 1){
        int v = chi[u][0]; dfs(v);
        forn(i, 32){
            if (can[v][i]){ can[u][i^a[u]] = true; par[v][i^a[u]] = i;}
        }
        if ((des[u] & 1) ^ 1) can[u][0] = true;
        return;
    }

    for (int v: chi[u]) dfs(v);

    forn(id, chi[u].size() - 1){
        int v = chi[u][id];
        int w = chi[u][id+1];
        memset(can2, false, 32);
        forn(i, 32){
            if (!can[v][i]) continue;
            forn(j, 32){
                if (can[w][j]){ can2[i^j] = true; par[v][i^j] = i;}
            }
        }
        forn(i, 32) can[w][i] = can2[i];
    }

    int v = chi[u][chi[u].size()-1];
    memset(can2, false, 32);
    forn(i, 32){
        if (can[v][i]){ can2[i^a[u]] = true; par[v][i^a[u]] = i;}
    }
    forn(i, 32) can[u][i] = can2[i];
    if ((des[u]&1)^1) can[u][0] = true;
}

vi steps;

void backtrack(int u, int x){
    // cout << u << " " << x << "\n";
    if (x == 0){
        steps.push_back(u);
        steps.push_back(u);
        if ((des[u] & 1) ^ 1) return;
    }

    if (chi[u].empty()) return;

    if (chi[u].size() == 1){
        int v = chi[u][0];
        backtrack(v, par[v][x]);
        return;
    }

    int curr = x ^ a[u];
    for (int i = chi[u].size() - 1; i > 0; i--){
        int v = chi[u][i-1];
        int w = chi[u][i];
        // cout << v << " " << w << " " << curr << "\n";
        backtrack(w, curr ^ par[v][curr]);
        curr = par[v][curr];
    }
    backtrack(chi[u][0], curr);
}

void solve(){
    int n; cin >> n;    
    rep(i, 1, n) cin >> a[i];
    rep(i, 2, n) cin >> p[i];
    rep(i, 2, n) chi[p[i]].push_back(i);

    numDescendants(1);
    dfs(1);
    // forn(i, 32) cout << can[2][i] << " ";
    // cout << "\n";
    // forn(i, 32) cout << can[1][i] << " ";
    // cout << "\n";
    // rep(i, 2, n){
    //     cout << i << " " << des[i] << " " << ((des[i] & 2) ^ 1) << "\n";
    //     forn(j, 33) cout << can[i][j] << " ";
    //     cout << "\n";
    //     forn(j, 33) cout << par[i][j] << " ";
    //     cout << "\n";
    // }

    if (!can[1][0]){ cout << -1 << "\n"; return;}
    backtrack(1, 0);
    reverse(all(steps));
    // if (steps.back() != 1){
    //     steps.push_back(1);
    //     steps.push_back(1);
    // }
    cout << steps.size() << "\n";
    for (int x: steps){
        cout << x << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
}
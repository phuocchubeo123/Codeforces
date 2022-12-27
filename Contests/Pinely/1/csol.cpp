#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))

const int maxn = 1e3 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<vi> chi(maxn), a(maxn, vi(maxn, 0));
vi vis(maxn);
// vector<set<int>> a(maxn);

void dfs(int u, int x){
    a[u][x] = 1;
    vis[u] = 1;
    for (int v: chi[u]) if (vis[v] == 0) dfs(v, x);
}

void solve(){
    // topo sort
    int n; cin >> n;
    forn(i, n) chi[i].clear();
    forn(i, n) forn(j, n+1) a[i][j] = 0;
    forn(i, n){
        string s; cin >> s;
        forn(j, n) if (s[j] == '1') chi[i].push_back(j);
    }

    forn(i, n){
        forn(i, n) vis[i] = 0;
        dfs(i, i+1);
    }

    forn(i, n){
        int ans = 0;
        forn(j, n+1) if (a[i][j] == 1) ans++;
        cout << ans << " "; 
        forn(j, n+1) if (a[i][j] == 1) cout << j << " ";
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}
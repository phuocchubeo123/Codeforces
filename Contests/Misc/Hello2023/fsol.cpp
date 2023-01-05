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
vector<vi> chi(maxn+1);
vector<vector<vi>> seq(maxn, vector<vi>(32));
vector<vi> can(maxn, vi(32, 0)), can2(maxn, vi(32, 0));

void dfs(int u){
    can[u][a[u]] = 1;
    for (int v: chi[u]){
        dfs(v);
        forn(i, 32){
            forn(j, 32){
                can2[u][i^j] |= (can[u][i] & can[v][j]);
            }
        }
        forn(i, 32) can[u][i] = can2[u][i];
    }
}

void solve(){
    int n; cin >> n;    
    rep(i, 1, n) cin >> a[i];
    rep(i, 2, n) cin >> p[i];
    rep(i, 2, n) chi[p[i]].push_back(i);
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
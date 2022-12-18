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
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T a, T b){while(b){b^=a^=b^=a%=b;} return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 2005;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

void solve(){
    int n; cin >> n;
    vector<vector<ll>> f(n+1, vector<ll>(n+1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cin >> f[i][j];
            f[j][i] = f[i][j];
        }
    }

    set<int> curr;
    curr.insert(1);
    vector<set<pair<ll, int>>> candidates(n+1);
    vector<pii> edges;
    vi vis(n+1, 0);
    vis[1] = 1;
    for (int i = 2; i <= n; i++) candidates[1].insert({-f[1][i], i});

    for (int i = 2; i <= n; i++){
        ll mn = 0;
        int u, v;
        for (int j = 1; j <= n; j++){
            if (vis[j] == 1){
                pair<ll, int> p = *candidates[j].begin();
                if (p.first <= mn){
                    mn = p.first; u = j; v = p.second;
                }
            }
        }
        edges.push_back({u, v});
        curr.insert(v);
        vis[v] = 1;
        for (int j = 1; j <= n; j++){
            if (vis[j] == 0) candidates[v].insert({-f[v][j], j});
        }
        for (int j: curr){
            candidates[j].erase({-f[j][v], v});
        }

    }

    for (auto p: edges){
        int u = p.first, v = p.second;
        ll ac = f[u][u] - f[u][v];
        ll bc = f[v][v] - f[v][u];
        ll c = (ac + bc) / n;
        cout << u << " " << v << " " << c << "\n";
    }
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
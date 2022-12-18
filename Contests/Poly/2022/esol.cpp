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
#define for1(i, n) for(int i = 1; i <= n; i++)
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

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<vi> adj(maxn);
vector<vi> par(maxn, vi(20, -1));
vi pow2(maxn);
vi vis(maxn);
vi path1(maxn, -1), path2(maxn, -1);
vi qr1(maxn, 0), qr2(maxn, 0);

void reRoot(int i){
    stack<int> st;
    for1(i, maxn) vis[i] = 0;
    st.push(i);
    par[i][0] = i;
    while (!st.empty()){
        int u = st.top(); st.pop();
        if (vis[u] == 1) continue;
        vis[u] = 1;
        for (int v: adj[u]){
            if (par[u][0] == v) continue;
            par[v][0] = u;
            st.push(v);
        }
    }
}

int ancestor(int u, int k){
    if (k == 0) return u;
    int rem = k - (1 << pow2[k]);
    return ancestor(par[u][pow2[k]], rem);
}

void dfs(int u){
    if (vis[u] == 1) return;
    vis[u] = 1;
    if (qr1[u] == 1) path1[u] = 0;
    if (qr2[u] == 1) path2[u] = 0;

    for (int v: adj[u]){
        if (par[u][0] == v) continue;
        dfs(v);
        if (path1[v] >= 0){
            if (path1[u] == -1) path1[u] = 0;
            path1[u] += 2 + path1[v];
        }
        if (path2[v] >= 0){
            if (path2[u] == -1) path2[u] = 0;
            path2[u] += 2 + path2[v];
        }
    }
}

void solve(){
    pow2[1] = 0;
    for (int i = 2; i < maxn; i++){
        pow2[i] = pow2[i/2] + 1;
    }

    int n, d; cin >> n >> d;
    forn(i, n-1){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    reRoot(1);

    for1(i, 19){
        for1(u, n) par[u][i] = par[par[u][i-1]][i-1];
    }

    int m1; cin >> m1;
    forn(i, m1){
        int a; cin >> a;
        qr1[a] = 1;
        qr2[ancestor(a, d)] = 1;
    }

    int m2; cin >> m2;
    forn(i, m2){
        int b; cin >> b;
        qr2[b] = 1;
        qr1[ancestor(b, d)] = 1;
    }

    // for1(i, n) cout << qr1[i] << " ";
    // cout << "\n";
    // for1(i, n) cout << qr2[i] << " ";
    // cout << "\n";
    // return;

    forn(i, maxn-1) vis[i] = 0;
    dfs(1);

    // for1(i, n) cout << path1[i] << " ";
    // cout << "\n";
    // for1(i, n) cout << path2[i] << " ";
    // cout << "\n";

    cout << path1[1] + path2[1];
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
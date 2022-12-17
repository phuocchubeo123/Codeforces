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

const int maxn = 2e3 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<vector<int>> adj(maxn);
vector<vector<int>> to(maxn, vector<int>(maxn)), ans(maxn, vi(maxn));
vector<int> vis(maxn);
vector<char> ch(maxn);

void find_to(int u, int ori){
    if (vis[u] == 1) return;
    vis[u] = 1;
    for (auto v: adj[u]){
        if (vis[v] == 1) continue;
        to[v][ori] = u;
        find_to(v, ori);
    }
}

int find_ans(int u, int v){
    if (ans[u][v] != -1) return ans[u][v];
    if (u == v){
        ans[u][v] = 1;
        return 1;
    }

    if (ch[u] != ch[v]){
        ans[u][v] = max(find_ans(to[u][v], v), find_ans(to[v][u], u));
        return ans[u][v];
    }

    if (to[u][v] == v){
        ans[u][v] = 2;
        return 2;
    }

    ans[u][v] = 2 + find_ans(to[u][v], to[v][u]);
    return ans[u][v];
}

void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear();
    string s; cin >> s;
    for (int i = 1; i <= n; i++){
        ch[i] = s[i-1];
    }

    forn(i, n-1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) vis[j] = 0;
        find_to(i, i);
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            ans[i][j] = -1;
        }
    }

    int res = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            res = max(res, find_ans(i, j));
        }
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= n; j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << res << "\n";
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
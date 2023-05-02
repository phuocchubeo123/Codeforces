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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

void solve(){
    int n, a, b; cin >> n >> a >> b;
    vector<vector<pair<int, ll>>> adj(n+1); 
    forn(i, n-1){
        int u, v; cin >> u >> v;
        ll w; cin >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vi vis(n+1, 0);
    vector<ll> dis_a(n+1, -1);
    stack<int> st;
    st.push(a);
    dis_a[a] = 0;
    while (!st.empty()){
        int u = st.top(); st.pop();
        vis[u] = 1;
        for (auto p: adj[u]){
            int v = p.first;
            ll w = p.second;
            if (vis[v] == 1) continue;
            if (v == b){
                if ((dis_a[u] ^ w) == 0){
                    cout << "YES\n";
                    return;
                }
                continue;
            }
            dis_a[v] = (dis_a[u] ^ w);
            st.push(v);
        }
    }

    rep(i, 1, n) vis[i] = 0;
    vector<ll> dis_b(n+1, -1);
    // st.clear();
    st.push(b);
    dis_b[b] = 0;
    while (!st.empty()){
        int u = st.top(); st.pop();
        vis[u] = 1;
        for (auto p: adj[u]){
            int v = p.first;
            ll w = p.second;
            if (vis[v] == 1) continue;
            dis_b[v] = (dis_b[u] ^ w);
            st.push(v);
        }
    }

    dis_b[b] = -1;

    map<ll, int> in_b;
    rep(i, 1, n) if (dis_b[i] != -1) in_b[dis_b[i]] = 1;
    rep(i, 1, n) if (dis_a[i] != -1 && in_b[dis_a[i]] == 1){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
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
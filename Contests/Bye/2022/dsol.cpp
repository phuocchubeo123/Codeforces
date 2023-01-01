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
const ll MOD = 998244353;
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vi a(maxn), b(maxn); 
vector<set<int>> co(maxn);
vi vis(maxn), taken(maxn);
bool flag;
vi cnt(maxn, 0);

void dfs(int u, int i){
    taken[i] = u;
    vis[u] = 1;

    cnt[a[u]]--; cnt[b[u]]--;
    co[i].erase(u);
    if (a[u] == i && b[u] == i){
    }

    else if (a[u] == i){
        co[b[u]].erase(u);
        if (cnt[b[u]] == 1){
            int w = *co[b[u]].begin();
            if (a[w] == b[u]) dfs(w, b[w]);
            else dfs(w, a[w]);
        }
    }

    else if (b[u] == i){
        co[a[u]].erase(u);
        if (cnt[a[u]] == 1){
            int w = *co[a[u]].begin();
            if (a[w] == a[u]) dfs(w, b[w]);
            else dfs(w, a[w]);
        }
    }

    for (int v: co[i]){
        if (a[v] == b[v]){ flag = false; continue;}
        if (a[v] == i) dfs(v, b[v]);
        if (b[v] == i) dfs(v, a[v]);
    }
}

vector<vi> vertices(maxn);
vi col(maxn);
int color;

void dfs2(int u){
    if (vis[u] == 1) return;
    vis[u] = 1;
    vertices[color].push_back(u);
    col[u] = color;
    co[a[u]].erase(u); co[b[u]].erase(u);
    for (int v: co[a[u]]){

        dfs2(v);
    }
    for (int v: co[b[u]]){
        dfs2(v);
    }
}

void solve(){
    int n; cin >> n;
    rep(i, 1, n){ co[i].clear(); vertices[i].clear();}
    rep(i, 1, n) cnt[i] = 0;
    forn(i, n){ cin >> a[i]; co[a[i]].insert(i); cnt[a[i]]++;}
    forn(i, n){ cin >> b[i]; co[b[i]].insert(i); cnt[b[i]]++;}

    forn(i, n) vis[i] = 0;
    rep(i, 1, n) taken[i] = -1;
    flag = true;
    ll ans = 1;
    forn(i, n){
        if (vis[i] == 1) continue;
        if (a[i] == b[i]){
            dfs(i, a[i]);
            if (flag){ ans = (ans * n) % MOD; continue;}
            else{ cout << 0 << "\n"; return;}
        }
        
        if (cnt[a[i]] == 1 && cnt[b[i]] == 1){ cout << 0 << "\n"; return;}
        if (cnt[a[i]] == 1){
            dfs(i, a[i]);
            if (flag) continue;
            else{ cout << 0 << "\n"; return;}
        }
        if (cnt[b[i]] == 1){
            dfs(i, b[i]);
            if (flag) continue;
            else{ cout << 0 << "\n"; return;}
        }
    }

    // rep(i, 1, n) cout << cnt[i] << " ";
    // cout << "\n";
    // rep(i, 1, n) cout << taken[i] << " ";
    // cout << "\n";

    rep(i, 1, n) if (cnt[i] == 0 && taken[i] == -1){ cout << 0 << "\n"; return;}

    color = 0;
    forn(i, n) col[i] = -1;
    forn(i, n){
        if (vis[i] == 1) continue;
        color++;
        dfs2(i);
    }

    rep(i, 1, color){
        ans = (ans * 2) % MOD;
    }
    cout << ans << "\n";
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
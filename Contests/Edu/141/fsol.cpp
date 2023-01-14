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

const int maxn = 3e3 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

int n1, n2;
vector<vector<int>> adj(2 * maxn);
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : adj[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

void maxMatchingKuhn(){
    mt.assign(n2, -1);
    for (int v = 0; v < n1; ++v) {
        used.assign(n1, false);
        try_kuhn(v);
    }
}

vvi decompose(vi p){
    int sz = p.size();
    vector<bool> vis(sz, false);
    vvi cycs;
    rep(i, 1, sz-1){
        if (vis[i]) continue;
        int curr = i;
        vi cyc;
        while (!vis[curr]){
            cyc.push_back(curr);
            vis[curr] = true;
            curr = p[curr];
        }
        cycs.push_back(cyc);
    }
    return cycs;
}


void solve(){
    int n; cin >> n;
    vi a(n+1); rep(i, 1, n) cin >> a[i];
    vi b(n+1); rep(i, 1, n) cin >> b[i];

    vvi cyca = decompose(a), cycb = decompose(b);

    vi ca(n+1), cb(n+1);
    forn(i, cyca.size()){
        for (int x: cyca[i]){
            ca[x] = i;
        }
    }

    forn(i, cycb.size()){
        for (int x: cycb[i]){
            cb[x] = i;
        }
    }

    // cout << "cycles in a\n";
    // for (auto cyc: cyca){
    //     for(int x: cyc) cout << x << " ";
    //     cout << "\n";
    // }
    // cout << "cycles in b\n";
    // for (auto cyc: cycb){
    //     for(int x: cyc) cout << x << " ";
    //     cout << "\n";
    // }

    // rep(i, 1, n) cout << ca[i] << " ";
    // cout << "\n";
    // rep(i, 1, n) cout << cb[i] << " ";
    // cout << "\n";

    n1 = cyca.size(); n2 = cycb.size() + n;
    vector<set<int>> adj2(2 * n);
    rep(i, 1, n){
        adj2[ca[i]].insert(cb[i] + n);
        adj2[cb[i] + n].insert(ca[i]);
    }

    forn(i, 2 * n){
        for (int x: adj2[i]) adj[i].push_back(x);
    }

    // forn(i, n1){
    //     cout << i << ":\n";
    //     for (int j: adj[i]) cout << j - n << " ";
    //     cout << "\n";
    // }
    
    // // cout << "\n";
    // forn(i, n2-n){
    //     cout << i << ":\n";
    //     for (int j: adj[i + n]) cout << j << " ";
    //     cout << "\n";
    // }

    maxMatchingKuhn();
    vi cnt(n+1, 1);
    int ans = n;
    forn(i, n2-n){
        if (mt[i + n] != -1){
            // cout << i << " " << mt[i+n] << "\n";
            // rep(j, 1, n) if (ca[j] == i) cout << j << " ";
            // cout << "\n";
            // rep(j, 1, n) if (cb[j] == mt[i+n]) cout << j << " ";
            // cout << "\n";
            rep(j, 1, n) if (cb[j] == i && ca[j] == mt[i+n]){ cnt[j] = 0; ans--; break;}
        }
    }

    cout << ans << "\n";
    rep(i, 1, n) if (cnt[i] == 1) cout << i << " ";
    cout << "\n";
}

using namespace std::chrono;

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
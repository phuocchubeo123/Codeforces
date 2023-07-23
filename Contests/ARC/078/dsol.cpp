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
vi par(maxn, 0);
vvi chi(maxn);

void makeRoot(int u){
    for (int v: adj[u]){
        if (par[u] == v) continue;
        par[v] = u;
        chi[u].push_back(v);
        makeRoot(v);
    }
}

vi pts(maxn, 1);

void pt(int u){
    for (int v: chi[u]){
        pt(v);
        pts[u] += pts[v];
    }
}

void solve(){
    int n; cin >> n;
    forn(i, n-1){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    makeRoot(1);
    pt(1);

    // rep(i, 1, n) cout << par[i] << " ";
    // cout << "\n";
    // rep(i, 1, n) cout << pts[i] << " ";
    // cout << "\n";
    // return;

    int curr = n;
    vi anc;
    while (curr != 1){
        anc.push_back(curr);
        curr = par[curr];
    }

    anc.push_back(curr);

    int white = pts[anc[anc.size() / 2 - 1]];
    int black = n - white;


    // cout << black << " " << white << "\n";
    
    if (black > white) cout << "Fennec\n";
    else cout << "Snuke\n";
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
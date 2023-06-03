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

struct dsu{
    vi p;

    dsu(){}
    dsu(int n){p.resize(n); forn(i, n) p[i] = i;}

    int get(int u){
        return (u == p[u]) ? u : (p[u] = get(p[u]));
    }
    bool unite(int u, int v){
        u = get(u); v = get(v);
        if (u != v){ p[u] = v; return true;}
        return false;
    }
};

set<pair<int, int>> adj[maxn];
vi a(maxn);
vi pt(maxn, 0);
vi vis(maxn, 0);
vi par(maxn);
vector<set<int>> chi(maxn);

int play(int x, int q, int rt){
    int curr_point = q;
    int y = par[x];
    q += pt[y];
    while (!chi[y].empty()){
        int z = *chi[y].begin();
        bool flag = true;
        for (auto edge: adj[z]){
            int qq = edge.first, u = edge.second;
            if (qq > q){
                flag = false;
                break;
            }
        }

        if (!flag){
            while (){
                chi[rt].insert(*pt);
                chi[y].erase(*pt);
            }
        }
    }           
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    forn(i, n) cin >> a[i];
    
    forn(i, m){
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].insert({v, w});
        adj[v].insert({u, w});
    }

    vector<pair<pair<int, int>, int>> qr;
    forn(i, q){
        int x, q; cin >> x >> q;
        x--;
        qr.push_back({{q, x}, i});
    }

    sort(all(qr));

    vi ans(q);

    forn(i, n) par[i] = i;
    forn(i, n) chi[i].insert(i);

    for (auto QR: qr){
        int q = QR.first.first, x = QR.first.second, i = QR.second;
        int y = play(x, q, x);
        ans[i] = y;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
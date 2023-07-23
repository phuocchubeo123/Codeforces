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

struct pt{
    int ind;
    int x;
    int y;
};

bool sort1(pt u, pt v){
    if (u.x < v.x) return true;
    if (u.x > v.x) return false;
    if (u.y < v.y) return true;
    return false;
}

bool sort2(pt u, pt v){
    if (u.y < v.y) return true;
    if (u.y > v.y) return false;
    if (u.x < v.x) return true;
    return false;
}

int dist(pt u, pt v){
    return min(abs(u.x - v.x), abs(u.y - v.y));
}

istream& operator>>(istream& in, pt& p){
    in >> p.x >> p.y;
    return in;
}

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

void solve(){
    int n; cin >> n;
    vector<pt> p(n);
    forn(i, n){
        cin >> p[i];
        p[i].ind = i;
    }

    vector<pair<pt, pt>> edges;

    sort(all(p), sort1);

    forn(i, n-1){
        pt u = p[i], v = p[i+1];
        edges.push_back({u, v});
    }

    sort(all(p), sort2);

    forn(i, n-1){
        pt u = p[i], v = p[i+1];
        edges.push_back({u, v});
    }

    sort(all(edges), [](pair<pt, pt> x, pair<pt, pt> y){
        return dist(x.first, x.second) < dist(y.first, y.second);
    });

    // for (auto e: edges){
    //     cout << e.first.ind << " " << e.second.ind << "\n";
    // }

    dsu d(n);
    ll ans = 0;
    for (auto e: edges){
        if (!d.unite(e.first.ind, e.second.ind)) continue;
        // cout << "found: " << e.first.ind << " " << e.second.ind << "\n";
        ans += 1ll * dist(e.first, e.second);
    }

    cout << ans << "\n";
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
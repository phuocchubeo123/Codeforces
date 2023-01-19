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

ll encode(string s){
    ll ans = 0;
    for (char c: s) ans = ans * 26 + (c - 'a' + 1);
    return ans;
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
    vector<string> a(n), b(n);
    forn(i, n) cin >> a[i] >> b[i];
    vector<ll> aa(n), bb(n);
    forn(i, n){ aa[i] = encode(a[i]); bb[i] = encode(b[i]);}

    vector<ll> c;
    forn(i, n){ c.push_back(aa[i]); c.push_back(bb[i]);}
    sort(all(c));
    c.resize(distance(c.begin(), unique(all(c))));
    map<ll, int> enc;
    forn(i, c.size()) enc[c[i]] = i;
    forn(i, n){ aa[i] = enc[aa[i]]; bb[i] = enc[bb[i]];}

    dsu d(2 * n);
    forn(i, n){
        bool x = d.unite(aa[i], bb[i]);
        if (!x){ cout << "No\n"; return;}
    }
    cout << "Yes\n"; return;
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
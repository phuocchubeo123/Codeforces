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

int r, c; 

int encode(int x, int y){
    return 1000 * x + y;
}

pii decode(int z){
    return {z / 1000, z % 1000};
}

bool valid(int x, int y){
    return (0 <= x) && (x < r) && (0 <= y) && (y < c);
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
    cin >> r >> c;
    vector<string> grid(r);
    forn(i, r) cin >> grid[i];
    dsu d(1000 * 1000);

    vector<pii> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    forn(i, r) forn(j, c) for (pii p: dir){
        int i2 = i + p.first, j2 = j + p.second;
        // cout << i << " " << j << " " << i2 << " " << j2 << "\n";
        // continue;
        if (valid(i2, j2) && grid[i][j] == grid[i2][j2]) d.unite(encode(i, j), encode(i2, j2));
    }

    int n; cin >> n;
    forn(i, n){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        if (d.get(encode(r1, c1)) != d.get(encode(r2, c2))){ cout << "neither\n"; continue;}
        int a, b;
        tie(a, b) = decode(d.get(encode(r1, c1)));
        if (grid[a][b] == '0') cout << "binary\n";
        else cout << "decimal\n";
    }
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
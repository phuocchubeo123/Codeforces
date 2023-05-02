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

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vvi adj(maxn);
vi par(maxn);
vvi chi(maxn);

void dfs(int u){
    for (int v: adj[u]){
        if (par[u] == v) continue;
        par[v] = u;
        chi[u].push_back(v);
        dfs(v);
    }
}

int tim;
int tm2;
vi tin(maxn), tout(maxn);
vi tin_rev(maxn), tout_rev(maxn);
void dfs2(int u){
    tim++;
    tin[u] = tim;
    for (int v: chi[u]){
        dfs2(v);
    }
    tm2++;
    tout[u] = tm2;
}

vvi basis_tin(maxn), basis_tout(maxn);

vvi basis(maxn);

void merge_basis(vi a, int x, vi &b){
    if (a.empty()){ b.push_back(x); return;}
    int pt = 0;
    int cur = x;
    per(bit, 29, 0){
        if (pt == a.size()){
            if (cur) b.push_back(cur);
            return;
        }
        if ((a[pt] >> bit) & 1){
            if ((cur >> bit) & 1) cur = cur ^ a[pt];
            b.push_back(a[pt]);
            pt++;
        }
        else{
            if ((cur >> bit) & 1){
                b.push_back(cur);
                rep(i, pt, a.size() - 1) b.push_back(a[i]);
                return;
            }
            else{ 
                continue;
            }
        }
    }
}

void merge_bases(vi a, vi b, vi &c){
    c = a;
    vi d;
    for (int x: b){
        d.clear();
        merge_basis(c, x, d);
        c = d;
    }
}

vi a(maxn); 
void dfs3(int u){
    basis[u] = {a[u]};
    vi tmp;
    for (int v: chi[u]){
        dfs3(v);
        tmp.clear();
        merge_bases(basis[u], basis[v], tmp);
        basis[u] = tmp;
    }

}

bool ancestor(int u, int v){
    return (tin[u] < tin[v] && tout[u] > tout[v]);
}

int best_subset(vi a){
    int cur = 0;
    int pt = 0;
    per(bit, 29, 0){
        if (pt == a.size()) return cur;
        if (((a[pt] >> bit) & 1) == 0) continue;
        if ((cur >> bit) & 1) pt++;
        else{ cur = cur ^ a[pt]; pt++;}
    }
    return cur;
}

void solve(){
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    vi u(n), v(n);
    forn(i, n-1){
        cin >> u[i] >> v[i];
    }
    forn(i, n-1){
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }

    par[1] = -1;
    dfs(1);
    tim = 0; tm2 = 0;
    dfs2(1);

    rep(i, 1, n){ tin_rev[tin[i]] = i; tout_rev[tout[i]] = i;}

    rep(i, 1, n){
        merge_basis(basis_tin[i-1], a[tin_rev[i]], basis_tin[i]);
    }

    per(i, n, 1){
        merge_basis(basis_tout[i+1], a[tout_rev[i]], basis_tout[i]);
    }

    dfs3(1);

    // cout << "basis:\n";
    // for (int x: basis[2]) cout << x << " ";
    // cout << "\n";
    // cout << "best: " << best_subset(basis[2]) << "\n";

    int q; cin >> q;
    forn(i, q){
        int r, vv;
        cin >> r >> vv;
        // cout << r << " " << vv << "\n";
        if (r == vv){
            cout << best_subset(basis[1]) << "\n";
            continue;
        }
        
        // cout << tin[vv] << " " << tin[r] << "\n";
        // cout << tout[vv] << " " << tout[r] << "\n";
        // cout << "ancestor: " << ancestor(vv, r) << "\n";
        if (!ancestor(vv, r)){
            // cout << "one\n";
            cout << best_subset(basis[vv]) << "\n";
            continue;
        }

        int L = 0, R = chi[vv].size() - 1;
        while (L < R){
            // cout << L << " " << R << "\n";
            int m = (L + R + 1) / 2, x = chi[vv][m];
            if (tin[x] > tin[r]) R = m - 1;
            else L = m;
        }
        vi base_qr;
        int x = chi[vv][L];
        // cout << tin[x] << "\n";
        // for (int y: basis_tin[tin[x] - 1]) cout << y << " ";
        // cout << "\n";
        merge_bases(basis_tin[tin[x]-1], basis_tout[tout[x]+1], base_qr);
        cout << best_subset(base_qr) << "\n";
        // return;
    }

    // clear
    rep(i, 1, n) adj[i].clear();
    rep(i, 1, n) par[i] = -1;
    rep(i, 1, n) chi[i].clear();
    rep(i, 1, n) basis_tin[i].clear();
    rep(i, 1, n) basis_tout[i].clear();
    rep(i, 1, n) basis[i].clear();
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
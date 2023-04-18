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

struct LazySegTree{
    int sz;
    vector<ll> seg;
    vector<ll> lazy;
  
    LazySegTree(int s){
        sz = s;
        seg.resize(4 * s);
        lazy.resize(4 * s);
    }

    void update(int pos, ll val){
        update(1, 1, sz, pos, val);
    }

    void update(int node, int st, int en, int pos, ll val){
        if (lazy[node]){
            seg[node] += lazy[node];
            if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > pos) || (en < pos)) return;
        if ((st == pos) && (en == pos)){
            seg[node] = val ;
            return;
        }
        int mid = (st + en) / 2;
        update(2*node, st, mid, pos, val);
        update(2*node+1, mid+1, en, pos, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }

    void rangeUpdate(int l, int r, ll val){
        rangeUpdate(1, 1, sz, l, r, val);
    }

    void rangeUpdate(int node, int st, int en, int l, int r, ll val){
        if (lazy[node]){
            seg[node] += lazy[node];
            if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > r) || (en < l)) return;
        if ((st >= l) && (en <= r)){
            seg[node] += val;
            if (st != en){lazy[2*node] += val, lazy[2*node+1] += val;}
            return;
        }
        int mid = (st + en) / 2;
        rangeUpdate(2*node, st, mid, l, r, val);
        rangeUpdate(2*node+1, mid+1, en, l, r, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }

    ll query(int l, int r){
        return query(1, 1, sz, l, r);
    }

    ll query(int node, int st, int en, int l, int r){
        if (lazy[node]){
            seg[node] += lazy[node];
            if (st < en){lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > r) || (en < l)) return 0;
        if ((l <= st) && (en <= r)) return seg[node];
        int mid = (st + en) / 2;
        ll q1 = query(2*node, st, mid, l, r);
        ll q2 = query(2*node+1, mid+1, en, l, r);
        return (q1+q2);
    }
};

void solve(){
    int n; cin >> n;
    vi a(n+1); rep(i, 1, n) cin >> a[i];
    vvi num(n+1);
    rep(i, 1, n) num[a[i]].push_back(i);
    LazySegTree best(n+1);
    LazySegTree tot(n+1);
    rep(i, 1, n) best.update(i, 0); 
    rep(i, 1, n) tot.update(i, 0); 

    ll cnt;
    rep(i, 1, n){
        // cout << i << ":\n";
        // for (int j: num[i]) cout << j << " ";
        // cout << "\n";
        for (int j: num[i]){
            int l = j-1, r = n;
            while (l < r){
                int m = (l + r + 1) / 2;
                if (best.query(m, m) >= i) r = m - 1;
                else l = m;
            }
            // cout << i << " " << j << " " << l << "\n";
            if (l == j-1) continue;
            else{
                best.rangeUpdate(j, l, 1);
                tot.rangeUpdate(j, l, 1ll * i);
            }
        }
    }

    // rep(i, 1, n){
    //     ll x = best.query(i, i);
    //     cout << tot.query(i, i) - x * (x + 1) / 2 << " ";
    // }
    ll x = best.query(n, n);
    cout << tot.query(n, n) - x * (x + 1) / 2;
    cout << "\n";
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
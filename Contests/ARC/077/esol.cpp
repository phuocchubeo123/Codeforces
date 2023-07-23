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

struct Node{
    ll val;
    Node(int a){val = 1ll * a;}
    Node(ll a){val = a;}
    Node(){val = 0;}
};

Node operator+(const Node& x, const Node& y){
    Node res;
    res.val = x.val + y.val;
    return res;
}

template <typename T>
struct LazySegTree{
    int sz;
    vector<T> seg;
    vector<ll> lazy;
    vector<ll> lazy2;
  
    LazySegTree(int s){
        sz = s;
        seg.resize(4 * s);
        lazy.resize(4 * s);
        lazy2.resize(4 * s);
    }

    void dump_lazy(int node, int st, int en){
        int mid = (st + en) / 2;

        if (lazy[node]){
            seg[node].val += lazy[node] * (en - st + 1);
            if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }

        if (lazy2[node]){
            seg[node].val += (lazy2[node] * (en - st + 1) * (en - st + 2)) / 2;
            if (st != en){
                lazy[2*node] += (lazy2[node] * (en - mid));
                lazy2[2*node] += lazy2[node];
                lazy2[2*node+1] += lazy2[node];
            }
            lazy2[node] = 0;
        }

    }

    void update(int pos, int val){
        update(1, 1, sz, pos, val);
    }

    void update(int node, int st, int en, int pos, ll val){
        dump_lazy(node, st, en);
        int mid = (st + en) / 2;

        if ((st > pos) || (en < pos)) return;
        if ((st == pos) && (en == pos)){
            seg[node].val += val;
            return;
        }

        update(2*node, st, mid, pos, val);
        update(2*node+1, mid+1, en, pos, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }

    void rangeUpdate(int l, int r, int val){
        rangeUpdate(1, 1, sz, l, r, val);
    }

    void rangeUpdate(int node, int st, int en, int l, int r, ll val){
        dump_lazy(node, st, en);
        if ((st > r) || (en < l)) return;
        if ((st >= l) && (en <= r)){
            seg[node].val += val * (en - st + 1);
            if (st != en){
                lazy[2*node] += val;
                lazy[2*node+1] += val;
            }
            return;
        }
        int mid = (st + en) / 2;
        rangeUpdate(2*node, st, mid, l, r, val);
        rangeUpdate(2*node+1, mid+1, en, l, r, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }

    void arithUpdate(int l, int r, ll val){
        arithUpdate(1, 1, sz, l, r, val + (r - sz));
    }

    void arithUpdate(int node, int st, int en, int l, int r, ll val){
        dump_lazy(node, st, en);
        int mid = (st + en) / 2;
        if ((st > r) || (en < l)) return;
        if ((st >= l) && (en <= r)){
            seg[node].val += (val) * (en - st + 1) + (en - st + 1) * (en - st + 2) / 2;
            if (st != en){
                lazy[2*node] += val + (en - mid);
                lazy[2*node+1] += val;
                lazy2[2*node]++;
                lazy2[2*node+1]++;
            }
            return;
        }
        arithUpdate(2*node, st, mid, l, r, val + (en - mid));
        arithUpdate(2*node+1, mid+1, en, l, r, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }

    T query(int l, int r){
        return query(1, 1, sz, l, r);
    }

    T query(int node, int st, int en, int l, int r){
        dump_lazy(node, st, en);
        if ((st > r) || (en < l)) return T();
        if ((l <= st) && (en <= r)){
            // cout << "st: " << st << " " << en << "\n";
            return seg[node];
        }
        int mid = (st + en) / 2;
        T q1 = query(2*node, st, mid, l, r);
        T q2 = query(2*node+1, mid+1, en, l, r);
        return (q1+q2);
    }
};


void solve(){
    int n, m; cin >> n >> m;
    vi a(n);
    forn(i, n) cin >> a[i];
    LazySegTree<Node> st(m);
    forn(i, n-1){
        // rep(i, 1, m) cout << st.query(i, i).val << " ";      
        // cout << "\n";
        // cout.flush();
        int u = a[i], v = a[i+1];
        if (u < v){
            int step = v - u;
            st.rangeUpdate(1, u, step);
            st.arithUpdate(u+1, v, 0);
            if (v < m) st.rangeUpdate(v+1, m, step);
        }
        if (u > v){
            int step = (m - u) + v;
            st.rangeUpdate(v+1, u, step);
            st.arithUpdate(1, v, 0);
            if (u < m) st.arithUpdate(u+1, m, v);
        }
    }

    // rep(i, 1, m) cout << st.query(i, i).val << " ";      
    // cout << "\n";
    // cout.flush();

    ll ans = 1e12;
    rep(i, 1, m) ans = min(ans, st.query(i, i).val);
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
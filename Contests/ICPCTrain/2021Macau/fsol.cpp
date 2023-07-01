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

const int maxn = 5e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

/* Lazy Segment Tree*/

struct Node{
    ll val;
    ll mn;
    int pos;
    Node(int a, int ps = 0){val = 1ll * a; pos = ps;}
    Node(ll a, int ps = 0){val = a; pos = ps;}
    Node(ll a, ll Mn){val = a; mn = Mn;}
    Node(){val = 0; mn = 0;}
};

Node operator+(const Node& x, const Node& y){
    Node res;
    res.val = max(x.val, y.val);
    res.mn = min(x.mn, y.mn);
    if (x.val > y.val) res.pos = x.pos;
    else res.pos = y.pos;
    return res;
}

template <typename T>
struct LazySegTree{
    int sz;
    vector<T> seg;
    vector<ll> lazy;
  
    LazySegTree(int s){
        sz = s;
        seg.resize(8 * s);
        lazy.resize(8 * s);
    }

    void update(int pos, ll val){
        update(1, 1, sz, pos, val);
    }

    void update(int node, int st, int en, int pos, ll val){
        if (lazy[node]){
            seg[node].val += lazy[node];
            seg[node].mn += lazy[node];
            if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > pos) || (en < pos)) return;
        if ((st == pos) && (en == pos)){
            seg[node].val += val;
            seg[node].mn += val;
            seg[node].pos = pos;
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
            seg[node].val += lazy[node];
            seg[node].mn += lazy[node];
            if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > r) || (en < l)) return;
        if ((st >= l) && (en <= r)){
            seg[node].val += val;
            seg[node].mn += val;
            if (st != en){lazy[2*node] += val, lazy[2*node+1] += val;}
            return;
        }
        int mid = (st + en) / 2;
        rangeUpdate(2*node, st, mid, l, r, val);
        rangeUpdate(2*node+1, mid+1, en, l, r, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }

    T query(int l, int r){
        return query(1, 1, sz, l, r);
    }

    T query(int node, int st, int en, int l, int r){
        if (lazy[node]){
            seg[node].val += lazy[node];
            seg[node].mn += lazy[node];
            if (st < en){lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > r) || (en < l)) return T(1ll * 0, (ll) (10000000006));
        if ((l <= st) && (en <= r)) return seg[node];
        int mid = (st + en) / 2;
        T q1 = query(2*node, st, mid, l, r);
        T q2 = query(2*node+1, mid+1, en, l, r);
        return (q1+q2);
    }
};

void solve(){
    int n; cin >> n;
    vector<ll> a(n+1);
    rep(i, 1, n) cin >> a[i];
    ll tot = 0;
    rep(i, 1, n) tot += a[i];
    if (tot > 1ll * (n - 2) * n){
        cout << "Recurrent\n";
        return;
    } 

    LazySegTree<Node> st(n);
    rep(i, 1, n){
        st.update(i, a[i]);
    }  
    
    int cnt = 0;
    while (true){
        Node nd = st.query(1, n);
        ll mx = nd.val;
        ll mn = nd.mn;
        int ps = nd.pos;
        if (mx - mn <= n) break;
        ll x = mx / (1ll * (n-1));
        st.update(ps, -1ll * x * n);
        st.rangeUpdate(1, n, x);
        if (cnt++ == n){
            cout << "Recurrent\n";
            return;
        }
    }  

    vector<pair<ll, int>> b;
    rep(i, 1, n){
        b.push_back({st.query(i, i).val, i});
    }
    vi c(n+1);
    forn(i, n) c[b[i].second] = b[i].first;
    // rep(i, 1, n) cout << c[i] << " ";
    // cout << "\n";
    sort(all(b));
    reverse(all(b));

    forn(i, n){
        // rep(i, 1, n) cout << st.query(i, i).val << " ";
        // cout << "\n";
        if (b[i].first + i >= n-1){
            continue;
        }
        else{
            forn(j, i) c[b[j].second] -= 1ll * n;
            rep(j, 1, n) c[j] += i;
            rep(j, 1, n) cout << c[j] << ((j == n) ? "" : " ");
            cout << "\n";
            return;   
        }
    }
    cout << "Recurrent\n";
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
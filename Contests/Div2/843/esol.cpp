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

struct Node{
    ll mn;
    int pos;
    Node(ll a){mn = a;}
    Node(){mn = 1ll * 1e9 * maxn;}
};

Node operator+(const Node& x, const Node& y){
    Node res;
    if (x.mn < y.mn){ res.mn = x.mn; res.pos = x.pos;}
    else { res.mn = y.mn; res.pos = y.pos;}
    return res;
}

template <typename T>
struct LazySegTree{
    int sz;
    vector<T> seg;
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
            seg[node].mn += lazy[node];
            if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > pos) || (en < pos)) return;
        if ((st == pos) && (en == pos)){
            seg[node].mn = val;
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
            seg[node].mn += lazy[node];
            if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > r) || (en < l)) return;
        if ((st >= l) && (en <= r)){
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
            seg[node].mn += lazy[node];
            if (st < en){lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > r) || (en < l)) return T();
        if ((l <= st) && (en <= r)) return seg[node];
        int mid = (st + en) / 2;
        T q1 = query(2*node, st, mid, l, r);
        T q2 = query(2*node+1, mid+1, en, l, r);
        return (q1+q2);
    }
};


void solve(){
    int n; cin >> n;
    vector<ll> a(n+1); rep(i, 1, n) cin >> a[i];
    
    vector<ll> b;
    b.push_back(0);
    int pt = 1;
    while (pt <= n && a[pt] == 0) pt++;
    while (pt <= n){
        int pt2 = pt;
        ll tot = 0;
        while (pt2 <= n && a[pt2] * a[pt] >= 0){
            tot += a[pt2];
            pt2++;
        }
        b.push_back(tot);
        pt = pt2;
    }

    if (b[1] == 0){ cout << 0 << "\n"; return;}


    for (ll &x: b) if (x < 0) x = -x;

    int sz = b.size() - 1;
    LazySegTree<Node> st(sz);
    vi l(sz+1), r(sz+1);
    rep(i, 1, sz){ l[i] = i - 1; r[i] = i + 1;}

    rep(i, 1, sz){
        st.update(i, b[i]);
    }

    // st.rangeUpdate(1, sz, -1);
    // rep(i, 1, sz) cout << st.query(i, i).mn << " ";
    // cout << "\n";

    ll ans = 0;
    forn(_, sz){
        Node nd = st.query(1, sz);
        ll x = nd.mn;
        int i = nd.pos;
        ans += x;
        // cout << "ans: " << ans << "\n";
        st.rangeUpdate(1, sz, -x);
        st.update(i, 1ll * 1e9 * maxn);
        // rep(i, 1, sz) cout << st.query(i, i).mn << " ";
        // cout << "\n";
        if (r[i] == sz+1){ r[l[i]] = sz+1; continue;}
        if (l[i] == 0){ l[r[i]] = 0; continue;}
        r[l[i]] = r[i];
        l[r[i]] = l[i];
        if ((r[i] - l[i] + 1) & 1){
            ll a = st.query(l[i], l[i]).mn, b = st.query(r[i], r[i]).mn;
            st.update(r[i], a + b);
            st.update(l[i], 0);
        }
        // rep(i, 1, sz) cout << st.query(i, i).mn << " ";
        // cout << "\n";
    }

    cout << ans << "\n";
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
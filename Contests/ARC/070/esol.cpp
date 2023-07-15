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
            seg[node].val += lazy[node];
            if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > pos) || (en < pos)) return;
        if ((st == pos) && (en == pos)){
            seg[node].val += val;
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
            if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > r) || (en < l)) return;
        if ((st >= l) && (en <= r)){
            seg[node].val += val;
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

    int find(ll val){
        return find(1, 1, sz, val);
    }

    int find(int st, int en, ll val){
        int node = 1;
        
    }

    int find(int node, int st, int en, ll val){
        if (lazy[node]){
            seg[node].val += lazy[node];
            if (st < en){
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (st == en) return 1;
        int mid = (st + en) / 2;
        if (seg[2 * node] >= val) return find(2 * node, st, mid, val);
        else return mid - st + 1 + find(2 * node + 1, mid+1, en, val - seg[2 * node]);
    }
};


LazySegTree<Node> st(7*maxn);

int cent, edge;

int recent(int x){
    int location = cent + x;
    if (location <= 0) return edge + location + 1;
    if (location > edge) return location - edge;
    return location;
}

void upd(int l, int r, ll val){
    int loc1 = recent(l), loc2 = recent(r);
    if (loc1 <= loc2){
        st.rangeUpdate(loc1, loc2, val);
    }
    else{
        st.rangeUpdate(loc1, edge, val);
        st.rangeUpdate(1, loc2, val);
    }
}

void upd(int l, ll val){
    upd(l, l, val);
}

ll qr(int pos){
    return st.query(recent(pos), recent(pos)).val;
}

int fnd(ll val){

}

void solve(){
    int n; cin >> n;
    vi l(n), r(n);
    forn(i, n) cin >> l[i] >> r[i];

    // preprocess
    // find a_1, a_2, ..., a_n such that
    // a_1 + r_1 - 1 >= a_2 + l_2  =>  a_1 >= a_2 + l_2 - r_1 + 1
    // a_1 + l_1 <= a_2 + r_2 - 1  => a_1 <= a_2 + r_2 - l_1 - 1

    vi u(n), v(n);
    rep(i, 1, n-1){
        u[i] = l[i] - r[i-1] + 1;
        v[i] = r[i] - l[i-1] - 1;
    }

    edge = 7*n;
    cent = 1;
    
    upd(0, 0);
    upd(1, 1);

    ll best = 0;

    rep(i, 1, n-1){
        ll l0 = qr(0);
        ll l1 = qr(1);
        ll l2 = qr(2);
        ll best_left = l0 - l[i];
        ll best_right = l1 + r[i] - 1;

        if (best_right < 0){
            // best is from best_right until 0 or st[1]
            if (0 <= l2 - 1){
                // best until 0 would be 0
                // 1 until -> would be +1
            }
        }
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
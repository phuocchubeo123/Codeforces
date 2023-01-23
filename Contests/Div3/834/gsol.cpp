#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
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
    Node(){val = 1e9;}
};

Node operator+(const Node& x, const Node& y){
    Node res;
    res.val = min(x.val, y.val);
    return res;
}

template <typename T>
struct SegTree{
    int sz;
    vector<T> seg;
  
    SegTree(int s){
        sz = s;
        seg.resize(4 * s);
    }

    void update(int pos, T val){
        update(1, 1, sz, pos, val);
    }

    void update(int node, int st, int en, int pos, T val){
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

    T query(int l, int r){
        return query(1, 1, sz, l, r);
    }

    T query(int node, int st, int en, int l, int r){
        if ((st > r) || (en < l)) return T();
        if ((l <= st) && (en <= r)) return seg[node];
        int mid = (st + en) / 2;
        T q1 = query(2*node, st, mid, l, r);
        T q2 = query(2*node+1, mid+1, en, l, r);
        return (q1+q2);
    }

    // int find(int val){
    //     return find(1, 1, sz, val);
    // }

    // int find(int node, int st, int en, int val){
    //     if (st == en) return 1;
    //     int mid = (st + en) / 2;
    //     if (seg[2 * node] >= val) return find(2 * node, st, mid, val);
    //     else return mid - st + 1 + find(2 * node + 1, mid+1, en, val - seg[2 * node]);
    // }
};

struct Node2{
    ll val;
    Node2(int a){val = 1ll * a;}
    Node2(ll a){val = a;}
    Node2(){val = 1e9;}
};

Node2 operator+(const Node2& x, const Node2& y){
    Node2 res;
    res.val = min(x.val, y.val);
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

    void update(int pos, T val){
        update(1, 1, sz, pos, val);
    }

    void update(int node, int st, int en, int pos, T val){
        if (lazy[node]){
            seg[node].val += lazy[node];
            if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > pos) || (en < pos)) return;
        if ((st == pos) && (en == pos)){
            seg[node] = val;
            return;
        }
        int mid = (st + en) / 2;
        update(2*node, st, mid, pos, val);
        update(2*node+1, mid+1, en, pos, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }

    void rangeUpdate(int l, int r, int val){
        rangeUpdate(1, 1, sz, l, r, val);
    }

    void rangeUpdate(int node, int st, int en, int l, int r, int val){
        if (lazy[node] != 0){
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
        if (lazy[node] != 0){
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

    int walk(){
        return walk(1, 1, sz);
    }

    int walk(int node, int st, int en){
        if (lazy[node] != 0){
            seg[node].val += lazy[node];
            if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if (st == en) return st;
        int mid = (st + en) / 2;
        if (seg[2*node].val + lazy[2*node] == 0) return walk(2*node, st, mid);
        else return walk(2*node+1, mid+1, en);
    }
};


void solve(){
    int n; cin >> n;
    vi a(n+1, 0); rep(i, 1, n/2) cin >> a[2 * i];

    vi cnt(n+1);
    rep(i, 1, n) cnt[a[i]]++;
    rep(i, 1, n) if (cnt[i] > 1){ cout << -1 << "\n"; return;}
    vi b(n+1, 0);
    rep(i, 1, n) if (a[i] != 0) b[a[i]] = -1;
    rep(i, 1, n) if (b[i] == 0) b[i] = 1;

    // rep(i, 1, n) cout << a[i] << " ";
    // cout << "\n";

    // rep(i, 1, n) cout << b[i] << " ";
    // cout << "\n";
    
    int curr = 0;
    LazySegTree<Node2> pre(n);
    rep(i, 1, n){
        curr += b[i];
        if (curr < 0){ cout << -1 << "\n"; return;}
        pre.update(i, Node2(curr));
    }

    // rep(i, 1, n) cout << pre.query(i, i).val << " ";
    // cout << "\n";

    SegTree<Node> minPos(n);
    rep(i, 1, n){
        if (a[i] != 0) minPos.update(a[i], Node(i));
        else minPos.update(a[i], Node());
    }

    // rep(i, 1, n) cout << minPos.query(i, i).val << " ";
    // cout << "\n";


    rep(i, 1, n){
        if (b[i] == -1) continue;
        int firstZero = pre.walk();
        // cout << firstZero << "\n";
        Node pos = minPos.query(1, firstZero);
        // cout << pos.val << "\n";
        a[pos.val-1] = i;
        // rep(i, 1, n) cout << a[i] << " ";
        // cout << "\n";
        minPos.update(a[pos.val], Node());
        // rep(i, 1, n) cout << minPos.query(i, i).val << " ";
        // cout << "\n";
        pre.rangeUpdate(i+1, a[pos.val]-1, -1);
        pre.update(i, Node2());
        pre.update(a[pos.val], Node2());
        // rep(i, 1, n) cout << pre.query(i, i).val << " ";
        // cout << "\n";
        // return;
    }

    rep(i, 1, n) cout << a[i] << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}
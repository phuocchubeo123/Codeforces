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
    vector<int> lazy;
  
    LazySegTree(int s){
        sz = s;
        seg.resize(4 * s);
        lazy.resize(4 * s);
    }

    void update(int pos, int val){
        update(1, 1, sz, pos, val);
    }

    void update(int node, int st, int en, int pos, int val){
        if (lazy[node]){
            seg[node].val += lazy[node];
            if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > pos) || (en < pos)) return;
        if ((st == pos) && (en == pos)){
            seg[node].val = val ;
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

    // int find(int val){
    //     return find(1, 1, sz, val);
    // }

    // int find(int node, int st, int en, int val){
    //     if (lazy[node]){
    //         //seg[node].update(lazy[node])
    //         if (st < en){
    //             lazy[2*node] += lazy[node];
    //             lazy[2*node+1] += lazy[node];
    //             //dump lazy in 2*node and 2*node+1
    //         }
    //         lazy[node] = 0;
    //     }
    //     if (st == en) return 1;
    //     int mid = (st + en) / 2;
    //     if (seg[2 * node] >= val) return find(2 * node, st, mid, val);
    //     else return mid - st + 1 + find(2 * node + 1, mid+1, en, val - seg[2 * node]);
    // }
};


void solve(){
    int n; cin >> n;
    int q; cin >> q;
    vi a(n+1); rep(i, 1, n) cin >> a[i];
    LazySegTree<Node> st(n);
    rep(i, 1, n) st.update(i, 0);

    forn(_, q){
        int qr; cin >> qr;
        if (qr == 1){
            int l, r; cin >> l >> r;
            st.rangeUpdate(l, r, 1);
        }
        else{
            int x; cin >> x;
            int times = st.query(x, x).val;
            while (times > 0){
                int after = 0;
                int before = a[x];
                forn(i, 11){
                    after += before % 10;
                    before /= 10;
                }
                if (after == a[x]){ times--; break;}
                a[x] = after;
                times--;
            }
            st.update(x, times);
            cout << a[x] << "\n";
        }

        // rep(i, 1, n) cout << st.query(i, i).val << " ";
        // cout << "\n";
        // rep(i, 1, n) cout << a[i] << " ";
        // cout << "\n";
    }
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
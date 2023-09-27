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
const ll INF = 1e13;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

struct LazySegTree{
    int sz;
    vector<ll> seg;
    vector<ll> l1;
    vector<ll> l2;
    vector<ll> mx;
    vector<ll> ml1;
    vector<ll> ml2;
  
    LazySegTree(int s){
        sz = s;
        seg.resize(4*s);
        l1.resize(4*s);
        l2.resize(4*s);
        mx.resize(4*s);
        ml1.resize(4*s);
        ml2.resize(4*s);
        for (int i = 0; i < 4*s; i++){
            seg[i] = 0;
            l2[i] = -INF;
            l1[i] = 0;
            mx[i] = 0;
            ml1[i] = 0;
            ml2[i] = -INF;
        }
    }

    void dump(int node, int st, int en){
        mx[node] = max(seg[node] + ml1[node], mx[node]);
        mx[node] = max(mx[node], ml2[node]);
        seg[node] = max(seg[node] + l1[node], l2[node]);
        if (st == en){
            l1[node] = 0;
            l2[node] = -INF;
            ml1[node] = 0;
            ml2[node] = -INF;
            return;
        }
        ml2[2*node] = max(l2[2*node] + ml1[node], ml2[2*node]);
        ml2[2*node] = max(ml2[node], ml2[2*node]);
        ml1[2*node] = max(l1[2*node] + ml1[node], ml1[2*node]);
        l2[2*node] = max(l2[2*node] + l1[node], l2[node]);
        l1[2*node] += l1[node];

        ml2[2*node+1] = max(l2[2*node+1] + ml1[node], ml2[2*node+1]);
        ml2[2*node+1] = max(ml2[2*node+1], ml2[node]);
        ml1[2*node+1] = max(l1[2*node+1] + ml1[node], ml1[2*node]);
        l2[2*node+1] = max(l2[2*node+1] + l1[node], l2[node]);
        l1[2*node+1] += l1[node];

        ml1[node] = 0;
        ml2[node] = -INF;
        l1[node] = 0;
        l2[node] = -INF;
    }

    void rangeUpdate1(int l, int r, ll val){
        rangeUpdate1(1, 1, sz, l, r, val);
    }

    void rangeUpdate1(int node, int st, int en, int l, int r, ll val){
        // cout << node << " " << st << " " << en << "\n";
        dump(node, st, en);
        if ((st > r) || (en < l)) return;
        if ((st >= l) && (en <= r)){
            l1[node] = val;
            ml1[node] = max(ml1[node], val);
            dump(node, st, en);
            return;
        }
        int mid = (st + en) / 2;
        rangeUpdate1(2*node, st, mid, l, r, val);
        rangeUpdate1(2*node+1, mid+1, en, l, r, val);
        seg[node] = max(seg[2*node], seg[2*node+1]);
        mx[node] = max(mx[node], seg[node]);
    }

    void rangeUpdate2(int l, int r, ll val){
        rangeUpdate2(1, 1, sz, l, r, val);
    }

    void rangeUpdate2(int node, int st, int en, int l, int r, ll val){
        // cout << node << " " << st << " " << en << "\n";
        dump(node, st, en);
        if ((st > r) || (en < l)) return;
        if ((st >= l) && (en <= r)){
            l2[node] = val;
            ml2[node] = val;
            dump(node, st, en);
            return;
        }
        int mid = (st + en) / 2;
        rangeUpdate2(2*node, st, mid, l, r, val);
        rangeUpdate2(2*node+1, mid+1, en, l, r, val);
        seg[node] = max(seg[2*node], seg[2*node+1]);
        mx[node] = max(mx[node], seg[node]);
    }

    ll query(int l, int r){
        return query(1, 1, sz, l, r);
    }

    ll query(int node, int st, int en, int l, int r){
        // cout << node << " " << st << " " << en << "\n";
        dump(node, st, en);
        if ((st > r) || (en < l)) return 0;
        if ((l <= st) && (en <= r)) return mx[node];
        int mid = (st + en) / 2;
        ll q1 = query(2*node, st, mid, l, r);
        ll q2 = query(2*node+1, mid+1, en, l, r);
        return max(q1, q2);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    // cout << n << " " << q << "\n";

    LazySegTree st(n);

    for (int i = 0; i < q; i++){
        int t; cin >> t;
        if (t == 1){
            // cout << "type1\n"; 
            int l, r; ll c;
            cin >> l >> r >> c;
            st.rangeUpdate1(l, r, c);
        }

        else if (t == 2){
            // cout << "type2\n"; 
            int l, r; ll d;
            cin >> l >> r >> d;
            st.rangeUpdate2(l, r, d);
        }

        else{
            // cout << "type3\n"; 
            int l, r; cin >> l >> r;
            cout << max(st.query(l, r), 0ll) << "\n";
        }

        // cout << "seg\n";
        // for (int i = 0; i < 4*n; i++) cout << st.seg[i] << " ";
        // cout << "\n";
        // cout << "mx\n";
        // for (int i = 0; i < 4*n; i++) cout << st.mx[i] << " ";
        // cout << "\n";
        // cout << "l1\n";
        // for (int i = 0; i < 4*n; i++) cout << st.l1[i] << " ";
        // cout << "\n";
        // cout << "l2\n";
        // for (int i = 0; i < 4*n; i++) cout << st.l2[i] << " ";
        // cout << "\n";
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
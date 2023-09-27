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
const ll INF = 1e12;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

struct LazySegTree{
    int sz;
    vector<ll> seg;
    vector<ll> lz; 

    LazySegTree(int s){
        sz = s;
        seg.resize(4*s);
        lz.resize(4*s);
        for (int i = 0; i < 4*s; i++){
            seg[i] = INF;
            lz[i] = 0;
        }
    }

    void dump(int n, ll st, ll en){
        seg[n] += lz[n];
        if (st == en){
            lz[n] = 0;
            return;
        }
        lz[2*n] += lz[n];
        lz[2*n+1] += lz[n];
        lz[n] = 0;
    }

    void upd(ll p, ll val){
        upd(1, 1, sz, p, val);
    }

    void upd(int n, ll st, ll en, ll p, ll val){
        dump(n, st, en);
        if (st > p || en < p) return;
        if (st == en){
            seg[n] = val;
            return;
        }
        int m = (st + en) / 2;
        upd(2*n, st, m, p, val);
        upd(2*n+1, m+1, en, p, val);
        seg[n] = min(seg[2*n], seg[2*n+1]);
    }

    void update(ll l, ll r, ll val){
        update(1, 1, sz, l, r, val);
    }

    void update(int n, ll st, ll en, ll l, ll r, ll val){
        dump(n, st, en);
        if (st > r || en < l) return;
        if (st >= l && en <= r){
            lz[n] += val;
            dump(n, st, en);
            return;
        }
        int m = (st + en) / 2;
        update(2*n, st, m, l, r, val);
        update(2*n+1, m+1, en, l, r, val);
        seg[n] = min(seg[2*n], seg[2*n+1]);
    }

    ll query(ll l, ll r){
        return query(1, 1, sz, l, r);
    }

    ll query(ll n, ll st, ll en, ll l, ll r){
        dump(n, st, en);
        if (st > r || en < l) return INF;
        if (st >= l && en <= r) return seg[n];
        int m = (st + en) / 2;
        ll q1 = query(2*n, st, m, l, r);
        ll q2 = query(2*n+1, m+1, en, l, r);
        return min(q1, q2);
    }
};

void solve(){
    ll n, q; cin >> n >> q;
    ll a, b; cin >> a >> b;
    vector<ll> x(q);
    for (int i = 0; i < q; i++) cin >> x[i];

    // ending at x_0
    LazySegTree st(n);
    st.upd(a, abs(x[0] - b));
    st.upd(b, abs(x[0] - a));

    LazySegTree st2(n);
    st2.upd(a, abs(x[0] - b));
    st2.upd(b, abs(x[0] - a));
    for (ll i = 1; i <= n; i++){
        st2.update(i, i, i - x[0]);
    }

    LazySegTree st3(n);
    st3.upd(a, abs(x[0] - b));
    st3.upd(b, abs(x[0] - a));
    for (ll i = 1; i <= n; i++){
        st3.update(i, i, x[0] - i);
    }

    // for (int i = 1; i <= n; i++){
    //     cout << st.query(i, i) << " ";
    // }
    // cout << "\n";
    // for (int i = 1; i <= n; i++){
    //     cout << st2.query(i, i) << " ";
    // }
    // cout << "\n";
    // for (int i = 1; i <= n; i++){
    //     cout << st3.query(i, i) << " ";
    // }
    // cout << "\n";

    for (int i = 1; i < q; i++){
        st.update(1, n, abs(x[i] - x[i-1]));
        // cout << "\n";
        st2.update(1, n, x[i-1] - x[i]);
        st3.update(1, n, x[i] - x[i-1]);

        ll x1 = st2.query(x[i], n);
        ll x2 = st3.query(1, x[i]);
        ll u = min(x1, x2);
        st.upd(x[i-1], u);
        st2.update(1, n, abs(x[i] - x[i-1]));
        st3.update(1, n, abs(x[i] - x[i-1]));
        st2.upd(x[i-1], u + x[i-1] - x[i]);
        st3.upd(x[i-1], u + x[i] - x[i-1]);

        // for (int i = 1; i <= n; i++){
        //     cout << st.query(i, i) << " ";
        // }
        // cout << "\n";
        // for (int i = 1; i <= n; i++){
        //     cout << st2.query(i, i) << " ";
        // }
        // cout << "\n";
        // for (int i = 1; i <= n; i++){
        //     cout << st3.query(i, i) << " ";
        // }
        // cout << "\n";
    }

    cout << st.query(1, n) << "\n";
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
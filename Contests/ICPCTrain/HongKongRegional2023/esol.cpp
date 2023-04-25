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

const int maxn = 1e6 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

struct Node{
    ll val;
    ll lazy;
    ll cnt;
    Node(){val = INF; lazy = 0; cnt = 1;}
};

Node operator+(const Node& x, const Node& y){
    Node res;
    res.val = min(x.val + x.lazy, y.val + y.lazy);
    res.cnt = 0;
    if (x.val + x.lazy == res.val){
        res.cnt += x.cnt;
    }
    if (y.val + y.lazy == res.val){
        res.cnt += y.cnt;
    }
    return res;
}


template <typename T>
struct LazySegTree{
    int sz;
    vector<T> seg;

    LazySegTree(int s){
        sz = s;
        seg.resize(4 * s);
        build(1, 1, s);
    }

    void build(int node, int st, int en){
        if (st == en){
            seg[node].val = 0;
            seg[node].lazy = 0;
            seg[node].cnt = 1;
            return;
        }

        int mid = (st + en) / 2;
        build(2*node, st, mid);
        build(2*node+1, mid+1, en);
        seg[node] = seg[2*node] + seg[2*node+1];
    }

    void rangeUpdate(int l, int r, int val){
        rangeUpdate(1, 1, sz, l, r, val);
    }

    void rangeUpdate(int node, int st, int en, int l, int r, int val){
        if (seg[node].lazy != 0){
            seg[node].val += seg[node].lazy;
            if (st != en){
                seg[2*node].lazy += seg[node].lazy;
                seg[2*node+1].lazy += seg[node].lazy;
            }
            seg[node].lazy = 0;
        }
        if ((st > r) || (en < l)) return;
        if ((st >= l) && (en <= r)){
            seg[node].val += val;
            if (st != en){seg[2*node].lazy += val, seg[2*node+1].lazy += val;}
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
        if (seg[node].lazy != 0){
            seg[node].val += seg[node].lazy;
            if (st != en){
                seg[2*node].lazy += seg[node].lazy;
                seg[2*node+1].lazy += seg[node].lazy;
            }
            seg[node].lazy = 0;
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
    int n, k;
    cin >> n >> k;
    vi a(n+1);
    vvi ind(maxn);
    rep(i, 1, n){
        cin >> a[i];
        ind[a[i]].push_back(i);
    }

    vector<pair<int, int>> curr(maxn), next(maxn);

    rep(i, 1, n){
        curr[i] = {-1, -1};
        next[i] = {-1, -1};
    }

    forn(i, maxn){
        if (ind[i].empty()) continue;

        if (k-1 < ind[i].size()){
            curr[ind[i][k-1]] = {1, ind[i][0]};
        }
        rep(j, k, ind[i].size()-1){
            curr[ind[i][j]] = {ind[i][j-k]+1, ind[i][j-k+1]};
        }

        if (k < ind[i].size()){
            next[ind[i][k]] = {1, ind[i][0]};
        }
        rep(j, k+1, ind[i].size()-1){
            next[ind[i][j]] = {ind[i][j-k-1]+1, ind[i][j-k]};
        }
    }

    vector<int> curr_index(maxn);

    forn(i, maxn){
        curr_index[i] = ind[i].size() - 1;
    }

    LazySegTree<Node> st(n);

    forn(i, maxn){
        if (ind[i].empty()) continue;
        int last = ind[i].back();
        if (curr[last].first != -1){
            // cout << curr[last].first << " " << curr[last].second << "\n";
            st.rangeUpdate(curr[last].first, curr[last].second, 1);
            // cout << "\n";
        }
    }
    
    // rep(i, 1, n) cout << st.query(i, i).val << " ";
    // cout << "\n";

    ll ans = 0;
    Node mn = st.query(1, n);
    if (mn.val == 0) ans += mn.cnt;

    per(i, n-1, 1){
        if (curr[i+1].first != -1){
            st.rangeUpdate(curr[i+1].first, curr[i+1].second, -1);
        }
        if (next[i+1].first != -1){
            st.rangeUpdate(next[i+1].first, next[i+1].second, 1);
        }

        mn = st.query(1, i);
        // rep(i, 1, n) cout << st.query(i, i).val << " ";
        // cout << "\n";
        if (mn.val == 0)  ans += mn.cnt;
    }

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
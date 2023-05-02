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

struct Node1{
    ll val;
    Node1(){val = 0;}
};

Node1 operator+(const Node1& x, const Node1& y){
    Node1 res;
    res.val = max(x.val, y.val);
    return res;
}

struct Node2{
    ll val; 
    Node2(){val = 0;}
};

Node2 operator+(const Node2& x, const Node2& y){
    Node2 res;
    res.val = x.val + y.val;
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

    void update(int pos, int val){
        update(1, 1, sz, pos, val);
    }

    void update(int node, int st, int en, int pos, int val){
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

    vector<pair<int, pair<int, int>>> deconstruct(int node, int st, int en){
        
    }

    T find_right(int i, int x){

        return T();
    }

    T find_right(int node, int st, int en, int i, int x){
        if (st == en) return seg[node];
        if (en < x) return T();
        if (st < x){
            int mid = 
        }
    }

    T find_left(int i, int x){
        return T();
    }
};


void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n+1); rep(i, 1, n) cin >> a[i];
    vi ar(n+1); rep(i, 1, n) ar[a[i]] = i;
    vi b(m+1); rep(i, 1, m) cin >> b[i];
    set<int> l;
    rep(i, 1, k){
        int L; cin >> L;
        l.insert(L);
    }

    SegTree<Node1> st(n);
    rep(i, 1, n) st.update(i, a[i]);

    vi cnt(n+1); rep(i, 1, n) cnt[i] = 1;
    rep(i, 1, m) cnt[b[i]]--;
    vi need; rep(i, 1, n) if (cnt[i] == 1) need.push_back(i);
    sort(all(need)); reverse(all(need));

    for (int x: need){
        int i = ar[x];
        Node1 u = st.find_right(i, x);
        Node1 v = st.find_left(i, x);
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
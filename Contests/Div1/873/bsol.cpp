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

const int maxn = 3e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vi a(maxn);

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
            seg[node].val += val ;
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
};

void solve(){
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    vi will(n);
    forn(i, n) will[i] = i+1;
    sort(all(will), [](int x, int y){
        return a[x] < a[y];
    });

    vi l(n+2), r(n+2);
    rep(i, 1, n) l[i] = i-1;
    rep(i, 1, n) r[i] = i+1;
    r[n+1] = n+1;
    l[0] = 0;

    vi rev_will = will;
    reverse(all(rev_will));
    for (int i: rev_will){
        l[r[i]] = l[i];
        r[l[i]] = r[i];
    }

    // rep(i, 1, n) cout << l[i] << " ";
    // cout << "\n";
    // rep(i, 1, n) cout << r[i] << " ";
    // cout << "\n";

    vi l2(n+2), r2(n+2);
    rep(i, 1, n) l2[i] = i;
    rep(i, 1, n) r2[i] = i;
    l2[0] = 1;
    r2[n+1] = n+1;
    vi marked(n+2, 0);

    SegTree<Node> st(n);

    ll ans = 0;
    for (int i: will){
        int u = i - l[i], v = r[i] - i;
        // from l[i] + 1 to i
        ans += 1ll * u * (u - 1) / 2 * v;
        // from 0 to l[i]
        int x = l2[l[i]] - 1;
        ans += 1ll * (l[i] - x) * (u-1) * v;
        ans += 1ll * x * u * v;

        // cout << "ans so far: " << i << " " << l[i] << " " << r[i] << " " << l2[l[i]] << " " << ans << "\n";

        if (marked[i-1] == 1 && marked[i+1] == 1){
            l2[r2[i+1]] = l2[i-1];
            r2[l2[i-1]] = r2[i+1];
        }       
        else if (marked[i-1] == 1){
            l2[i] = l2[i-1];
            r2[l2[i-1]] = i;
        }
        else if (marked[i+1] == 1){
            r2[i] = r2[i+1];
            l2[r2[i+1]] = i;
        }
        marked[i] = 1;


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
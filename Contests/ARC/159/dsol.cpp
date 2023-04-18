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

    void operator+=(const Node& other){
        val = max(val, other.val);
    }
};

Node operator+(const Node& x, const Node& y){
    Node res;
    res.val = max(x.val, y.val);
    return res;
}

template <typename T>
struct LazySegTree{
    int sz;
    vector<T> seg;
    vector<T> lazy;
  
    LazySegTree(int s){
        sz = s;
        seg.resize(4 * s);
        lazy.resize(4 * s);
    }

    void update(int pos, int val){
        update(1, 1, sz, pos, val);
    }

    void update(int node, int st, int en, int pos, int val){
        seg[node] = seg[node] + lazy[node];
        if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
        lazy[node] = 0;

        if ((st > pos) || (en < pos)) return;
        if ((st == pos) && (en == pos)){
            seg[node] = seg[node] + T(val);
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
        seg[node] = seg[node] + lazy[node];
        if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
        lazy[node] = 0;
        if ((st > r) || (en < l)) return;
        if ((st >= l) && (en <= r)){
            seg[node] = seg[node] + T(val);
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
        seg[node] = seg[node] + lazy[node];
        if (st < en){lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];}
        lazy[node] = 0;

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
    ll n,i,j,pos,posl,ma,ma1,ma2;
    cin >> n;
    ll l[n+1],r[n+1],ans;
    vector<ll> v;
    for(i=1;i<=n;i++){
        cin >> l[i] >> r[i];
        v.push_back(r[i]);
    }
    sort(v.begin(),v.end());
    LazySegTree<Node> seg1(n),seg2(n);
    for(i=1;i<=n;i++){
        seg1.update(i,v[n-1]-v[i-1]);
        seg2.update(i,0);
    }
    ans=0;
    for(i=1;i<=n;i++){
        pos=lower_bound(v.begin(),v.end(),r[i])-v.begin();
        pos+=1;
        posl=lower_bound(v.begin(),v.end(),l[i])-v.begin();
        posl+=1;
        ma1=seg2.query(1,posl-1).val;
        ma2=seg1.query(posl,pos-1).val;
        ma=max(ma1+(r[i]-l[i]+1),ma2+r[i]-v[n-1]);
        ans=max(ans,ma);
        seg2.update(pos,ma);
        seg1.update(pos,ma+v[n-1]-r[i]);
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
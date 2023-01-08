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
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T a, T b){while(b){b^=a^=b^=a%=b;} return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

struct Node{
    int mn;
    Node(int a){mn = a;}
    Node(){mn = maxn;}
};

Node operator+(const Node& left, const Node& right){
    Node res;
    res.mn = min(left.mn, right.mn);
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
            seg[node] = T(val) ;
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

    int find(int val){
        return find(1, 1, sz, val);
    }

    int find(int node, int st, int en, int val){
        if (st == en) return 1;
        int mid = (st + en) / 2;
        if (seg[2 * node] >= val) return find(2 * node, st, mid, val);
        else return mid - st + 1 + find(2 * node + 1, mid+1, en, val - seg[2 * node]);
    }
};

vi pos[maxn];
SegTree<Node> r(maxn);

ll solve(vi a, int n, int k){
    SegTree<ll> l(n);
    rep(i, 1, n) l.update(i, 0);

    vi r_best(n+1);
    per(i, n, 1){
        r_best[i] = r.query(a[i] + 1, min(a[i] + k, maxn)).mn;
        r.update(a[i], i);
    }
    rep(i, 1, n) r.update(a[i], maxn);

    rep(i, 1, n) pos[a[i]].clear();
    rep(i, 1, n) pos[a[i]].push_back(i);
    vector<int> b = a;
    sort(all(b));
    auto it = unique(all(b));
    b.resize(distance(b.begin(), it));
    int pt = 1;
    ll ans = 0;
    for (int x: b){
        while (pt <= n && b[pt] < x - k){
            for (int j: pos[b[pt]]){
                int qr = l.query(j, j);
                l.update(j, 0);
                int k = r_best[j];
                if (k == -1) continue;
                l.update(r_best[j], l.query(k, k) + qr);
            }
            pt++;
        }
        for (int i: pos[x]){
            ans += l.query(1, i-1);
            // cout << "ans: " << ans << "\n";
        }
        for (int i: pos[x]){
            l.update(i, l.query(i, i) + 1);
        }
    }
    return ans;
}

vi cnt(maxn, 0);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        int n, k; cin >> n >> k;
        vector<int> a(n+1); rep(i, 1, n) cin >> a[i];
        ll ANS = 0;
        ANS += solve(a, n, k);
        reverse(a.begin()+1, a.end());
        ANS += solve(a, n, k);
        rep(i, 1, n){
            cnt[a[i]]++;
            ANS += 1ll * cnt[a[i]];
        }
        rep(i, 1, n) cnt[a[i]] = 0;
        cout << ANS << "\n";
    }
}
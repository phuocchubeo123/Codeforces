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

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count()); //willy108
vector<ll> hh;

void prehash(){
    forn(i, maxn) hh.push_back(rng()%(1ll<<60));
    sort(all(hh));
    // forn(i, 5) cout << hh[i] << " ";
    // cout << "\n";
}

map<ll, int> encode;
void makeUnique(vector<ll> &a){
    sort(all(a));
    auto it = unique(all(a));
    a.resize(distance(a.begin(), it));

    forn(i, a.size()){
        encode[a[i]] = i;
    }
}

struct Node{
    ll val;
    Node(int a){val = 1ll * a;}
    Node(ll a){val = a;}
    Node(){val = 0;}
};

Node operator+(const Node& x, const Node& y){
    Node res;
    res.val = x.val ^ y.val;
    return res;
}


template<typename T>
struct node
{
    T val;
    node<T>* left, *right;
  
    node() {}
    node(node<T>* l, node<T>* r, T v)
    {
        left = l;
        right = r;
        val = v;
    }
};
  

template<typename T>
struct PersistentSegTree{
    node<T>* version[maxn];
    int sz;

    PersistentSegTree(int n){
        sz = n;
        version[0] = new node<T>(NULL, NULL, T());
        build(version[0], 0, sz-1);
    }

    void build(node<T>* cur,int l,int r)
    {
        if (l==r){ cur->val = T(); return;}
        int mid = (l+r) / 2;
        cur->left = new node<T>(NULL, NULL, T());
        cur->right = new node<T>(NULL, NULL, T());
        build(cur->left, l, mid);
        build(cur->right, mid+1, r);
        cur->val = cur->left->val + cur->right->val;
    }

    void update(int ver, int pos, T val){
        version[ver] = new node<T>(NULL, NULL, T());
        upgrade(version[ver-1], version[ver], 0, sz-1, pos, val);
    }

    void upgrade(node<T>* prev, node<T>* cur, int l, int r, int pos, T val){
        if (pos > r or pos < l or l > r) return;
        if (l == r){ cur->val = val; return;}
        int mid = (l+r) / 2;
        if (pos <= mid){
            cur->right = prev->right;
            cur->left = new node<T>(NULL, NULL, T());
            upgrade(prev->left,cur->left, l, mid, pos, val);
        }
        else{
            cur->left = prev->left;
            cur->right = new node<T>(NULL, NULL, T());
            upgrade(prev->right, cur->right, mid+1, r, pos, val);
        }
        cur->val = cur->left->val + cur->right->val;
    }

    T query(int ver, int st, int en){
        node<T>* cur = version[ver];
        return query(cur, 0, sz-1, st, en);
    }

    T query(node<T>* cur, int l, int r, int st, int en)
    {
        if (st > r or en < l or l > r) return T();
        if (st <= l and r <= en) return cur->val;
        int mid = (l+r) / 2;
        T q1 = query(cur->left, l, mid, st, en);
        T q2 = query(cur->right, mid+1, r, st, en);
        return q1+q2;
    }

    int walk(int ver1, int ver2){
        node<T>* u = version[ver1];
        node<T>* v = version[ver2];
        // cout << u->val.val << " " << v->val.val << " " << (u->val.val == v->val.val) << "\n";
        // return 0;
        if (u->val.val == v->val.val){
            // cout << "none\n";
            return -1;
        }
        return walk(u, v, 0, sz-1);
    }

    int walk(node<T>* u, node<T>* v, int l, int r){
        if (l == r) return l;
        int mid = (l+r) / 2;
        if (u->left->val.val == v->left->val.val) return walk(u->right, v->right, mid+1, r);
        else return walk(u->left, v->left, l, mid);
    }
};

void solve(){
    prehash();
    int n; cin >> n;
    vector<ll> a(n);
    forn(i, n) cin >> a[i];
    vector<ll> b = a;
    makeUnique(b);

    // forn(i, n) cout << encode[a[i]] << " ";
    // cout << "\n";

    PersistentSegTree<Node> seg(maxn);
    forn(i, n){
        Node x = seg.query(i, encode[a[i]], encode[a[i]]);
        seg.update(i+1, encode[a[i]], x + Node(hh[encode[a[i]]]));
        // forn(j, n) cout << seg.query(i+1, j, j).val << " ";
        // cout << "\n";
    }

    // cout << seg.version[0]->val.val << "\n";
    // cout << seg.version[4]->val.val << "\n";

    // return;

    int q; cin >> q;
    ll ans = 0;
    forn(_, q){
        ll aa, bb; cin >> aa >> bb;
        ll l = ans ^ aa, r = ans ^ bb;
        // cout << l << " " << r << "\n";
        int x = seg.walk(l-1, r);
        ans = (x == -1) ? 0: b[x];
        cout << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
}
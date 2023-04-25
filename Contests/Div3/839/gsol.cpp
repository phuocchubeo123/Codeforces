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
    ll mx;
    Node(ll a){mx = a;}
    Node(){mx = 0;}
};

Node operator+(const Node& left, const Node& right){
    Node res;
    res.mx = max(left.mx, right.mx);
    return res;
}

struct SegTree{
  int sz;
  vector<Node> seg;
  
  SegTree(int s, int lz=0){
    sz = s;
    seg.resize(4 * s);
  }

  void update(int pos, int val){
    update(1, 1, sz, pos, val);
  }

  void update(int node, int st, int en, int pos, int val){
    if ((st > pos) || (en < pos)) return;
    if ((st == pos) && (en == pos)){
      seg[node].mx += val;
      return;
    }
    int mid = (st + en) / 2;
    update(2*node, st, mid, pos, val);
    update(2*node+1, mid+1, en, pos, val);
    seg[node] = seg[2*node] + seg[2*node+1];
  }

  Node query(int l, int r){
    return query(1, 1, sz, l, r);
  }

  Node query(int node, int st, int en, int l, int r){
    if ((st > r) || (en < l)) return Node();
    if ((l <= st) && (en <= r)) return seg[node];
    int mid = (st + en) / 2;
    Node q1 = query(2*node, st, mid, l, r);
    Node q2 = query(2*node+1, mid+1, en, l, r);
    return (q1+q2);
  }

//   int find(int val){
//     return find(1, 1, sz, val);
//   }

//   int find(int node, int st, int en, int val){
//     if (st == en) return 1;
//     int mid = (st + en) / 2;
//     if (seg[2 * node] >= val) return find(2 * node, st, mid, val);
//     else return mid - st + 1 + find(2 * node + 1, mid+1, en, val - seg[2 * node]);
//   }
};

void solve(){
    ll n; cin >> n;
    ll x, y; cin >> x >> y;
    vector<ll> a(n+1); a[0] = 0; rep(i, 1, n) cin >> a[i]; sort(all(a));
    
    vector<ll> need(n+1);
    rep(i, 1, n){
        need[i] = max(a[i] - i + 1, need[i-1]);
    }
    need[0] = 0;

    // rep(i, 0, n) cout << need[i] << " ";
    // return;
    
    ll ans = 0;

    while (true){
        forn(_, 3){
            // cout << x << " " << ans << "\n";
            ll l = 0, r = n;
            while (l < r){
                ll m = (l+r+1) / 2;
                if (x < need[m]) r = m-1;
                else l = m;
            }

            if (x + l >= y){
                ans += y - x;
                cout << ans << "\n";
                return;
            }

            if (x + 2 * l - n <= x){
                cout << -1 << "\n";
                return;
            }

            x += 2 * l - n;
            ans += n;
        }

        // cout << "one " << x << " " << ans << "\n";
        ll l = 0, r = n;
        while (l < r){
            ll m = (l+r+1) / 2;
            if (x < need[m]) r = m-1;
            else l = m;
        }
        // cout << l << "\n";

        if (l == n){
            ans += ((y - x) / n) * n;
            x += ((y - x) / n) * n;
            continue;
        }

        if (x + l >= y){
            ans += y - x;
            cout << ans << "\n";
            return;
        }

        if (x + 2 * l - n <= x){
            cout << -1 << "\n";
            return;
        }

        ll rounds = min((y - x - l) / (2 * l - n), (need[l+1] - x) / (2 * l - n));
        x += (2 * l - n) * rounds;
        ans += n * rounds;
    }
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
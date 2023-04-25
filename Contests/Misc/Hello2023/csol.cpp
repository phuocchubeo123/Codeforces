#include <bits/stdc++.h>
using namespace std;

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

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

struct Node{
    ll mn;
    int id;
    Node(ll a, int i){mn = a; id = i;}
    Node(){mn = -1e9 - 5; id = -1;}
};

Node operator+(const Node& left, const Node& right){
    Node res;
    res.mn = max(left.mn, right.mn);
    if (left.mn < right.mn) res.id = right.id;
    else res.id = left.id;
    return res;
}

struct SegTree{
  int sz;
  vector<Node> seg;
  
  SegTree(int s, int lz=0){
    sz = s;
    seg.resize(8 * s);
  }

  void update(int pos, ll val){
    update(1, 1, sz, pos, val);
  }

  void update(int node, int st, int en, int pos, ll val){
    if ((st > pos) || (en < pos)) return;
    if ((st == pos) && (en == pos)){
      seg[node].mn = val;
      seg[node].id = pos;
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

SegTree st(maxn);

void solve(){
    int n, m; cin >> n >> m;
    rep(i, 1, n){
        ll a; cin >> a;
        if (i <= m) st.update(i, a);
        else st.update(i, -a);
    }

    // 1 1 2 3 5

    ll tot = 0;
    int ans = 0;

    // rep(i, 1, n) cout << st.query(i, i).mn << " ";
    // cout << "\n";

    per(i, m, 2){
        tot += st.query(i, i).mn;
        // cout << tot << "\n";
        if (tot <= 0) continue;
        while (tot > 0){
            Node curr = st.query(i, m);
            ll change = curr.mn;
            int ind = curr.id;
            // cout << i << " " << change << " " << ind << "\n";
            st.update(ind, -change);
            tot -= 2 * change;
            ans++;
            // break;
        }
    }

    tot = 0;
    rep(i, m+1, n){
        tot += st.query(i, i).mn;
        // cout << tot << "\n";
        if (tot <= 0) continue;
        while (tot > 0){
            Node curr = st.query(m+1, i);
            ll change = curr.mn;
            int ind = curr.id;
            // cout << i << " " << change << " " << ind << "\n";
            st.update(ind, -change);
            tot -= 2 * change;
            ans++;
            // break;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        // cout << "Case " << T << ":\n";
        solve();
    }
}
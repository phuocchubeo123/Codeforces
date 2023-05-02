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

struct SegTree{
  int sz;
  vi seg;
  
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
      seg[node] = val;
      return;
    }
    int mid = (st + en) / 2;
    update(2*node, st, mid, pos, val);
    update(2*node+1, mid+1, en, pos, val);
    seg[node] = seg[2*node] + seg[2*node+1];
  }

  int query(int l, int r){
    return query(1, 1, sz, l, r);
  }

  int query(int node, int st, int en, int l, int r){
    if ((st > r) || (en < l)) return 0;
    if ((l <= st) && (en <= r)) return seg[node];
    int mid = (st + en) / 2;
    int q1 = query(2*node, st, mid, l, r);
    int q2 = query(2*node+1, mid+1, en, l, r);
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

void solve(){
    int n; cin >> n;
    vi a(n+1), b(n+1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    int m; cin >> m;
    vi x(m+1);
    rep(i, 1, m) cin >> x[i];
    // sort(x.begin()+1, x.end());
    // reverse(x.begin()+1, x.end());
    map<int, int> cnt;
    rep(i, 1, m) cnt[x[i]]++;
    
    rep(i, 1, n) if (a[i] < b[i]){ cout << "NO\n"; return;}

    map<int, vi> st;
    set<int> nums;
    rep(i, 1, n){ st[b[i]].push_back(i); nums.insert(b[i]);}
    vi c(n);
    rep(i, 1, n) c[i-1] = b[i];
    sort(c.begin(), c.end());
    auto it = unique(c.begin(), c.end());
    c.resize(distance(c.begin(), it));
    reverse(c.begin(), c.end());

    SegTree segt(n);
    rep(i, 1, n) segt.update(i, 0);

    for (int x: c){
        // cout << x << ":\n";
        // rep(i, 1, n) cout << segt.query(i, i) << " ";
        // cout << "\n";
        int need;
        vi need_change;
        for (int i: st[x]) if (b[i] != a[i]) need_change.push_back(i);
        if (need_change.size() > 1){
            need = 1;
            forn(i, need_change.size() - 1){
                if (segt.query(need_change[i], need_change[i+1]) > 0) need++;
            }
        }
        else if (need_change.size() == 1) need = 1;
        else need = 0;
        if (need > cnt[x]){ cout << "NO\n"; return;}
        for (int i: st[x]) segt.update(i, 1);
    }

    cout << "YES\n";
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
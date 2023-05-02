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
    int pos;
    Node(int a, int ps){mn = a; pos = ps;}
    Node(){mn = INF;}
};

Node operator+(const Node& left, const Node& right){
    Node res;
    if (left.mn < right.mn){res.mn = left.mn; res.pos = left.pos;}
    else if (left.mn == right.mn){res.mn = left.mn; res.pos = min(left.pos, right.pos);}
    else {res.mn = right.mn; res.pos = right.pos;}
    return res;
}

struct SegTree{
  int sz;
  vector<Node> seg;
  
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
        seg[node].mn = val;
        seg[node].pos = pos;
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
    if ((st >= l) && (en <= r)) return seg[node];
    int mid = (st + en) / 2;
    Node q1 = query(2*node, st, mid, l, r);
    Node q2 = query(2*node+1, mid+1, en, l, r);
    return (q1+q2);
  }
};

void solve(){
    string s;
    cin >> s;
    vi x;
    forn(i, s.size()) x.push_back(s[i] - '0');
    int k; cin >> k;    
    int n = x.size();

    SegTree st(n);
    for (int i = 0; i < n; i++){
        st.update(i+1, x[i]);
    }

    vi cnt(10);
    int pt, pt2 = k;
    vi ans;
    forn(i, pt2+1) cnt[x[i]]++;
    forn(i, 10) if (cnt[i] > 0 && i != 0){
        ans.push_back(i);
        forn(j, n){
            if (x[j] == i){
                cnt[x[j]]--;
                pt = j+1;
                break;
            }
            cnt[x[j]]--;
            k--;
        }
        break;
    }
    while (k > 0){
        Node next_choice = st.query(pt+1, pt+k+1);
        ans.push_back(next_choice.mn);
        k -= (next_choice.pos - pt - 1);
        pt = next_choice.pos;

        if (pt == n) break;
    }

    for (int i = pt; i < n; i++) ans.push_back(x[i]);

    while (k > 0){
        ans.pop_back();
        k--;
    }

    for (auto x: ans) cout << x;
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    cin >> c;
    while(c--){
        solve();
    }
}
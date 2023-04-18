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
};


void solve(){
    int n, q;
    cin >> n >> q;

    vector<queue<int>> noti(n+1);
    int s = 0, curr = 0, read = 0;
    vi queries;
    queries.push_back(0);
    
    rep(t, 1, q){
        int type, x;
        cin >> type >> x;
        if (type == 1){
            s += 1;
            noti[x].push(t);
            queries.push_back(x);
        }

        if (type == 2){
            queries.push_back(0);
            while (!noti[x].empty()){
                int t1 = noti[x].front();
                noti[x].pop();
                queries[t1] = -1;
                s -= 1;
            }
        }

        if (type == 3){
            queries.push_back(0);
            while (read < x){
                curr++;
                int x1 = queries[curr];
                if (x1 == 0) continue;
                read++;
                if (x1 == -1) continue;
                noti[x1].pop();
                s--;
                queries[curr] = 0;
            }
        }

        cout << s << "\n";       
    }
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
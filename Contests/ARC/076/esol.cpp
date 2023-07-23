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

int r, c;

struct pt{
    int x;
    int y;
    int id;
    int loc;

    pt(){}

    void restruct(){
        if (y == 0){
            loc = x;
            return;
        }
        if (x == r){
            loc = r + y;
            return;
        }
        if (y == c){
            loc = r + c + (r-x);
            return;
        }
        if (x == 0){
            loc = r + c + r + (c-y);
            return;
        }
    }
};

istream& operator>>(istream& in, pt& p){
    in >> p.x;
    in >> p.y;
    return in;
}

bool filter(pt p){
    return (p.x == 0) | (p.y == 0) | (p.x == r) | (p.y == c);
}

void solve(){
    int n; cin >> r >> c >> n;
    vector<pt> ps;
    forn(i, n){
        int x, y, u, v;
        pt p, q;
        cin >> p >> q;
        p.id = i; q.id = i;
        ps.push_back(p);
        ps.push_back(q);
    }

    vector<pt> qs;
    vi c(n, 0);
    for (pt p: ps){
        if (filter(p)){
            c[p.id]++;
        }
    }

    for (pt p: ps){
        if (c[p.id] == 2){
            p.restruct();
            qs.push_back(p);
        }
    }

    sort(all(qs), [](pt u, pt v){
        return u.loc < v.loc;
    });

    if (qs.empty()){
        cout << "YES\n";
        return;
    }

    stack<pt> st;
    st.push(qs[0]);

    vi cnt(n, 0);

    // for (pt p: qs){
    //     cout << p.x << " " << p.y << " " << p.loc << "\n";
    // }

    rep(i, 1, qs.size() - 1){
        pt p = qs[i];
        // cout << p.x << " " << p.y << "\n";
        cout.flush();
        cnt[p.id]++;
        if (cnt[p.id] == 2){
            if (st.top().id != p.id){
                cout << "NO\n";
                return;
            }
            st.pop();
        }
        else{
            st.push(p);
        }
    }

    cout << "YES\n";
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
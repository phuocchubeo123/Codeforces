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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

void solve(){
    // a / k and b / k
    // we need to check if a / k > b / k
    int n; cin >> n;
    vi a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    vector<pii> prs;
    forn(i, n) if (a[i] > b[i]) prs.push_back({b[i] - 1, a[i] - 1});
    sort(all(prs));

    vector<pii> st;
    for (pii p: prs){
        if (st.empty()){ st.push_back(p); continue;}
        pii q = st.back();
        if (q.second > p.second) continue;
        st.push_back(p);
    }

    vi x, y;
    for (pii p: st){ x.push_back(p.first); y.push_back(p.second);}

    if (x.empty()){
        cout << n << "\n";
        rep(i, 1, n) cout << i << " ";
        cout << "\n";
        return;
    }

    vi lbx(n + 1, 1e6), lby(n+1, 1e6);
    per(i, x.size() - 1, 0){
        lbx[x[i]] = i;
        lby[y[i]] = i;
    }
    per(i, n-1, 0){
        if (lbx[i] == 1e6) lbx[i] = lbx[i+1];
        if (lby[i] == 1e6) lby[i] = lby[i+1];
    }

    vi ans;
    rep(k, 1, n){
        bool flag = true;
        for (int q = k; q <= n; q += k){
            if (lbx[q] != lby[q]) flag = false;
        }
        if (flag) ans.push_back(k);
    }
    cout << ans.size() << "\n";
    for (int k: ans) cout << k << " ";
    cout << "\n";
}

using namespace std::chrono;

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
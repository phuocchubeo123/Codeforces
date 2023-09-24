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

void solve(){
    // cout << "new c\n";
    ll n, m, p; cin >> n >> m >> p;
    vector<ll> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<ll> x;
    for (int i = 0; i < p; i++){
        ll a, b;
        cin >> a >> b;
        ll y = (b - s[a-1] + m) % m;
        if (y == 0) x.push_back(y);
        else x.push_back(m - y);
    }

    sort(x.begin(), x.end());
    vector<ll> cnt;
    vector<ll> v;
    int pt = 0;
    cnt.push_back(1ll);
    v.push_back(x[0]);
    for (int i = 1; i < p; i++){
        if (x[i] == x[i-1]){
            cnt[pt]++;
        }
        else{
            cnt.push_back(1);
            v.push_back(x[i]);
            pt++;
        }
    }

    int sz = cnt.size();

    if (v[0] > 0){
        for (int i = 1; i < sz; i++) v[i] -= v[0];    
    }
    v[0] = 0;
    
    ll tot = 0;
    for (int i = 0; i < sz; i++){
        tot += cnt[i] * v[i];
    }

    ll tot2 = 0;
    for (int i = 0; i < sz; i++){
        tot2 += cnt[i];
    }

    // cout << tot2 << "\n";

    ll ans = tot;

    for (int i = 1; i < sz; i++){
        tot -= tot2 * (v[i] - v[i-1]);
        tot += m * cnt[i-1];
        // cout << tot << " ";
        ans = min(ans, tot);
    }
    // cout << "\n";

    cout << ans << "\n";
}

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
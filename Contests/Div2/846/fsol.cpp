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

const int maxn = 3e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

void solve(){
    int n; cin >> n;
    vi a(n); forn(i, n) cin >> a[i];
    sort(all(a));
    // cout << "a:\n";
    // for (int x: a) cout << x << " ";
    // cout << "\n\n";
    vector<ll> cnt(maxn, 0), num(maxn, 0);
    ll ans = 0;
    forn(i, n){
        vi p;
        // extract prime divs
        int b = a[i];
        for (int x = 2; x * x <= b; x++){
            if (b % x == 0) p.push_back(x);
            while (b % x == 0) b /= x;
        }
        if (b > 1) p.push_back(b);

        // 
        int sz = p.size();
        ll sum_id = 0, bad = 0;
        for (int mask = 0; mask < (1 << sz); mask++){
            int unit = 0, x = 1;
            for (int bit = 0; bit < sz; bit++) if ((mask >> bit) & 1){ x *= p[bit]; unit++;}
            if (unit & 1){ sum_id += cnt[x]; bad += num[x];}
            else{ sum_id -= cnt[x]; bad -= num[x];}
        }
        sum_id += cnt[1]; bad += num[1];
        // cout << "sum id: " << sum_id << " " << bad << "\n";
        ans += 1ll * i * (i-1) / 2 - (i - 1) * bad + sum_id;
        // cout << "ans: " << ans << "\n";

        // update cnt and num
        for (int mask = 0; mask < (1 << sz); mask++){
            int unit = 0, x = 1;
            for (int bit = 0; bit < sz; bit++) if ((mask >> bit) & 1){ x *= p[bit]; unit++;}
            cnt[x] += i; num[x]++;
        }

        // cout << "cnt: ";
        // for (int x = 1; x <= a[n-1]; x++) cout << num[x] << " ";
        // cout << "\n";
    }

    cout << ans << "\n";
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
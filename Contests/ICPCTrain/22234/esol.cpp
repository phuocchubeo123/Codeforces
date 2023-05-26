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

const ll maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

ll a[maxn], b[maxn];

pair<ll, ll> sv(ll n){
    if (n == 0){
        return {0, 0};
    }
    ll lo = 1, hi = maxn;
    while (lo < hi){
        ll mi = (lo + hi + 1) / 2;
        if (mi * mi * mi > n){
            hi = mi-1;
        }
        else{
            lo = mi;
        }
    }

    // cout << n << " " << lo << "\n";

    if (lo == 1){
        return {n, n};
    }

    if (lo * lo * lo == n){
        return sv(n-1);
    }

    ll ans = a[lo-1];
    pair<ll, ll> ans2 = sv(n - lo * lo * lo);
    if (ans2.first + 1 >= ans){
        return {ans2.first + 1, ans2.second + lo * lo * lo};
    }
    else{
        return sv(lo * lo * lo - 1);
    }
}

void solve(){
    a[1] = 7; b[1] = 7;
    for (ll i = 2; i < maxn; i++){
        a[i] = a[i-1] - 1;
        for (ll x = 0; x < (i + 1) * (i + 1) * (i + 1); x += i * i * i){
            ll y = (i + 1) * (i + 1) * (i + 1) - x;
            if (y >= b[i-1]){
                a[i] += 1;
                b[i] = x + b[i-1];
            }
        }
    }

    // rep(i, 1, 10) cout << a[i] << " " << b[i] << "\n";

    ll n; cin >> n;
    pair<ll, ll> ans = sv(n);
    cout << ans.first << " " << ans.second << "\n";
    return;
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
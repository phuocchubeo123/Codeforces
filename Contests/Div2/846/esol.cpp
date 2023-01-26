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

pair<ll, ll> intersect(pair<ll, ll> x, pair<ll, ll> y){
    if (x.first > y.first) return intersect(y, x);
    if (x.second < y.first) return {0, 0};
    if (x.second > y.second) return y;
    return {y.first, x.second};
}

void solve(){
    ll l, r; cin >> l >> r;
    l--;
    vector<pair<ll, ll>> intervals;
    for (ll x = 1; x * x <= l; x++){
        if (r / x - l / x <= 1) intervals.push_back({x, x});
    }
    for (ll x = 1; x * x <= l; x++){
        pair<ll, ll> i1 = {l / (x + 1) + 1, l / x}, i2 = {r / (x + 1) + 1, r / x};
        pair<ll, ll> i3 = {l / (x + 1) + 1, l / x}, i4 = {r / (x + 2) + 1, r / (x + 1)};
        intervals.push_back(intersect(i1, i2));
        intervals.push_back(intersect(i3, i4));
    }

    intervals.push_back({0, 0});

    pair<ll, ll> i1 = {l + 1, r}, i2 = {r / 2 + 1, r};
    intervals.push_back(intersect(i1, i2));

    sort(all(intervals));
    // for (pii p: intervals) cout << p.first << " " << p.second << " & " << "\n";
    ll cur = 0;
    ll ans = 1;
    for (pair<ll, ll> p: intervals){
        if (p.second <= cur) continue;
        if (p.first <= cur){
            ans += p.second - cur;
            cur = p.second;
            continue;
        }
        ans += p.second - p.first + 1;
        cur = p.second;
    }
    cout << r + 1 - ans << "\n";
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
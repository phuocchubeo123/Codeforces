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

const int maxn = 5e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

vvi divisors(maxn);

void solve(){
    rep(i, 1, maxn){
        for (int j = 2 * i; j < maxn; j += i){
            divisors[j].push_back(i);   
        }
    }

    string s; cin >> s;
    int sz = s.size();
    char fir = s[0];
    bool rep_all = true;
    for (char c: s){
        if (c != fir) rep_all = false;
    }
    if (rep_all){
        cout << sz << "\n" << 1 << "\n";
        return;
    }

    vector<int> z = z_function(s);
    bool is_good = true;
    rep(i, 1, sz-1){
        if (z[i] == sz - i && sz % i == 0) is_good = false;
    }
    if (is_good){
        cout << 1 << "\n" << 1 << "\n";
        return;
    }

    vi good_pref(sz+1, 0);
    rep(i, 1, sz-1){
        is_good = true;
        for (int j: divisors[i]){
            if (z[j] >= i - j) is_good = false;
        }
        if (is_good) good_pref[i] = 1;
    }

    reverse(s.begin(), s.end());
    z = z_function(s);

    vi good_suf(sz+1, 0);
    rep(i, 1, sz-1){
        is_good = true;
        for (int j: divisors[i]){
            if (j == i) break;
            if (z[j] >= i - j) is_good = false;
        }
        if (is_good) good_suf[i] = 1;
    }

    good_suf[1] = 1;
    good_pref[1] = 1;

    cout << 2 << "\n";
    int ans = 0;
    rep(i, 1, sz){
        if (good_pref[i] == 1 && good_suf[sz-i] == 1) ans++;
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
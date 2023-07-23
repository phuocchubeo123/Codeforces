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
    int n; cin >> n;
    vector<ll> a(n);
    forn(i, n) cin >> a[i];
    sort(all(a)); reverse(all(a));

    vector<ll> b;
    ll curr = a[0];
    ll ans = 0;
    forn(i, n-1){
        b.push_back(curr);
        sort(all(b)); reverse(all(b));
        curr = a[i+1] + ans;

        ll last = b[i];
        ll steps = (last - curr) / (n+1);
        if (steps > 0){
            forn(j, i+1) b[j] -= (n-i) * steps;
            curr += steps * (i+1);
            ans += steps * (i+1);
        }

        // cout << steps << "\n";
        // for (int x: b) cout << x << " ";
        // cout << "\n";
        // cout << "\n";

        // continue;

        while (true){
            // cout.flush();
            bool flag = true;
            forn(j, i+1){
                if (b[j] > curr && b[j] >= n){
                    // cout << j << " false\n";
                    flag = false;
                    curr++;
                    b[j] -= (n+1);
                    ans++;
                    forn(k, i+1) b[k]++;
                }
            }
            // for (int x: b) cout << x << " ";
            // cout << "\n";
            // cout << "curr: " << curr << "\n";
            if (flag) break;
        }

        // cout << "ans: " << ans << "\n";
    }

    b.push_back(curr);
    sort(all(b)); reverse(all(b));
    // for (int x: b) cout << x << " ";
    // cout << "\n";

    ll steps = b[n-1] - n+1;
    if (steps > 0){
        ans += steps * n;
        forn(i, n) b[i] -= steps;
    }
    // for (int x: b) cout << x << " ";
    // cout << "\n";
    // return;
    while (true){
        // for (int x: b) cout << x << " ";
        // cout << "\n";
        // cout.flush();
        bool flag = true;
        forn(i, n){
            if (b[i] > n-1){
                flag = false;
                b[i] -= (n+1);
                ans++;
                forn(j, n) b[j]++;
            }
        }

        if (flag){
            cout << ans << "\n";
            return;
        }
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
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

int tcase = 0;
void solve(){
    int n; cin >> n;
    vector<pair<int, int>> tourist(n);
    forn(i, n){
        cin >> tourist[i].second >> tourist[i].first;
    }
    sort(all(tourist));
    reverse(all(tourist));

    // cout << n << "\n";
    // forn(i, n) cout << tourist[i].first << " " << tourist[i].second << "\n";
    // cout << "\n";

    int ans = 0;
    for (int i = 0; i < tourist.size(); i += 2){
        if (i + 1 < tourist.size()){
            int t1 = tourist[i].first, w1 = tourist[i].second;
            int t2 = tourist[i+1].first, w2 = tourist[i+1].second;
            if (w1 == 1 && w2 == 1){
                ans += t1 + 2;
                continue;
            }
            if (w1 == 1 && w2 == 2){
                ans += t1 + t2 + 1;
                continue;
            }
            if (w1 == 2){
                ans += 2 * t1 + 1;
                continue;
            }
        }

        else{
            int t = tourist[i].first, w = tourist[i].second;
            if (w == 1) ans += t + 2;
            else ans += 2 * t + 1;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    while(T--){
        tcase++;
        cout << "Case #" << tcase << ": ";
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
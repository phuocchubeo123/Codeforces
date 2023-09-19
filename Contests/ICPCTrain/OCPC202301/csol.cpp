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
    vector<ll> x(n), y(n);
    vector<int> l(n);
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        char c; cin >> c;
        l[i] = c - 'a';
    }


    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++){
        cnt[l[i]]++;
    }

    bool one_line = true;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            for (int k = j+1; k < n; k++){
                if ((x[j] - x[i]) * (y[k] - y[i]) == (x[k] - x[i]) * (y[j] - y[i])) continue;
                one_line = false;
            }
        }
    }

    if (one_line){
        for (int i = 0; i < 26; i++){
            if (cnt[i] >= 2){
                cout << 2 << "\n";
                return;
            }
        }
        cout << 1 << "\n";
        return;
    }

    for (int i = 0; i < 26; i++){
        if (cnt[i] >= 2){
            cout << "Infinity\n";
            return;
        }
    }

    cout << 1 << "\n";
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
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

double drt, pay, amt, depr;

void solve(){
    // cout << drt << " " << pay << " " << amt << "\n";
    vector<double> d(drt + 1, -1);
    forn(i, depr){
        int m; 
        cin >> m;
        cin >> d[m];
    }
    forn(i, drt + 1){
        if (d[i] == -1){
            d[i] = d[i-1];
        }
    }

    double loan = amt;
    amt += pay;
    double monthly = loan / drt;
    forn(i, drt + 1){
        amt *= (1 - d[i]);
        if (i > 0) loan -= monthly;
        // cout << "month: " << i << ": " << amt << " " << loan << "\n";
        if (loan < amt){ cout << i << ((i == 1) ? " month\n" : " months\n"); return;}
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    while (true){
        cin >> drt >> pay >> amt >> depr;
        if (drt < 0) break;
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
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

int N, B, H, W;
void solve(){
    vi p(H);
    vvi num(H, vi(W));
    forn(i, H){
        string s;
        getline(cin, s);
        // cout << s << "\n";
        stringstream tmp;
        tmp << s;
        tmp >> p[i];
        tmp.str("");
        tmp.clear();
        getline(cin, s);
        tmp << s;
        forn(j, W){
            tmp >> num[i][j];
        }
        tmp.str("");
        tmp.clear();
    }

    // forn(i, H) cout << p[i] << " ";
    // cout << "\n";
    // forn(i, H){
    //     forn(j, W) cout << num[i][j] << " ";
    //     cout << "\n";
    // }

    int pay = B + 5;
    forn(i, H){
        forn(j, W){
            if (num[i][j] >= N && p[i] * N <= B) pay = min(pay, p[i] * N);
        }
    }

    if (pay == B + 5) cout << "stay home\n";
    else cout << pay << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    while (true){
        string s;
        getline(cin, s);
        // cout << s << "\n";
        if (s == "") break;
        istringstream tmp(s);
        tmp >> N >> B >> H >> W;
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
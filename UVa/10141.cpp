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

int n, p;
void solve(){
    vector<string> name(p);
    vector<double> d(p);
    vector<double> r(p);
    forn(i, p){
        getline(cin, name[i]);
        cin >> d[i] >> r[i];
        cin.ignore();
        string s;
        forn(j, r[i]){
            getline(cin, s);
        }
    }

    bool flag = false;
    forn(i, p){
        if (r[i] == n){
            flag = true;
        }
    }

    if (flag){
        double mx = 2000000000;
        string ans;
        forn(i, p){
            if (r[i] == n && d[i] < mx){
                mx = min(mx, d[i]);
                ans = name[i];
            }
        }
        cout << ans << "\n";
        return;
    }

    double rm = 0;
    double curr_d = 2000000000;
    string ans;
    forn(i, p){
        if (r[i] / n > rm){
            rm = r[i] / n;
            curr_d = d[i];
            ans = name[i];
        }
        else if (r[i] / n == rm && d[i] < curr_d){
            curr_d = d[i];
            ans = name[i];
        }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    while (true){
        cin >> n >> p;
        cin.ignore();
        if (n == 0 && p == 0) break;
        if (T >= 2) cout << "\n";
        forn(i, n){
            string s;
            getline(cin, s);
        }
        cout << "RFP #" << T << "\n";
        solve();
        T++;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
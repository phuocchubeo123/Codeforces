#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
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
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m)), b(n, vi(m)), c(n, vi(m)), d(n, vi(m));
    forn(i, n){
        forn(j, m) cin >> a[i][j];
    }

    int l = 1, r = min(n, m);
    while (l < r){
        int mm = (l + r + 1) / 2;
        // cout << mm << "\n";
        forn(i, n) forn(j, m){
            if (a[i][j] >= mm) b[i][j] = 1;
            else b[i][j] = 0;
        }

        // forn(i, n){
        //     forn(j, m) cout << b[i][j] << " ";
        //     cout << "\n";
        // }

        forn(i, n){
            int tot = 0;
            forn(j, mm) tot += b[i][j];
            c[i][0] = tot;
            for (int j = 1; j + mm - 1 < m; j++){
                tot += b[i][j+mm-1] - b[i][j-1];
                c[i][j] = tot;
            }
        }

        // forn(i, n){
        //     forn(j, m) cout << c[i][j] << " ";
        //     cout << "\n";
        // }
        
        bool flag = false;
        forn(j, m){
            int tot = 0;
            forn(i, mm) tot += c[i][j];
            if (tot == mm * mm) flag = true;
            for (int i = 1; i + mm - 1 < n; i++){
                tot += c[i+mm-1][j] - c[i-1][j];
                if (tot == mm * mm){
                    // cout << j << " " << i << "\n";
                    flag = true;
                }
            }
        }

        // cout << flag << "\n";

        if (flag) l = mm;
        else r = mm - 1;
        // break;
    }

    cout << l << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}
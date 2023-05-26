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

vvi L(maxn, vi(LOG)), R(maxn, vi(LOG));

void solve(){
    int n; cin >> n;
    vector<ll> x(n);
    forn(i, n) cin >> x[i];

    ll l; cin >> l;
    int q; cin >> q;
    vi a(q), b(q);
    forn(i, q) cin >> a[i] >> b[i];

    vi u(n), v(n);

    int pt = 0;
    forn(i, n){
        while (pt < n && x[pt] - x[i] <= l){
            if (pt == n-1) break;
            if (x[pt+1] - x[i] <= l) pt++;
            else break;
        }
        u[i] = pt;
    }

    pt = n-1;
    per(i, n-1, 0){
        while (pt >= 0 && x[i] - x[pt] <= l){
            if (pt == 0) break;
            if (x[i] - x[pt-1] <= l) pt--;
            else break;
        }
        v[i] = pt;
    }


    forn(i, n){ L[i][0] = i; R[i][0] = i;}
    per(i, n-1, 0){ L[i][1] = v[i]; R[i][1] = u[i];}

    forn(i, n){
        rep(j, 2, LOG-1){
            L[i][j] = L[L[i][j-1]][j-1];
        }
    }

    per(i, n-1, 0){
        rep(j, 2, LOG-1){
            R[i][j] = R[R[i][j-1]][j-1];
        }
    }

    // forn(i, n){
    //     forn(j, LOG){
    //         cout << L[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n";

    // forn(i, n){
    //     forn(j, LOG){
    //         cout << R[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // return;

    forn(i, q){
        a[i]--; b[i]--;
        // cout << a[i] << " " << b[i] << "\n";
        if (a[i] < b[i]){
            int curr = a[i];
            int jmp = LOG-1;
            int tot = 0;
            while (true){
                // cout << "curr: " << curr << " " << jmp << " " << tot << "\n";
                if (R[curr][jmp] > b[i]){
                    jmp--;
                    if (jmp == 0){
                        if (curr == b[i]) cout << tot << "\n";
                        else cout << tot + 1 << "\n";
                        break;
                    } 
                    continue;
                }
                tot += (1 << (jmp - 1));
                curr = R[curr][jmp];
            }
        }

        else{
            int curr = a[i];
            int jmp = LOG-1;
            int tot = 0;
            while (true){
                // cout << "curr: " << curr << " " << jmp << " " << tot << "\n";
                if (L[curr][jmp] < b[i]){
                    jmp--;
                    if (jmp == 0){
                        if (curr == b[i]) cout << tot << "\n";
                        else cout << tot + 1 << "\n";
                        break;
                    } 
                    continue;
                }
                tot += (1 << (jmp - 1));
                curr = L[curr][jmp];
            }
        }

    }
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
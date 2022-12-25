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

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

ll h;
vi par_col(maxn), par_row(maxn);
vector<ll> change_col(maxn), change_row(maxn);

void find_par_col(int i){
    if (par_col[par_col[i]] == par_col[i]) return;
    find_par_col(par_col[i]);
    change_col[i] = (change_col[i] + change_col[par_col[i]]) % h; 
    par_col[i] = par_col[par_col[i]];
};

void find_par_row(int i){
    if (par_row[par_row[i]] == par_row[i]) return;
    find_par_row(par_row[i]);
    change_row[i] = (change_row[i] + change_row[par_row[i]]) % h;
    par_row[i] = par_row[par_row[i]];
};

void solve(){
    int n, m; cin >> n >> m;
    cin >> h;
    vector<vector<ll>> a(n, vector<ll>(m));
    forn(i, n){
        forn(j, m) cin >> a[i][j];
    }

    forn(i, n){ par_row[i] = i; change_row[i] = 0;}
    forn(j, m){ par_col[j] = j; change_col[j] = 0;}

    bool flag = false;
    forn(i, n) forn(j, m) if (a[i][j] != -1) flag = true;
    ll ans = 1;
    if (!flag){
        forn(i, n - 1) ans = (ans * h) % MOD;
        forn(j, m-1) ans = (ans * h) % MOD;
        ans = (ans * h) % MOD;
        cout << ans << "\n";
        return;
    }

    // forn(j, m) cout << par_col[j] << " ";
    // cout << "\n";

    forn(i, n){
        int pivot = -1;
        forn(j, m) if (a[i][j] != -1){ pivot = j; break;}
        if (pivot == -1) continue;
        find_par_col(pivot);

        forn(j, m) if (a[i][j] != -1){
            find_par_col(j);
            ll change = (a[i][pivot] - a[i][j] + change_col[pivot] + h) % h;
            if (par_col[j] == par_col[pivot]){
                if (change != change_col[j]){ cout << 0 << "\n"; return;}
            }
            else{
                change_col[par_col[j]] = (change - change_col[j] + h) % h;
                par_col[par_col[j]] = par_col[pivot];
                par_col[j] = par_col[pivot];
                change_col[j] = change;
            }
        }
        // forn(j, m) cout << par_col[j] << " ";
        // cout << "\n";
    }

    forn(j, m){
        int pivot = -1;
        forn(i, n) if (a[i][j] != -1){ pivot = i; break;}
        if (pivot == -1) continue;
        find_par_row(pivot);

        forn(i, n) if (a[i][j] != -1){
            find_par_row(i);
            ll change = (a[pivot][j] - a[i][j] + change_row[pivot] + h) % h;
            if (par_row[i] == par_row[pivot]){
                if (change != change_row[i]){ cout << 0 << "\n"; return;}
            }
            else{
                change_row[par_row[i]] = (change - change_row[i] + h) % h;
                par_row[par_row[i]] = par_row[pivot];
                par_row[i] = par_row[pivot];
                change_row[i] = change;
            }
        }
        // forn(j, m) cout << par_col[j] << " ";
        // cout << "\n";
    }
    // forn(j, m) cout << par_col[j] << " ";
    // cout << "\n";
    // forn(j, m) cout << change_col[j] << " ";
    // cout << "\n";

    // forn(j, n) cout << par_row[j] << " ";
    // cout << "\n";
    // forn(j, n) cout << change_row[j] << " ";
    // cout << "\n";

    int pow = 0;
    forn(i, n){
        // bool flag = false;
        // forn(j, m){
        //     if (a[i][j] != -1) flag = true;
        // }
        // if (!flag) pow += 1;
        if (par_row[i] == i) pow += 1;
    }

    forn(j, m){
        bool flag = false;
        forn(i, n){
            if (a[i][j] != -1) flag = true;
        }
        if (!flag) pow += 1;
    }

    // forn(i, n){
    //     if (par_row[i] == i){
    //         bool flag = false;
    //         forn(j, m){
    //             if (a[i][j] != -1) flag = true;
    //         }
    //         if (!flag) pow += 1;
    //     }
    // }

    pow -= 1;
    forn(i, pow) ans = (ans * h) % MOD;
    cout << ans << "\n";
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
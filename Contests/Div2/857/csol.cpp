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

mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count()); //willy108
vector<ll> hh;

void prehash(){
    forn(i, maxn) hh.push_back(rng() % (1ll << 60));
    sort(all(hh));
}

void solve(){
    // cout << hh[0] << hh[1] << "\n";
    int n, m; cin >> n >> m;
    cout << n * m << "\n";
    vector<vector<ll>> b(n, vector<ll>(m));

    ll cnt = rng() % maxn;
    forn(j, m){
        cnt++;
        cnt %= maxn;
        b[0][j] = hh[cnt];
    }

    forn(j, min(5, m)){
        cnt++;
        cnt %= maxn;
        b[1][j] = hh[cnt];
    }

    rep(j, 5, m-1){
        b[1][j] = b[0][j-5] ^ b[0][j-4] ^ b[0][j] ^ b[0][j-1] ^ b[1][j-5] ^ b[1][j-4] ^ b[1][j-1];
    }

    forn(j, min(5, m)){
        cnt++;
        cnt %= maxn;
        b[2][j] = hh[cnt];
    }

    rep(j, 5, m-1){
        b[2][j] = b[1][j-5] ^ b[1][j-4] ^ b[1][j] ^ b[1][j-1] ^ b[2][j-5] ^ b[2][j-4] ^ b[2][j-1];
    }

    rep(i, 3, n-1){
        cnt++;
        cnt %= maxn;
        b[i][0] = hh[cnt];
        rep(j, 1, m-1){
            if (j + 2 < m){
                b[i][j] = b[i-1][j] ^ b[i-1][j-1] ^ b[i][j-1] ^ b[i-2][j+1] ^ b[i-2][j+2] ^ b[i-3][j+1] ^ b[i-3][j+2];
            }
            else{
                if (j - 3 >= 0){
                    b[i][j] = b[i-1][j] ^ b[i-1][j-1] ^ b[i][j-1] ^ b[i-2][j-2] ^ b[i-2][j-3] ^ b[i-3][j-2] ^ b[i-3][j-3];
                }
                else{
                    cnt++; 
                    cnt %= maxn;
                    b[i][j] = hh[cnt];
                }
            }
        }
    }

    forn(i, n){
        forn(j, m) cout << b[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    prehash();
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
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

ll dp[305][305];
int dp2[305][305][3];
ll dp0[305][305];

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> qr(305);
    forn(i, m){
        int l, r, x;
        cin >> l >> r >> x;
        qr[r].push_back({r-l+1, x});
    }

    forn(j, 305){
        forn(k, 305){
            dp[j][k] = 0;
        }
    }

    dp[0][0] = 1;

    rep(i, 1, n){
        forn(j, 305){
            forn(k, 305){
                dp2[j][k][0] = 0;
                dp2[j][k][1] = 0;
                dp2[j][k][2] = 0;
            }
        }
        forn(j, 304){
            forn(k, 304){
                for (pii p: qr[i]){
                    int range = p.first, x = p.second;
                    if (x == 1){
                        if (range == 1){
                            dp2[j][k][0]++;
                            dp2[j][k][1]++;
                            dp2[j][k][2]++;
                        }
                        else if (j >= range - 1){
                            dp2[j][k][0]++;
                        }
                        else{
                            continue;
                        }
                    }

                    else if (x == 2){
                        if (range < 2) continue;
                        if (j >= range - 1){
                            dp2[j][k][1]++;
                            dp2[j][k][2]++;
                        }
                        else{
                            if (k >= range - 1){
                                dp2[j][k][0]++;
                                dp2[j][k][1]++;
                            }
                            else{
                                continue;
                            }
                        }
                    }

                    else{
                        if (range < 3) continue;
                        if (j >= range - 1) continue;
                        if (k >= range - 1){
                            dp2[j][k][2]++;
                        }
                        else{
                            dp2[j][k][0]++;
                            dp2[j][k][1]++;
                            dp2[j][k][2]++;
                        }
                    }
                }
            }
        }

        int amt = qr[i].size();
        forn(j, 304){
            forn(k, 304) dp0[j][k] = 0;
        }
        forn(j, 304){
            forn(k, 304){
                if (dp2[j][k][0] == amt) (dp0[j+1][k+1] += dp[j][k]) %= MOD;
                if (dp2[j][k][1] == amt) (dp0[1][k+1] += dp[j][k]) %= MOD;
                if (dp2[j][k][2] == amt) (dp0[1][j+1] += dp[j][k]) %= MOD;
            }
        }
        forn(j, 304){
            forn(k, 304){
                dp[j][k] = dp0[j][k];
            }
        }
    }

    ll ans = 0;
    forn(j, 304){
        forn(k, 304){
            (ans += dp[j][k]) %= MOD;
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
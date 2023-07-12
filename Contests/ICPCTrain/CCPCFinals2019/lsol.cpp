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
    int n, m; cin >> n >> m;
    int ans = 0;
    forn(i, n){
        forn(j, m){
            if (i == 0){
                if (j == 0 || j == m - 1) ans++;
                continue;
            }
            if (i == n-1){
                if (j == 0 || j == m-1) ans++;
                continue;
            }
            if (j == 0 || j == m-1){
                continue;
            }

            forn(k, n){
                if (k == i) continue;
                if (k > i){
                    int l = j, r = j, u = i, d = k;
                    bool flag = false;;
                    // left rec
                    for (int ad = m-1-r; ad <= m-1-r; ad++){
                        if (r + ad == m-1 && u - ad == 0 && d + ad == n-1){
                            cerr << "left\n";
                            flag = true;
                        }
                    }

                    // up rec
                    for (int ad = l; ad < l+1; ad++){
                        if (l - ad == 0 && r + ad - 1 == m-1 && d + ad - 1 == n-1){
                            cerr << "up\n";
                            flag = true;
                        }
                    }

                    // right rec
                    for (int ad = u; ad < u+1; ad++){
                        if (u - ad == 0 && l - ad == 0 && d + ad - 1 == n-1){
                            cerr << "right\n";
                            flag = true;
                        }
                    }

                    // down rec
                    for (int ad = u; ad < u+1; ad++){
                        if (r + ad == m-1 && u - ad == 0 && l - ad == 0){
                            cerr << "down\n";
                            flag = true;
                        }
                    }

                    if (flag){
                        cerr << "vertical: " << i << " " << j << " " << k << "\n";
                        ans++;
                    }
                }

                if (k < i){
                    int l = j, r = j, u = k, d = i;
                    bool flag = false;
                    // right rec
                    for (int ad = u; ad < u+1; ad++){
                        if (u - ad == 0 && l - ad == 0 && d + ad == n-1){
                            cerr << "right\n";
                            flag = true;
                        }
                    }

                    // down rec
                    for (int ad = n-1-r; ad < n-r; ad++){
                        if (r + ad == n-1 && u - ad + 1 == 0 && l - ad + 1 == 0){
                            cerr << "down\n";
                            flag = true;
                        }
                    }

                    // left rec
                    for (int ad = n-1-d; ad < n-d; ad++){
                        if (d + ad == n-1 && r + ad == m-1 && u - ad + 1 == 0){
                            cerr << "left\n";
                            flag = true;
                        }
                    }

                    // up rec
                    for (int ad = l; ad < l+1; ad++){
                        if (l - ad == 0 && r + ad == m-1 && d + ad == n-1){
                            cerr << "right\n";
                            flag = true;
                        }
                    }
                    if (flag){
                        cerr << "vertical: " << i << " " << j << " " << k << "\n";
                        ans++;
                    }
                }
            }

            forn(k, m){
                if (k == j) continue;
                if (k > j){
                    int l = j, r = k, u = i, d = i;
                    bool flag = false;
                    // down rec
                    for (int ad = m-1-r; ad < m-r; ad++){
                        if (r + ad == m-1 && u - ad == 0 && l - ad == 0){
                            cerr << "down\n";
                            flag = true;
                        }
                    }

                    // left rec
                    for (int ad = n-1-d; ad < n-d; ad++){
                        if (d + ad == n-1 && r - ad + 1 == m-1 && u - ad + 1 == 0){
                            cerr << "left!\n";
                            flag = true;
                        }
                    }

                    // up rec
                    for (int ad = l; ad < l+1; ad++){
                        if (l - ad == 0 && d + ad == m-1 && r + ad - 1 == n-1){
                            cerr << "up\n";
                            flag = true;
                        }
                    }

                    // right rec
                    for (int ad = u; ad < u+1; ad++){
                        if (u - ad == 0 && l - ad == 0 && d + ad == n-1){
                            cerr << "right\n";
                            flag = true;
                        }
                    }

                    if (flag){
                        cerr << "horizontal: " << i << " " << j << " " << k << "\n";
                        ans++;
                    }
                }

                if (k < j){
                    int l = k, r = j, u = i, d = i;
                    bool flag = false;
                    // up rec
                    for (int ad = l; ad < l+1; ad++){
                        if (l - ad == 0 && d + ad == n-1 && r + ad == m-1){
                            cerr << "up\n";
                            flag = true;
                        }
                    }

                    // right rec
                    for (int ad = u; ad < u+1; ad++){
                        if (u - ad == 0 && l - ad + 1 == 0 && d + ad - 1 == n-1){
                            cerr << "right\n";
                            flag = true;
                        }
                    }

                    // down rec
                    for (int ad = m-1-r; ad < m-r; ad++){
                        if (r + ad == m-1 && u - ad == 0 && l - ad + 1 == 0){
                            cerr << "down\n";
                            flag = true;
                        }
                    }

                    // left rec
                    for (int ad = n-1-d; ad < n-d; ad++){
                        if (d + ad == n-1 && r + ad == m-1 && u - ad + 1 == 0){
                            cerr << "left\n";
                            flag = true;
                        }
                    }

                    if (flag){
                        cerr << "horizontal: " << i << " " << j << " " << k << "\n";
                        ans++;
                    }
                }
            }
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
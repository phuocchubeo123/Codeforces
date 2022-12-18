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
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T a, T b){while(b){b^=a^=b^=a%=b;} return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vi> mx(n, vi(m)), mx2(n, vi(m));
    forn(i, n){
        forn(j, m){
            cin >> grid[i][j];
        }
    }

    forn(i, n){
        forn(j, m){
            for (int k = 0; k+j < m; k++){
                int cnt = 0;
                if (grid[i][j+k] == '#'){
                    mx[i][j] = k;
                    break;
                }
                if (grid[i][j+k] == 'm'){
                    cnt++;
                    if (cnt == 2){
                        mx[i][j] = k;
                        break;
                    }
                }
            }
        }
    }

    forn(j, m){
        forn(i, n){
            for (int k = 0; k + i < n; k++){
                int cnt = 0;
                if (grid[i][j+k] == '#'){
                    mx2[i][j] = k;
                    break;
                }
                if (grid[i][j+k] == 'm'){
                    cnt++;
                    if (cnt == 2){
                        mx2[i][j] = k;
                        break;
                    }
                }
            }
        }
    }

    vi can(m), latest(m);
    forn(l, n){
        for(int k = 0; k + l < n; k++){
            forn(j, m){
                can[j] = 0;
                latest[j] = -1;
            }
            forn(j, m){
                if (mx2[l][j] <= k){
                    continue;
                }
                can[j] = 1;
            }

            int lt = -1;
            forn(j, m){
                if (can[j] == 1) lt = j;
                latest[j] = lt;
            }

            forn(j, m){

            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
}
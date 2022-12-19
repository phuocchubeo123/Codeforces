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
    int n, m, k; cin >> n >> m >> k;
    
    vector<vector<vi>> tiles(k+2);
    vector<pair<int, int>> weights;
    rep(id, 1, k+1){
        vector<vi> a(n+1, vi(m+1));
        rep(i, 1, n){
            string s; cin >> s;
            rep(j, 1, m) a[i][j] = s[j-1] - '0';
        }
        tiles[id] = a;

        int w = 0;
        rep(i, 2, n-1){
            rep(j, 2, m-1){
                int curr = a[i][j];
                if (a[i][j] == a[i][j+1]) continue;
                if (a[i][j] == a[i][j-1]) continue;
                if (a[i][j] == a[i+1][j]) continue;
                if (a[i][j] == a[i-1][j]) continue;
                w--;
            }
        }
        weights.push_back({w, id});
    }

    sort(all(weights));

    vector<vi> ans;
    forn(l, k){
        vector<vi> curr = tiles[weights[l].second];
        vector<vi> next = tiles[weights[l+1].second];
        forn(_, 1000){
            bool flag = false;
            rep(i, 2, n-1){
                rep(j, 2, m-1){
                    if (curr[i][j] == next[i][j]) continue;
                    if (curr[i][j] == curr[i][j+1]) continue;
                    if (curr[i][j] == curr[i][j-1]) continue;
                    if (curr[i][j] == curr[i+1][j]) continue;
                    if (curr[i][j] == curr[i-1][j]) continue;
                    curr[i][j] = 1 - curr[i][j];
                    ans.push_back({1, i, j});
                    flag = true;
                }
            }
            if (!flag) break;
        }
        ans.push_back({2, weights[l+1].second});
    }

    cout << weights[0].second << "\n";
    cout << ans.size() << "\n";
    for (vi v: ans){
        for (int x: v) cout << x << " ";
        cout << "\n";
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
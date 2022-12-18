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
    vector<vi> a(n, vi(m));
    vi w(n);
    forn(i, n){
        forn(j, m){
            cin >> a[i][j];
            w[i] += a[i][j];
        }
    }

    int tot_w = 0;
    forn(i, n) tot_w += w[i];

    if (tot_w % n != 0){
        cout << -1 << "\n";
        return;
    }

    int tar = tot_w / n;
    vector<set<int>> can_swap(m);
    forn(i, n){
        if (w[i] > tar){
            forn(j, m){
                if (a[i][j] == 1){
                    can_swap[j].insert(i);
                }
            }
        }
    }

    // forn(i, m){
    //     for (int x: can_swap[i]) cout << x << " ";
    //     cout << "\n";
    // }
    // return;

    vi x, y, z;
    forn(i, n){
        forn(j, m){
            if (w[i] >= tar) break;
            if (a[i][j] == 1) continue;
            if (can_swap[j].empty()) continue;
            auto it = can_swap[j].begin();
            int i2 = *it;
            x.push_back(i+1); y.push_back(i2+1); z.push_back(j+1);
            w[i2]--;
            w[i]++;
            can_swap[j].erase(it);
            if (w[i2] == tar){
                forn(k, m) can_swap[k].erase(i2);
            }
        }
    }

    cout << x.size() << "\n";
    forn(i, x.size()){
        cout << x[i] << " " << y[i] << " " << z[i] << "\n";
    }
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
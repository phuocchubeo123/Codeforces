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
    vi c(n), x(m);
    forn(i, n){ cin >> c[i]; c[i]--;}
    forn(i, m){ cin >> x[i];}

    if (m == 1){ cout << x[0]; return;}

    int mid = m / 2;
    vector<int> adj1(m), adj2(m), adj12(m);
    forn(i, n-1){
        if (c[i] < mid && c[i+1] < mid){ adj1[c[i]] |= (1 << c[i+1]); adj1[c[i+1]] |= (1 << c[i]);}
        else if (c[i] < mid) adj12[c[i]] |= (1 << (c[i+1]-mid));
        else if (c[i+1] < mid) adj12[c[i+1]] |= (1 << (c[i]-mid));
        else { adj2[c[i]-mid] |= (1 << (c[i+1]-mid)); adj2[c[i+1]-mid] |= (1 << (c[i]-mid));}
    }

    // forn(i, mid){
    //     forn(j, m-mid){
    //         if ((adj12[i] >> j) & 1) cout << 1;
    //         else cout << 0;
    //     }
    //     cout << "\n";
    // }
    // return;

    auto cost = [&](int msk){
        ll cst = 0;
        forn(i, mid) if ((msk >> i) & 1) cst += x[i];
        return cst;
    };

    auto cost2 = [&](int msk){
        ll cst = 0;
        forn(i, m - mid) if ((msk >> i) & 1) cst += x[mid + i];
        return cst;
    };

    vector<ll> dp((1 << (m - mid)), 1e9);

    // forn(mask, (1 << mid)){
    //     forn(i, mid) cout << ((mask >> i) & 1);
    //     cout << "\n";
    //     cout << cost(mask) << "\n";
    // }

    // cout << c[0] << "\n";

    forn(mask, (1 << mid)){
        if (c[0] < mid && (((mask >> c[0]) & 1) == 0)) continue;
        if (c[n-1] < mid && (((mask >> c[n-1]) & 1) == 0)) continue;
        int need = 0, con = 0;
        forn(i, mid) if (((mask >> i) & 1) == 0){
            need |= adj1[i];
            con |= adj12[i];
        }
        // forn(i, mid) cout << ((mask >> i) & 1);
        // cout << " ";
        // forn(i, mid) cout << (((need | mask) >> i) & 1);
        // cout << "\n";
        // continue;
        if ((need | mask) > mask) continue;
        if (c[0] >= mid) con |= (1 << (c[0] - mid));
        if (c[n-1] >= mid) con |= (1 << (c[n-1]-mid));
        // forn(i, mid) cout << ((mask >> i) & 1);
        // cout << " ";
        // forn(i, m-mid) cout << ((con >> i) & 1);
        // cout << "\n";
        dp[con] = min(dp[con], cost(mask));
    }
    // cout << "\n";

    ll ans = 1e9;

    forn(mask, (1 << (m - mid))){
        forn(i, m - mid){
            if ((mask >> i) & 1) dp[mask] = min(dp[mask], dp[mask ^ (1 << i)]);
        }
        int need = 0;
        forn(i, m-mid) if (((mask >> i) & 1) == 0){
            need |= adj2[i];
        }
        // forn(i, mid) cout << ((mask >> i) & 1);
        // cout << " ";
        // forn(i, mid) cout << (((need | mask) >> i) & 1);
        // cout << "\n";
        // continue;
        if ((need | mask) > mask) continue;
        if (c[0] >= mid && ((mask >> (c[0]-mid)) & 1) == 0) continue;
        if (c[n-1] >= mid && ((mask >> (c[n-1]-mid)) & 1) == 0) continue;
        // forn(i, mid) cout << ((mask >> i) & 1);
        // cout << " ";
        // cout << cost2(mask) << " " << dp[mask] << "\n";
        ans = min(ans, cost2(mask) + dp[mask]);
    }

    cout << ans;
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
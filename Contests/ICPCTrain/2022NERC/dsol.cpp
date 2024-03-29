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
    int n; cin >> n;
    ll m; cin >> m;
    vector<ll> a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));

    int pt1 = 0, pt2 = n-1;
    ll ans = 0;
    while (true){
        int l = pt1, r = pt2;
        while (l < r){
            int mid = (l + r + 1) / 2;
            if (a[mid] + a[pt1] > m) r = mid - 1;
            else l = mid;
        }

        // cout << pt1 << " " << l << "\n";

        if (pt1 == l){
            ans++;
            break;
        }
        else if (pt1 + 1 == l){
            ans += 2;
            break;
        }
        else{
            ans += 2;
            pt1++;
            pt2 = l - 1;
        }
    }

    // cout << ans << "\n";
    ll tot = n - ans + 1;
    forn(i, n) tot += a[i];
    cout << tot;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}
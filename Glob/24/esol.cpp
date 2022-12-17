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

multiset<pair<ll, ll>> both;
multiset<ll> bs, as;

void solve(){
    int n; cin >> n;
    ll k; cin >> k;

    vector<ll> a(n), b(n);
    forn(i, n){
        cin >> a[i] >> b[i];
    }

    if (a[0] >= k){
        cout << "YES\n";
        return;
    }

    if (a[0] + b[0] < k){
        cout << "NO\n";
        return;
    }

    both.clear(); as.clear(); bs.clear();
    for (int i = 1; i < n; i++) both.insert({-a[i] - b[i], a[i]});
    for (int i = 1; i < n; i++) bs.insert(-a[i]-b[i]);
    for (int i = 1; i < n; i++) as.insert(-a[i]);
    
    int remain = n-1;
    if (remain == 0){
        cout << "NO\n";
        return;
    }

    ll target = k - b[0];
    while (remain > 0){
        // cout << "target: " << target << "\n";
        // for (int x: as) cout << x << " ";
        // cout << "\n";
        // for (int y: bs) cout << y << " ";
        // cout << "\n";
        ll x = *as.begin();
        if (-x >= target){
            cout << "YES\n";
            return;
        }

        pair<ll, ll> curr = *both.begin();
        ll u = curr.second, v = -curr.first;
        if (v < target){
            cout << "NO\n";
            return;
        }

        if (remain == 1){
            cout << "NO\n";
            return;
        }

        auto it = bs.begin();
        it++;
        if (-(*it) >= target){
            cout << "YES\n";
            return;
        }
        target = target - v + u;
        both.erase(both.begin());
        as.erase(as.find(-u));
        bs.erase(bs.find(-v));

        remain--;
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
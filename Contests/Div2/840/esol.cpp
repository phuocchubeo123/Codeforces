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
    ll p; cin >> p;

    vector<ll> first(p+1, 1e9);
    set<pair<ll, ll>> st;
    st.insert({0, 0});
    while (!st.empty()){
        // for (auto p: st) cout << p.first << ", " << p.second << "; ";
        // cout << "\n";
        auto it = st.begin();
        ll n = (*it).first, q = (*it).second;
        st.erase(it);
        if (q == p){
            cout << n << " " << (n * n - 2 * p - n) / 2;
            // ans[p]
            return;
        }

        if (n >= first[q]){
            continue;
        }

        st.erase({first[q], q});
        first[q] = n;
        ll m = n+1, r;
        for (ll i = 2; q + (i * i - i) / 2 <= p; i++){
            m++;
            r = q + (i * i - i) / 2;
            // if (r == p){
            //     cout << m << " " << (m * m - 2 * p - m) / 2;
            //     return;
            // }

            if (m >= first[r]) continue;
            st.erase({first[r], r});
            first[r] = m+1;
            st.insert({m, r});
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    clock_t t_start = clock();
    while(T--){
        solve();
    }
    clock_t t_end = clock();
    // cout << "\n";
    // cout << fixed << setprecision(10) << double(t_end - t_start) / double(CLOCKS_PER_SEC) << "\n";
}
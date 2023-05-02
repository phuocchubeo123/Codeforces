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
    string s; cin >> s;
    vector<ll> l(n+1), r(n+1);
    l[0] = 1; r[0] = 1;
    for (ll i = 1; i <= n; i++){
        ll nums = (1 << i);
        l[i] = nums; r[i] = 1;
        for (ll j = 1; j <= nums; j++){
            // win one team in the first round
            // rank from l[i-1] to r[i-1] in the second round
            ll lowest, highest;
            if (s[n-i] == '0'){
                if (j == nums) continue;
                lowest = (j+2)/2;
                ll a = j-1, b = nums-j-1;
                if (a <= b) highest = a+1;
                else highest = b + (a-b) / 2 + 1;
            }

            else{
                if (j == 1) continue;
                highest = j / 2;
                ll a = j-2, b = nums - j;
                if (a <= b) lowest = 1;
                else lowest = (a - b) / 2 + 1;
            }
            if (lowest <= r[i-1] && highest >= l[i-1]){
                l[i] = min(l[i], j);
                r[i] = max(r[i], j);
            }
            // cout << j << " " << lowest << " " << highest << "\n";
        }
        // cout << l[i] << " " << r[i] << "\n";
    }

    for (ll j = 1; j <= (1 << n); j++){
        if (l[n] <= j && r[n] >= j) cout << j << " ";
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
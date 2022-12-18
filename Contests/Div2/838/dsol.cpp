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

int query(int i, int j){
    cout << "? " << i << " " << j << "\n";
    cout.flush();
    int x; cin >> x;
    return x;
}

void ans(int i, int j){
    cout << "! " << i << " " << j << "\n";
    cout.flush();
    int x; cin >> x;
    return;
}

void solve(vi a, int sz){
    if (a.size() == 1){
        ans(1, a[0]);
        return;
    }

    if (a.size() == 2){
        ans(a[0], a[1]);
        return;
    }

    int x1 = query(a[sz-1], a[sz-3]), x2 = query(a[sz-1], a[sz-2]);
    if (x1 == x2){
        a.pop_back();
        solve(a, sz-1);
        return;
    }

    vi qrs;
    for (int i = 0; i < sz-3; i++){
        qrs.push_back(query(a[i], a[sz-1]));
    }
    qrs.push_back(x1); qrs.push_back(x2);

    int mx = 0;
    vi a_new;
    int sz_new = 0;
    for (int qr: qrs) mx = max(qr, mx);
    for (int i = 0; i < qrs.size(); i++){
        if (qrs[i] == mx){
            a_new.push_back(a[i]);
            sz_new++;
        }
    }

    if (a_new.size() == 1){
        a_new.push_back(a[sz-1]);
        solve(a_new, 2);
        return;
    }

    solve(a_new, sz_new);
}

void solve(){
    vi a; 
    int n; cin >> n;
    // cout << n << "\n";
    // cout.flush();
    for (int i = 1; i <= n; i++) a.push_back(i);
    solve(a, n);
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
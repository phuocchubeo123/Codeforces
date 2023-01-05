#include <bits/stdc++.h>
using namespace std;

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

void solve(){
    int n; cin >> n;
    // s_1 = s_3 = s_5, s_2 = s_4 
    // a b a b a
    // a+b+a = 0
    // b = -2, a = 1
    // 1 -2 1 -2 1
    // a b a b a b a
    // 3a+2b = 0
    // b = -3, a = 2
    // 2 -3 2 -3 2 -3 2
    if (n & 1){
        if (n == 3 || n == 1){ cout << "NO\n"; return;}
        cout << "YES\n";
        int a = -(n/2), b = -a-1;
        forn(i, n/2) cout << b << " " << a << " ";
        cout << b << "\n";
        return;
    }
    cout << "YES\n";
    forn(i, n/2) cout << -1 << " " << 1 << " ";
    cout << "\n";
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
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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

// n 2 3 ... 1
void solve(){
    int n, x; cin >> n >> x;
    if (n % x == 0){
        vi a(n+1);
        rep(i, 1, n) a[i] = i;

        if (x == n){
            a[1] = n; a[n] = 1;
            rep(i, 1, n) cout << a[i] << " ";
            cout << "\n";
            return;
        }
        a[1] = x;
        a[x] = n;
        a[n] = 1;
        int curr = x;
        rep(i, x+1, n){
            if (a[i] % curr == 0 && n % i == 0){
                a[curr] = a[i];
                a[i] = n;
                curr = i;
            }
        }
        rep(i, 1, n) cout << a[i] << " ";
        cout << "\n";
    }
    else cout << "-1\n";
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
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
    int m; cin >> m;
    vector<vi> gr(2, vi(m));
    forn(i, 2){
        string s; cin >> s;
        forn(j, m){
            if (s[j] == 'W') gr[i][j] = 0;
            else gr[i][j] = 1;
        }
    }

    int cnt = 0;
    int pos = 0;
    forn(i, m){
        if (gr[0][i] == 0 && gr[1][i] == 0){
            if (cnt == 0) continue;
            for (int j = i; j < m; j++){
                if (gr[0][j] == 1 && gr[1][j] == 1){
                    cout << "NO\n";
                    return;
                }
            }
            cout << "YES\n";
            return;
        }

        cnt++;
        if (gr[0][i] == 1 && gr[1][i] == 1){
            if (pos == 0) pos = 0;
            else if (pos == 1) pos = 2;
            else if (pos == 2) pos = 1;
            continue;
        }

        if (gr[0][i] == 1){
            if (pos == 0) pos = 1;
            else if (pos == 1) pos = 1;
            else{
                cout << "NO\n";
                return;
            }
            continue;
        }

        if (gr[1][i] == 1){
            if (pos == 0) pos = 2;
            else if (pos == 2) pos = 2;
            else{
                cout << "NO\n";
                return;
            }
            continue;
        }
    }

    cout << "YES\n";
    return;
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
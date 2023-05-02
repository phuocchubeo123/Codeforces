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

const int maxn = 2e3 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<vi> child(maxn);
vi p(maxn), q(maxn), r(maxn), vis(maxn);

void rerank(int i){
    if (vis[i]) return;

    vis[i] = 1;

    if (child[i].empty()) return;
    for (int j: child[i]){
        rerank(j);
        q[i] = min(q[i], q[j]);
    }
}

void solve(){
    int n, m; cin >> n >> m;
    forn(i, n){
        cin >> p[i];
    }

    forn(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        child[a].push_back(b);
    }

    vi cnt(n+1);
    forn(i, n){
        // cout << "Processing " << i << "\n";
        int le = 1, ri = p[i];
        while (le < ri){
            int mid = (le + ri) / 2;
            // cout << le << " " << ri << " " << mid << "\n";

            forn(j, n) q[j] = p[j];
            q[i] = mid;
            forn(j, n) vis[j] = 0;
            forn(j, n){
                rerank(j);
            }

            // forn(j, n) cout << q[j] << " ";
            // cout << "\n";

            for (int j = 1; j <= n; j++) cnt[j] = 0;
            forn(j, n) cnt[q[j]]++;

            // for (int j = 1; j <= n; j++) cout << cnt[j] << " ";
            // cout << "\n";
            int tot = 0;
            bool flag = true;
            for (int j = 1; j <= n; j++){
                tot += cnt[j];
                if (tot > j){
                    flag = false;
                    break;
                }
            }
            if (!flag) le = mid + 1;
            else ri = mid;
        }
        cout << le << " ";
    }
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
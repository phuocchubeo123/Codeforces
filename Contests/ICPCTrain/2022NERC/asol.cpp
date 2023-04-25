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

const int maxn = 505;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<vector<int>> chi(maxn);
vector<int> vis(maxn, 0), par(maxn), price(maxn), co(maxn), num(maxn), rk, mt(maxn, -1);
int color = 0, cost = 0;

void dfs(int i){
    if (vis[i]) return;
    vis[i] = 1;
    co[i] = color;
    if (chi[i].empty()){
        rk.push_back(i);
        return;
    }

    for (int j: chi[i]) dfs(j);
    rk.push_back(i);
}

bool try_kuhn(int u){
    // cout << u << " ";
    if (vis[u] == 1) return false;
    vis[u] = 1;

    for (int v: chi[u]){
        if (mt[v] == -1 || try_kuhn(mt[v])){
            mt[v] = u;
            return true;
        }
    }
    return false;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> assign(n, vector<int>(m, 0));
    forn(i, n){
        string s; cin >> s;
        forn(j, m){
            if (s[j] == '1') assign[i][j] = 1;
        }
    }

    // cout << m << "\n";
    forn(i, m) par[i] = i;
    forn(i, m){
        for (int j = i+1; j < m; j++){
            // cout << i << " " << j << "\n";
            int one_zero = 0, zero_one = 0;
            forn(k, n){
                if (assign[k][i] == assign[k][j]) continue;
                if (assign[k][i] == 1) one_zero++;
                else zero_one++;
            }

            if (one_zero > 0 && zero_one > 0) continue;
            if (one_zero > 0){
                chi[i].push_back(j);
                par[j] = i;
            }
            else{
                chi[j].push_back(i);
                par[i] = j;
            }
        }
    }

    forn(i, m){
        // cout << i << ":\n";
        vis.assign(m, 0);
        bool dummy = try_kuhn(i);
        // cout << "\n";
    }

    // forn(i, m) chi[i].clear();
    // forn(i, m){
    //     if (mt[i] != -1) chi[mt[i]].push_back(i);
    // }

    vi to(m, -1);
    forn(i, m) if (mt[i] != -1) to[mt[i]] = i;

    // forn(i, m) cout << to[i] << " ";
    // cout << "\n";

    vis.assign(m, 0);
    forn(i, m){
        if (vis[i] == 1) continue;
        color++;

        cost = 1000;
        int j = i;
        while (mt[j] != -1) j = mt[j];
        // cout << i << " " << j << "\n";
        while (to[j] != -1){
            vis[j] = 1;
            price[j] = cost;
            co[j] = color;
            cost += 2;
            j = to[j];
        }
        vis[j] = 1;
        price[j] = cost;
        co[j] = color;
    }

    vector<vector<int>> pay(n, vector<int> (color+1));

    forn(i, n){
        forn(j, m){
            if (assign[i][j] == 1) pay[i][co[j]] = price[j] + 1;
            else pay[i][co[j]] = price[j] - 1;
        }
    }

    forn(i, n){
        forn(j, m){
            if (assign[i][j] == 1) pay[i][co[j]] = max(pay[i][co[j]], price[j] + 1);
            else pay[i][co[j]] = min(pay[i][co[j]], price[j] - 1);
        }
    }

    cout << color << "\n";
    forn(j, m) cout << co[j] << " ";
    cout << "\n";

    forn(j, m) cout << price[j] << " ";
    cout << "\n";

    forn(i, n){
        for(int j = 1; j <= color; j++) cout << pay[i][j] << " ";
        cout << "\n";
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
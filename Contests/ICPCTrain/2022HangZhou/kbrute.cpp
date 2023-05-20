#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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

vi rk(26);

bool gt(string u, string v){
    forn(i, min(u.size(), v.size())){
        if (rk[u[i]-'a'] > rk[v[i]-'a']) return true; 
        if (rk[u[i]-'a'] < rk[v[i]-'a']) return false;  
    }
    if (u.size() > v.size()) return true;
    return false;
}

void solve(){
    int n; cin >> n;
    int q; cin >> q;

    vector<string> ss;
    forn(i, n){
        string s; 
        cin >> s;
        ss.push_back(s);
    }

    forn(i, q){
        string s; cin >> s;
        forn(i, 26) rk[s[i]-'a'] = i;
        ll ans = 0;
        forn(j, n){
            rep(k, j+1, n-1){
                if (gt(ss[j], ss[k])) ans++;
            }
        }
        cout << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
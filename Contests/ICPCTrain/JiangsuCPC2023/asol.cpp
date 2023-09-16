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

char nxt(char c){
    if (c == 'z') return 'a';
    return (c + 1);
}

void solve(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    int id = 0;
    while (s.size() < 3 * m){
        id++;
        string new_s;
        int l = s.size();
        forn(i, l/2){
            new_s.push_back(s[i]);
        }
        forn(i, l) new_s.push_back(s[i]);
        rep(i, l/2, l-1){
            new_s.push_back(nxt(s[i]));
        }

        s = new_s;
    }

    string t;
    rep(i, s.size() - m, s.size() - 1) t.push_back(s[i]);

    int a = 1; 
    forn(i, 100) a = (a * 10) % 26;
    a += 26;
    a -= (id % 26);
    a %= 26;
    
    forn(i, m) forn(j, a) t[i] = nxt(t[i]);

    cout << t << "\n";
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
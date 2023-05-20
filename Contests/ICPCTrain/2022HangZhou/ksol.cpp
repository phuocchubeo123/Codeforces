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

const int maxn = 1e6 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

/////////////////////////////////////////
// Start of implementation
const int K = 27; // alphabet size

int nxt[maxn][K];
ll alr[maxn][K];
ll aft[K][K];

// we store the trie as an array of vertices
struct Trie{
    int cnt;
    
    Trie(){ 
        cnt = 0;
        forn(i, maxn) forn(j, K){
            nxt[i][j] = -1;
            alr[i][j] = 0;
        }
        forn(i, K) forn(j, K) aft[i][j] = 0;
    }

    void add_string(string const& s){
        int v = 0;
        for (char ch: s){
            int c = ch - '`';
            if (nxt[v][c] == -1){
                cnt++;
                nxt[v][c] = cnt;
            }
            forn(i, K){
                aft[c][i] += alr[v][i];
            }

            alr[v][c]++;
            v = nxt[v][c];
        }
    }
};

void solve(){
    int n; cin >> n;
    int q; cin >> q;
    Trie tr;

    forn(i, n){
        string s; 
        cin >> s;
        s.push_back('`');
        tr.add_string(s);
    }

    forn(i, q){
        string s; cin >> s;
        reverse(all(s));
        s.push_back('`');
        reverse(all(s));
        // cout << s << "\n";
        ll ans = 0;
        forn(j, K){
            int x = s[j] - '`';
            rep(k, j+1, K-1){
                int y = s[k] - '`';
                ans += aft[x][y];
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
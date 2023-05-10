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

const int maxn = 1e5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

vector<int> z;
vi sz(maxn);
string cs;
vector<string> s(maxn);

bool typ1vstyp2 (int u, int v, int i){
    int ori = v - sz[i];
    int x = z[sz[i] + ori];
    if (x >= sz[i]){
        return true;
    }
    if (cs[ori+x] < s[i][x]){
        return true;
    }
    return false;
}

bool typ2vstyp1 (int u, int v, int i){
    int ori = u - sz[i];
    if (ori >= v) return true;
    int x = z[sz[i] + ori];
    if (x >= v - ori) return true;
    if (cs[ori+x] > s[i][x]) return true;
    return false;
}

bool typ2vstyp2 (int u, int v, int i){
    int ori1 = u - sz[i];
    int ori2 = v - sz[i];
    if (ori1 >= v) return typ1vstyp2(ori1, v, i);
    int x = z[ori2 + sz[i]];
    if (x >= ori1 - ori2){
        int y = z[ori1 - ori2];
        if (y >= v - ori1) return true;
        if (s[i][y] < s[i][ori1-ori2+y]) return true;
        return false;
    }
    if (cs[ori2+x] < s[i][x]) return true;
    return false;
}

bool typ1eqtyp2 (int u, int v, int i){
    int ori = v - sz[i];
    int x = z[sz[i] + ori];
    if (x >= sz[i]){
        return true;
    }
    return false;
}

bool typ2eqtyp1(int u, int v, int i){
    int ori = u - sz[i];
    // return true;
    if (ori >= v) return true;
    int x = z[sz[i] + ori];
    if (x >= v - ori) return true;
    return false;
}

bool typ2eqtyp2(int u, int v, int i){
    int ori1 = u - sz[i];
    int ori2 = v - sz[i];
    if (ori1 >= v) return typ1eqtyp2(ori1, v, i);
    int x = z[ori2 + sz[i]];
    if (x >= ori1 - ori2){
        int y = z[ori1 - ori2];
        if (y >= v - ori1) return true;
    }
    return false;
}

void solve(){
    int n, k; cin >> n >> k;
    rep(i, 1, n) cin >> s[i];
    rep(i, 1, n) sz[i] = s[i].size();

    vvi good(n+1, vi(k+1, 0));
    good[n][k] = 1;
    per(i, n-1, 0){
        per(j, k, 0){
            if (good[i+1][j] == 1) good[i][j] = 1;
            if (j + sz[i+1] > k) continue;
            if (good[i+1][j+sz[i+1]] == 1) good[i][j] = 1;
        }
    }

    vvi dp(n+1, vi(k+1, 0));
    dp[0][0] = 1;
    forn(i, k) cs.push_back('z');
    dp[n][k] = 0;

    rep(i, 1, n){
        if (sz[i] > k){
            forn(j, k+1){
                dp[i][j] = dp[i-1][j];
            }
            continue;
        }

        string ref_str;
        for (char c: s[i]) ref_str.push_back(c);
        for (char c: cs) ref_str.push_back(c);
        // cout << ref_str << "\n";

        z.clear();
        z = z_function(ref_str);
        z[0] = sz[i];

        vector<int> tp(k+1, 0);

        forn(j, k+1){
            if (good[i][j] == 0){
                tp[j] = 0; 
                continue;
            }
            // empty string
            if (j == 0){
                tp[j] = 1;
                continue;
            }
            // too small to fit s[i]
            if (j < sz[i]){
                tp[j] = dp[i-1][j];
                continue;
            }
            // cannot fit s[i]
            if (dp[i-1][j-sz[i]] == 0){
                tp[j] = dp[i-1][j];
                continue;
            }
            // does not have cs[:i]
            if (dp[i-1][j] == 0){
                tp[j] = 2;
                continue;
            }
            // both available
            if (typ1vstyp2(j, j, i)) tp[j] = 1;
            else tp[j] = 2;
        }

        // for (int x: tp) cout << x << " ";
        // cout << "\n";

        int curr = 0;
        int typ = 1;
        rep(j, 1, k){
            if (tp[j] == 0) continue;
            if (typ == 1){
                if (tp[j] == 1){ curr = j; typ = 1; continue;}
                // if tp[j] == 2
                if (typ2vstyp1(j, curr, i)){ curr = j; typ = 2;}
                continue;
            }
            // cout << j << " " << "done here\n";
            // cout.flush();

            // if typ == 2
            if (tp[j] == 1){
                if (typ1vstyp2(j, curr, i)){ curr = j; typ = 1;}
                continue;
            }
                
            // cout << j << " " << "done here\n";
            // cout.flush();
            // // if tp[j] == 2
            // cout << j << " " << "done here\n";
            // cout.flush(); 
            if (typ2vstyp2(j, curr, i)){ curr = j; typ = 2;}
                       
            continue;
        }

        // cout << "done here\n";
        // cout.flush();

        forn(j, k+1){
            if (j == curr){ dp[i][j] = 1; break;}
            if (tp[j] == 0) continue;
            if (tp[j] == 1){
                if (typ == 1){ dp[i][j] = 1; continue;}
                if (typ2eqtyp1(curr, j, i) && j <= k && j >= 0){dp[i][j] = 1;}
                continue;
            }
            if (typ == 1){
                if (typ1eqtyp2(curr, j, i) && j <= k && j >= 0){dp[i][j] = 1;}
                continue;
            }
            if (typ2eqtyp2(curr, j, i) && j <= k && j >= 0){ dp[i][j] = 1;}
            continue;
        }

        // cout << curr << " " << typ << "\n";
        // for (int x: dp[i]) cout << x << " ";
        // cout << "\n";

        string cs2;
        // cout << "typ: " << typ << "\n";
        // cout.flush();
        if (typ == 1){
            forn(_, curr){ cs2.push_back(cs[_]);}
            while (cs2.size() < k+1) cs2.push_back('z');
        }
        else{
            forn(_, curr-sz[i]) cs2.push_back(cs[_]);
            for (char c: s[i]) cs2.push_back(c);
            while (cs2.size() < k+1) cs2.push_back('z');
        }

        cs.clear();
        for (char c: cs2) cs.push_back(c);
    }
    forn(i, k) cout << cs[i] << "";
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
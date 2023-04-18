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

int encode(vvi grid){
    int tot = 0;
    forn(i, 3){
        forn(j, 3){
            tot += (1 << (3 * i + j)) * grid[i][j];
        }
    }
    return tot;
}

bool valid(int i, int j){
    return (i >= 0) && (i <= 2) && (j >= 0) && (j <= 2);
}

void transform(vvi &grid){
    vvi tmp = grid;
    forn(i, 3){
        forn(j, 3){
            int tot = 0;
            if (valid(i-1, j)) tot ^= grid[i-1][j];
            if (valid(i+1, j)) tot ^= grid[i+1][j];
            if (valid(i, j-1)) tot ^= grid[i][j-1];
            if (valid(i, j+1)) tot ^= grid[i][j+1];
            tmp[i][j] = tot;
        }
    }
    grid = tmp;
}

void solve(){
    vvi grid(3, vi(3));
    forn(i, 3){
        string s; cin >> s;
        forn(j, 3) grid[i][j] = s[j] - '0';
    }
    vi cnt(512, 0);
    vi seq;
    while (true){
        // forn(i, 3){
        //     forn(j, 3) cout << grid[i][j];
        //     cout << "\n";
        // }
        // cout << "\n";
        int x = encode(grid);
        cnt[x]++;
        if (cnt[x] > 1) break;
        else seq.push_back(x);
        transform(grid);
    }

    forn(i, seq.size()){
        if (cnt[seq[i]] > 1){
            if (i > 0) cout << i-1 << "\n";
            else cout << -1 << "\n";
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
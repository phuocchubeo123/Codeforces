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

const int maxn = (1 << 18);
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

/////////////////////////////////////////
// Start of implementation
const int K = 11; // alphabet size
int nxt[maxn][K];
ll ans[maxn];
ll ans2[maxn];

struct Vertex {
    bool leaf = false;
    int index = -1;

    Vertex() {
    }
};

// we store the trie as an array of vertices
struct Trie{
    vector<Vertex> trie;
    
    Trie(){ trie.emplace_back();}

    void add_string(vi s, int i){
        int v = 0; // current vertex
        for (int c: s){
            if (nxt[v][c] == -1){
                nxt[v][c] = trie.size();
                trie.emplace_back();
            }
            v = nxt[v][c];
        }
        trie[v].leaf = true;
        trie[v].index = i;
        // cout << trie[v].index << "\n";
        // for (int c: s) cout << c << " ";
        // cout << "\n";
    }

    int get(vi s){
        int v = 0;
        for (int c: s){
            if (nxt[v][c] == -1) return -1;
            v = nxt[v][c];
        }
        // cout << trie[v].index << " " << trie[v].leaf << "\n";
        if (trie[v].leaf == 1) return trie[v].index;
        return -1;
    }
};

vector<vector<int>> split(int n){
    vvi spl;
    forn(mask, (1 << (n-1))){
        int curr = 1;
        vi v;
        rep(bit, 1, n-1){
            if (((mask >> bit) & 1) == ((mask >> (bit-1)) & 1)){
                curr++;
            }
            else{
                v.push_back(curr);
                curr = 1;
            }
        }
        v.push_back(curr);
        spl.push_back(v);
    }
    return spl;
} 

void solve(){
    // I need to split 5, 7, 5
    // How to split 5

    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    forn(i, maxn){
        forn(j, K) nxt[i][j] = -1;
    }

    vvi spl5 = split(X);
    vvi spl7 = split(Y);
    vvi spl52 = split(Z);

    // return;

    vvi good;
    for (vi v: spl5){
        for (vi v1: spl7){
            for (vi v2: spl52){
                vi vv;
                for (int x: v) vv.push_back(x);
                for (int x: v1) vv.push_back(x);
                for (int x: v2) vv.push_back(x);
                good.push_back(vv);
            }
        }
    }

    sort(all(good));

    vvi summ;
    summ.push_back({});
    rep(i, 1, X+Y+Z){
        vvi sum1 = split(i);
        for (vi v: sum1){
            bool flag = true;
            for (int x: v) if (x > 10) flag = false;
            if (flag) summ.push_back(v);
        }
    }

    sort(all(summ));

    int pt = 0;
    vi can((1<<18), 0);
    forn(i, summ.size()){
        if (summ[i] == good[pt]){
            can[i] = 1;
            pt++;
        }
    }

    Trie tr;
    forn(i, summ.size()){
        tr.add_string(summ[i], i);
    }

    vvi adj(1<<18);
    int tot;
    forn(i, summ.size()){
        vi v = summ[i];
        rep(j, 1, 10){
            vi v2;
            v2.push_back(j);
            tot = j;
            for (int x: v){ v2.push_back(x); tot += x;}
            while (tot > X+Y+Z){ tot -= v2.back(); v2.pop_back();}
            int ind = tr.get(v2);
            adj[i].push_back(ind);
        }
    }

    // forn(i, 3){
    //     vi v = summ[i];
    //     cout << "index: " << tr.get(v) << "\n";
    //     for (int x: v) cout << x << " ";
    //     cout << "\n";
    //     cout << "adj: ";
    //     for (int j: adj[i]) cout << j << " ";
    //     cout << "\n";
    //     for (int j: adj[i]){
    //         vi u = summ[j];
    //         for (int x: u) cout << x << " ";
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }

    // forn(i, 3){
    //     vi v = summ[i];
    //     cout << "index: " << tr.get(v) << "\n";
    //     for (int x: v) cout << x << " ";
    //     cout << "\n";
    //     cout << "adj: ";
    //     int tot = 0;
    //     for (int x: v) tot += x;
    //     rep(j, 1, 9){
    //         vi v2;
    //         v2.push_back(j);
    //         for (int x: v) v2.push_back(x);
    //         if (tot + j > 17) v2.pop_back();
    //         int ind = tr.get(v2);
    //         adj[i].push_back(ind);
    //         for (int x: v2) cout << x << " ";
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }

    // return;

    ans[0] = 1;
    int sz = summ.size() + 1;

    // cout << sz << "\n";
    // return;
    forn(i, N){
        forn(j, sz) ans2[j] = 0;
        forn(j, sz-1){
            for (int k: adj[j]){
                if (can[k] == 1) (ans2[sz-1] += ans[j]) %= MOD;
                else{
                    (ans2[k] += ans[j]) %= MOD;
                }
            }
        }

        (ans2[sz-1] += 10 * ans[sz-1]) %= MOD;
        forn(j, sz) ans[j] = ans2[j];

        // forn(j, sz) if (ans[j] > 0 && can[j] == 1){
        //     cout << j << " " << ans[j] << " " << can[j] << "\n";
        //     if (j == sz-1){cout << "needed" << "\n"; continue;}
        //     for (int x: summ[j]) cout << x << " ";
        //     cout << "\n";
        // }
        // cout << "\n";
    }

    cout << ans2[sz-1] << "\n";
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
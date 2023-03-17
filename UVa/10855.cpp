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

const int K = 26; // alphabet size

struct Vertex {
    int next[K]; // store edges from the vertex
    bool leaf = false;
    int index = 0;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

struct Trie{
    vector<Vertex> trie;
    int curr;
    
    Trie(){ trie.emplace_back(); curr = 1;}

    void add_string(string const& s){
        int v = 0; // current vertex
        for (char ch: s){
            int c = ch - 'a';
            if (trie[v].next[c] == -1){
                trie[v].next[c] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[c];
        }
        trie[v].leaf = true;
        if (trie[v].index == 0) {trie[v].index = curr; curr++;}
    }

    int get(string const& s){
        int v = 0;
        for (char ch: s){
            int c = ch - 'A';
            if (trie[v].next[c] == -1) return 0;
            v = trie[v].next[c];
        }
        if (trie[v].leaf) return trie[v].index;
        return 0;
    }
};

int N, n;

void count_appear(vector<vector<char>> sq1, vector<vector<char>> sq2){
    // forn(i, n){
    //     forn(j, n) cout << sq2[i][j] << " ";
    //     cout << "\n";
    // }
    int cnt = 0;
    forn(i, N-n+1){
        forn(j, N-n+1){
            bool flag = true;
            forn(k, n){
                forn(l, n){
                    if (sq2[k][l] != sq1[i+k][j+l]){
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag) cnt++;
        }
    }
    cout << cnt;
    // cout << "\n";
}

void rotate90(vector<vector<char>> &sq){
    vector<vector<char>> tmp(n, vector<char>(n)); 
    forn(i, n){
        forn(j, n){
            tmp[j][n-i-1] = sq[i][j];
        }
    }
    sq = tmp;
}

void solve(){
    vector<vector<char>> sq1(N, vector<char>(N)), sq2(n, vector<char>(n));
    forn(i, N){
        string s; cin >> s;
        forn(j, N) sq1[i][j] = s[j];
    }   
    forn(i, n){
        string s; cin >> s;
        forn(j, n) sq2[i][j] = s[j];
    }
    forn(_, 4){
        if (_ > 0) cout << " ";
        count_appear(sq1, sq2);
        rotate90(sq2);
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    while (true){
        cin >> N >> n;
        if (N == 0 && n == 0) break;
        // if (T > 1) cout << "\n";
        solve();
        T++;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
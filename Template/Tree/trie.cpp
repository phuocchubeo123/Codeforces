<<<<<<< HEAD
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

/////////////////////////////////////////
// Start of implementation
const int K = 26; // alphabet size

struct Vertex {
    int next[K]; // store edges from the vertex
    bool leaf = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

// we store the trie as an array of vertices
struct Trie{
    vector<Vertex> trie;
    
    Trie(){ trie.emplace_back();}

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
    }

    bool get(string const& s){
        int v = 0;
        for (char ch: s){
            int c = ch - 'a';
            if (trie[v].next[c] == -1) return false;
            v = trie[v].next[c];
        }
        if (trie[v].leaf) return true;
        return false;
    }
};

// Persistent trie
struct PersistentTrie{
    vector<Vertex> trie;
    
    PersistentTrie(){ trie.emplace_back();}

    
};

void solve(){
    Trie tr;
    tr.add_string("ab");
    tr.add_string("acd");

    cout << tr.get("ab") << "\n";
    cout << tr.get("ac") << "\n";
    cout << tr.get("acd") << "\n";
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
=======
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

/////////////////////////////////////////
// Start of implementation
const int K = 26; // alphabet size

struct Vertex {
    int next[K]; // store edges from the vertex
    bool leaf = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

// we store the trie as an array of vertices
struct Trie{
    vector<Vertex> trie;
    
    Trie(){ trie.emplace_back();}

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
    }

    bool get(string const& s){
        int v = 0;
        for (char ch: s){
            int c = ch - 'a';
            if (trie[v].next[c] == -1) return false;
            v = trie[v].next[c];
        }
        if (trie[v].leaf) return true;
        return false;
    }
};

// Persistent trie
struct PersistentTrie{
    vector<Vertex> trie;
    
    PersistentTrie(){ trie.emplace_back();}

    
}

void solve(){
    Trie tr;
    tr.add_string("ab");
    tr.add_string("acd");

    cout << tr.get("ab") << "\n";
    cout << tr.get("ac") << "\n";
    cout << tr.get("acd") << "\n";
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
>>>>>>> 1ca1a06dcaa453346a9b1c53df3a2ce9541e2772
}
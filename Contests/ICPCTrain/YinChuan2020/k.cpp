#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>

const int maxn = 10000*5*50+5;
const int N = 10000*5+5;
vector<vector<int>> ur(N);
int curr;
int cnt = -1;

const int K = 28; // alphabet size

int nxt[maxn][K];

struct Trie{
    vector<int> trie;
    
    Trie(){ trie.push_back(-1);}

    void add_string(string const& s){
        int v = 0; // current vertex
        for (char ch: s){
            int c = ch - 'a';
            if (ch == '.') c = 26;
            if (ch == '/') c = 27;
            if (nxt[v][c] == -1){
                nxt[v][c] = trie.size();
                trie.push_back(-1);
            }
            v = nxt[v][c];
            if (trie[v] == -1){
                cnt++;
                trie[v] = cnt;
            }
            ur[curr].push_back(trie[v]);
        }
    }
};

void solve(){
    forn(i, maxn){
        forn(j, K) nxt[i][j] = -1;
    }

    int n; cin >> n;
    map<string, int> mp;
    vector<string> url(n);
    forn(i, n){
        cin >> url[i];
    }

    vector<vector<int>> after(maxn);
    Trie tr;

    int num;
    for (curr = 0; curr < n; curr++){
        tr.add_string(url[curr]);

        forn(j, ur[curr].size() - 1){
            after[ur[curr][j]].push_back(ur[curr][j+1]);
        }

        after[ur[curr].back()].push_back(maxn-1);
    }

    // forn(i, n){
    //     for (int x: ur[i]) cout << x << " ";
    //     cout << "\n";
    // }

    vi c(maxn, 0);
    forn(i, n){
        forn(j, ur[i].size()) c[ur[i][j]];
    }

    vector<vector<pair<int, int>>> upd(n);
    for (int i = n-1; i >= 0; i--){
        for (int j = ur[i].size() - 1; j >= 0; j--){
            if (c[ur[i][j]] == 0){
                for (int x: after[ur[i][j]]) upd[i].push_back({ur[i][j], x});
            }
            c[ur[i][j]]++;
        }
    }

    // forn(i, n){
    //     for (auto p: upd[i]) cout << p.first << "," << p.second << " ; ";
    //     cout << "\n";
    // }

    vi pre(maxn, 0);
    int ans = 0;
    forn(i, n){
        for (auto p: upd[i]){
            int x = p.first, y = p.second;
            pre[y]--;
            if (pre[y] == 0) ans--;
            if (pre[y] < 0) pre[y] = 0;
            pre[x]++;
            if (pre[x] == 1) ans++;
            if (pre[x] > 1) pre[x] = 1; 
        }
        cout << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--){
        solve();
    }
}
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

vector<vector<pair<int, int>>> adj(20);
vi wt(20);
vi dp(1 << 20, 0);

bool there(int mask, int bit){
    return ((mask >> bit) & 1);
}

void print_mask(int mask){
    rep(i, 1, 19) if ((mask >> i) & 1) cout << i << ", ";
}

void prepare(){
    adj[1] = {{4, 8}, {5, 10}, {2, 3}};
    adj[2] = {{5, 9}, {6, 11}};
    adj[3] = {{6, 10}, {7, 12}, {2, 1}};
    adj[4] = {{5, 6}, {9, 14}};
    adj[5] = {{9, 13}, {10, 15}, {6, 7}};
    adj[6] = {{10, 14}, {11, 16}, {5, 4}};
    adj[7] = {{6, 5}, {11, 15}};
    adj[8] = {{4, 1}, {9, 10}, {13, 17}};
    adj[9] = {{5, 2}, {14, 18}, {10, 11}};
    adj[10] = {{5, 1}, {6, 3}, {11, 12}, {9, 8}, {14, 17}, {15, 19}};
    adj[11] = {{6, 2}, {10, 9}, {15, 18}};
    adj[12] = {{7, 3}, {11, 10}, {16, 19}};
    adj[13] = {{9, 5}, {14, 15}};
    adj[14] = {{9, 4}, {10, 6}, {15, 16}};
    adj[15] = {{14, 13}, {10, 5}, {11, 7}};
    adj[16] = {{15, 14}, {11, 6}};
    adj[17] = {{13, 8}, {18, 19}, {14, 10}};
    adj[18] = {{14, 9}, {15, 11}};
    adj[19] = {{18, 17}, {15, 10}, {16, 12}};

    rep(i, 1, 19){
        cin >> wt[i];
    }

    dp[0] = 0;

    vvi wtt(20);
    forn(mask, (1 << 20)){
        if (mask % 2 == 1) continue;
        int w = 0;
        rep(bit, 1, 19) w += ((mask >> bit) & 1);
        wtt[w].push_back(mask);
    }

    forn(w, 20){
        for(int mask: wtt[w]){
            // if ((mask >> 0) && 1) continue;
            rep(curr, 1, 19){
                if (there(mask, curr)){
                    for (pii p: adj[curr]){
                        int nxt = p.second;
                        int point = p.first;
                        if (there(mask, point) && !there(mask, nxt)){
                            int next_mask = mask ^ (1 << point) ^ (1 << nxt) ^ (1 << curr);

                            // if (mask == 34304){
                            //     print_mask(next_mask);
                            //     cout << " " << dp[next_mask] << "\n";
                            // }
                            dp[mask] = max(dp[mask], dp[next_mask] + wt[point]);
                        }
                    }
                }
                int next_mask = mask ^ (1 << curr);
                dp[mask] = max(dp[mask], dp[next_mask]);
            }
        }
    }

    // forn(mask, (1 << 20)){
    //     // if (mask && 1) continue;
    //     int weigt = 0;
    //     rep(curr, 1, 19){
    //         weigt += ((mask >> curr) & 1);
    //     }
    //     if (weigt > 4) continue;
    //     if (weigt < 2) continue;
    //     rep(curr, 1, 19){
    //         cout << ((mask >> curr) & 1);
    //     }
    //     cout << " ";
    //     cout << dp[mask] << "\n";
    // }

    // cout << "dp: ";
    // cout << dp[(1 << 11) + (1 << 15)] << "\n";
    // cout << dp[(1 << 9) + (1 << 10) + (1 << 15)] << "\n";
}


void solve(){
    int bm = 0;
    rep(i, 1, 19){
        char c; cin >> c;
        if (c == '#'){
            bm |= (1 << i);
        }
    }
    // cout << "mask: ";
    // cout << bm << "\n";
    // rep(i, 1, 19){
    //     cout << ((bm>> i) & 1);
    // }
    // cout << "\n";
    cout << dp[bm] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    prepare();
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
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

const int maxn = 500;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 61;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

int g[500][500];

void build_2_power(int x, int y, int p, int c, int s){
    if (p == 0){
        if (c == 0){
            for (int i = x; i < maxn; i++){
                g[i][y] = c;
            }
            for (int i = y; i < maxn-1; i++){
                g[maxn-1][i] = c;
            }
        }

        else{
            for (int i = y; i < maxn; i++){
                g[x][i] = c;
            }

            for (int i = x; i < maxn-1; i++){
                g[i][maxn-1] = c;
            }
        }
        
        return;
    }
    g[x][y] = c;
    g[x+1][y] = c;
    g[x][y+1] = c;
    g[x+1][y+1] = c;

    if (s % 2 == 0){
        build_2_power(x+1, y+2, p-1, c, s+1);
    }
    else{
        build_2_power(x+2, y+1, p-1, c, s+1);
    }
}

void build_from_source(int x, int y, int c){
    if (c == 0){
        for (int i = 1; i <= x; i++) g[i][0] = c;
        for (int i = 0; i <= y; i++) g[x][i] = c;
    }
    else{
        for (int i = 1; i <= y; i++) g[0][i] = c;
        for (int i = 0; i <= x; i++) g[i][y] = c;
    }
}

void solve(){
    ll p, q; cin >> p >> q;

    if (p == 0 && q == 0){
        cout << 3 << " " << 3 << "\n";
        cout << "RBB\n";
        cout << "BBB\n";
        cout << "BBR\n";
        return;
    }

    for (int i = 0; i < maxn; i++){
        for (int j = 0; j < maxn; j++){
            g[i][j] = 2;
        }
    }

    vector<int> xr;
    xr.push_back(maxn - 5);
    for (int i = 1; i <= LOG; i++){
        xr.push_back(xr.back() - 3);
    }
    
    vector<int> yr;
    yr.push_back(5);
    for (int i = 1; i <= LOG; i++){
        yr.push_back(yr.back() + 2);
    }

    vector<int> xb;
    xb.push_back(5);
    for (int i = 1; i <= LOG; i++){
        xb.push_back(xb.back() + 3);
    }

    vector<int> yb;
    yb.push_back(maxn - 5);
    for (int i = 1; i <= LOG; i++){
        yb.push_back(yb.back() - 2);
    }

    // cout << yb.back() << "\n";

    if (p == 0){
        g[0][0] = 1;

        for (int bit = 0; bit <= LOG; bit++){
            if ((q >> bit) & 1){
                build_from_source(xb[bit], yb[bit], 1);
                build_2_power(xb[bit], yb[bit], bit, 1, 0);
            }
        }

        g[maxn-1][maxn-1] = 2;
        g[maxn-1][maxn-2] = 1;

        cout << 500 << " " << 500 << "\n";
        for (int i = 0; i < maxn; i++){
            for (int j = 0; j < maxn; j++){
                if (g[i][j] == 2) cout << 'R';
                else cout << 'B';
            }
            cout << "\n";
        }
        return;
    }

    if (q == 0){
        g[0][0] = 0;

        for (int bit = 0; bit <= LOG; bit++){
            if ((p >> bit) & 1){
                build_from_source(xr[bit], yr[bit], 0);
                build_2_power(xr[bit], yr[bit], bit, 0, 0);
            }
        }

        g[maxn-1][maxn-1] = 2;
        g[maxn-2][maxn-1] = 0;

        cout << 500 << " " << 500 << "\n";
        for (int i = 0; i < maxn; i++){
            for (int j = 0; j < maxn; j++){
                if (g[i][j] == 2) cout << 'B';
                else cout << 'R';
            }
            cout << "\n";
        }
        return;
    }

    
    // cout << g[maxn-1][maxn-1] << "\n";

    for (int j = 0; j < maxn-1; j++){
        g[j][j] = 0;
        g[j+1][j] = 0;
        for (int i = j+2; i < maxn; i++){
            g[i][j] = 1;
        }
    }

    for (int i = 0; i < maxn-1; i++){
        g[i][i+1] = 1;
        g[i][i+2] = 1;
        for (int j = i+3; j < maxn; j++){
            g[i][j] = 0;
        }
    }

    p--; q--;

    for (int bit = 0; bit <= LOG; bit++){
        if ((q >> bit) & 1){
        build_from_source(xb[bit], yb[bit], 1);
        build_2_power(xb[bit], yb[bit], bit, 1, 0);
        }
    }

    for (int bit = 0; bit <= LOG; bit++){
        if ((p >> bit) & 1){
            build_from_source(xr[bit], yr[bit], 0);
            build_2_power(xr[bit], yr[bit], bit, 0, 0);
        }
    }

    g[0][3] = 1;
    g[1][1] = 1;
    g[1][2] = 0;
    g[2][0] = 0;

    g[maxn-4][maxn-1] = 1;
    g[maxn-3][maxn-2] = 0;
    g[maxn-2][maxn-2] = 1;
    g[maxn-1][maxn-3] = 0;

    g[0][0] = 0;
    g[maxn-1][maxn-1] = 1;

    // for (int i = 480; i < 500; i++){
    //     for (int j = 480; j < 500; j++){
    //         if (g[i][j] == 0) cout << "R";
    //         else cout << "B";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    // for (int i = 460; i < 500; i++){
    //     for (int j = 0; j < 40; j++){
    //         if (g[i][j] == 0) cout << "R";
    //         else cout << "B";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    // for (int i = 0; i < 20; i++){
    //     for (int j = 470; j < 500; j++){
    //         if (g[i][j] == 0) cout << "R";
    //         else cout << "B";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    cout << 500 << " " << 500 << "\n";
    for (int i = 0; i < maxn; i++){
        for (int j = 0; j < maxn; j++){
            if (g[i][j] == 0) cout << "R";
            else cout << "B";
        }
        cout << "\n";
    }

    // cout << (1ll << 61) - 1 << "\n";
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
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

void solve(){
    int n, q; cin >> n >> q;
    int sq = sqrt(n);
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<int> ps(n+1);
    for (int i = 1; i <= n; i++) ps[p[i]] = i;
    vector<int> l(q), r(q);
    for (int i = 1; i < q; i++) cin >> l[i] >> r[i];

    int mn[n+1][sq+1];

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= sq; j++){
            mn[i][j] = n + 5;
        }
    }

    for (int i = 1; i <= n; i++){
        int cur = p[i];
        mn[i][1] = i;
        for (int j = 2; j <= sq; j++){
            int nxt = cur - 1;
            if (nxt == 0) break;
            if (ps[nxt] > ps[cur]) break;
            cur = nxt;
            mn[ps[cur]][j] = i;
        }
    }

    int mxi[sq+5][sq+1];

    for (int i = 1; i <= sq+4; i++){
        for (int j = 1; j <= sq; j++){
            mxi[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++){
        int cur_int = (i + sq - 1) / sq;
        for (int j = 1; j <= sq; j++){
            mxi[cur_int][j] = min(mxi[cur_int][j], mn[i][j]);
        }
    }

    int mxpi[sq+5][sq+5][sq+1];
    for (int i = 1; i <= sq+4; i++){
        for (int k = 1; k <= sq; k++){
            mxpi[i][i][k] = mxi[i][k];
            for (int j = i+1; j <= sq+4; j++){
                mxpi[i][j][k] = min(mxpi[i][j-1][k], mxi[j][k]);
            }
        }
    }

    int mxl[n+1][sq+1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= sq; j++){
            if (i % sq == 1) mxl[i][j] = mn[i][j];
            else mxl[i][j] = min(mxl[i-1][j], mn[i][j]);
        }
    }

    int mxr[n+1][sq+1];
    for (int i = n; i >= 1; i--){
        for (int j = 1; j <= sq; j++){
            if (i % sq == 0 || i == n) mxr[i][j] = mn[i][j];
            else mxr[i][j] = min(mxr[i][j+1], mn[i][j]);
        }
    }

    int mxpp[sq+5][sq+5][sq+1];
    for (int i = 1; i <= sq; i++){
        for (int j = sq * (i-1) + 1; j < sq * i; j++){
            mxpp[j % sq][j % sq][i] = mxi[j % sq][i];
            for (int k = j + 1; k < sq * i; k++){
                mxpp[j][k][i] = min(mxpp[j][k-1][i], mxi[k][i]);
            }
        }
    }

    vector<vector<int>> s;
    int pt = 0;
    for (int i = 1; i <= n; i++){
        s.push_back({i});
        while (true){
            if (i == n) break;
            if (ps[i+1] > ps[i]){
                i++;
                s[pt].push_back(i);
            }
            else{
                break;
            }
        }
        pt++;
    }

    vector<vector<int>> s2;
    for (auto ss: s) if (ss.size() > sq) s2.push_back(ss);
    
    int br[n+1][s2.size()];
    for (int i = 0; i < s2.size(); i++){
        vector<int> ss = s2[i];
        int pt = 0;
        for (int j = 1; j <= n; j++){
            bool flag = true;
            while (j > ps[ss[pt]]){
                if (pt == s2[i].size() - 1){
                    flag = false;
                    break;
                }
                else{
                    pt++;
                } 
            }
            if (flag) br[j][i] = ps[ss[pt]];
            else br[j][i] = n+1;
        }
    }

    int bl[n+1][s2.size()];
    for (int i = 0; i < s2.size(); i++){
        vector<int> ss = s2[i];
        int pt = ss.size() - 1;
        for (int j = n; j >= 1; j--){
            bool flag = true;
            while (j < ps[ss[pt]]){
                if (pt == 0){
                    flag = false;
                    break;
                }
                else{
                    pt--;
                } 
            }
            if (flag) bl[j][i] = ps[ss[pt]];
            else bl[j][i] = 0;
        }
    }

    vector<int> vis(n+1, 0);

    for (int i = 0; i < q; i++){
        int u = l[i], v = r[i];
        int ans = 0;
        for (int j = 0; j < s2.size(); j++){
            int u1 = br[u][j], v1 = bl[v][j];
            if (u1 <= v1) ans = max(ans, v1 - u1 + 1);
        }
        if (ans > 0){
            cout << ans << "\n";
            continue;
        }

        int u1 = (u + sq - 1) / sq;
        int v1 = (v + sq - 1) / sq;

        if (u1 == v1){
            for (int j = u; j <= v; j++){
                vis[p[j]] = 0;
            }
            for (int j = u; j <= v; j++){
                if (vis[p[j]] == 1) continue;
                int xx = 1;
                int cur = p[j];
                while (true){
                    if (cur == n){
                        break;
                    }
                    else{
                        if (ps[cur+1] > ps[cur]){
                            cur++;
                            xx++;
                        }
                        else{
                            break;
                        }
                    }
                }
                ans = max(ans, xx);
            }

            cout << ans << "\n";
            continue;
        }


        if (u1 + 1 == v1){
            for (int j = 1; j <= sq; j++){
                int x = min(mxr[u][j], mxl[v][j]);
                if (x <= v){
                    ans = j;
                    break;
                }
            }
            cout << ans << "\n";
            continue;
        }

        for (int j = 1; j <= sq; j++){
            int x = min(min(mxr[u][j], mxpi[u1+1][v1][j]), mxl[v][j]);
            if (x <= v){
                ans = j;
                break;
            }
        }
        cout << ans << "\n";
        continue;
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
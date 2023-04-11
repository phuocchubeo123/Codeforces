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

auto start = high_resolution_clock::now();
auto stop = high_resolution_clock::now();

class Solution {
public:
    Solution(){}

    int tilingRectangle(int n, int m) {
        int grid[13][13];
        for (int i = 0; i < 13; i++){
            for (int j = 0; j < 13; j++){
                grid[i][j] = 0;
            }
        }

        int sz = 1;
        stack<int> st, X, Y;
        st.push(1);
        int crow[13];
        int cnt = 0;
        for (int i = 0; i < n; i++) crow[i] = 0;
        int ans = 20;
        bool stop_flag = true;

        while (stop_flag){

            // cout << "\n";
            // for (int i = 0; i < 13; i++){
            //     for (int j = 0; j < 13; j++){
            //         std::cout << grid[i][j];
            //     }
            //     cout << "\n";
            // }

            int curr = st.top();
            int fill_x = -1, fill_y = -1;
            for (int i = 0; i < n; i++){
                if (crow[i] == m) continue;
                fill_x = i;
                for (int j = 0; j < m; j++){
                    if (grid[i][j] == 0){
                        fill_y = j;
                        break;
                    }
                }
                break;
            }
            // cout << fill_x << " " << fill_y << "\n";

            if (!fill_grid(grid, fill_x, fill_y, curr, n, m, cnt, crow)){
                // std::cout << "cannot fill\n";
                st.pop();
                sz--;
                // cout << "sz: " << sz << "\n";
                if (sz == 0) return ans;
                int last_x = X.top(); X.pop();
                int last_y = Y.top(); Y.pop();
                int last_curr = st.top(); st.pop();
                unfill_grid(grid, last_x, last_y, last_curr, n, m, cnt, crow);
                st.push(last_curr+1);
                continue;
            }

            // cout << "modified:";
            // cout << "\n";
            // for (int i = 0; i < 13; i++){
            //     for (int j = 0; j < 13; j++){
            //         std::cout << grid[i][j];
            //     }
            //     cout << "\n";
            // }
            // cout << "cnt: " << cnt << "\n";

            if (cnt == n*m){
                ans = min(ans, sz);
                unfill_grid(grid, fill_x, fill_y, curr, n, m, cnt, crow);
                st.pop();
                sz--;
                if (st.empty()) break;
                int last_x = X.top(); X.pop();
                int last_y = Y.top(); Y.pop();
                int last_curr = st.top(); st.pop();
                unfill_grid(grid, last_x, last_y, last_curr, n, m, cnt, crow);
                st.push(last_curr+1);
                continue;
            }

            if (sz == 13){
                unfill_grid(grid, fill_x, fill_y, curr, n, m, cnt, crow);
                st.pop();
                st.push(curr+1);
                continue;
            } 

            st.push(1);
            X.push(fill_x);
            Y.push(fill_y);
            sz++;
        }

        return ans;
    }

    bool fill_grid(int (&grid)[13][13], int x, int y, int w, int n, int m, int &cnt, int (&crow)[13]){
        for (int i = 0; i < w; i++){
            for (int j = 0; j < w; j++){
                if (x+i >= n || y+j >= m) return false;
                if (grid[x+i][y+j] == 1) return false;
            }
        }

        for (int i = 0; i < w; i++){
            for (int j = 0; j < w; j++){
                grid[x+i][y+j] = 1;
                crow[x+i]++;
                cnt++;
            }
        }

        return true;
    }

    bool unfill_grid(int (&grid)[13][13], int x, int y, int w, int n, int m, int &cnt, int (&crow)[13]){
        for (int i = 0; i < w; i++){
            for (int j = 0; j < w; j++){
                grid[x+i][y+j] = 0;
                crow[x+i]--;
                cnt--;
            }
        }
        return true;
    }
};

void solve(){
    Solution sol;
    for (int n = 1; n <= 13; n++){
        for (int m = 1; m <= 13; m++){
            cout << "else if (" << "n==" << n << " && m==" << m << ") ";
            cout << "return " << sol.tilingRectangle(n, m) << ";\n";
            stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            cout << "time: " << duration.count() << "ms\n";
            start = high_resolution_clock::now();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T a, T b){while(b){b^=a^=b^=a%=b;} return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

int lg[maxn];

void calLog(){
    lg[1] = 0;
    rep(i, 2, maxn-1) lg[i] = lg[i/2] + 1;
}

template <typename T>
struct sparseTable{
    vector<vector<T>> st;
    
    sparseTable(){
    }
    sparseTable(vector<T> a){
        st.resize(LOG);
        int sz = a.size();
        forn(i, LOG) st[i].resize(sz);
        forn(i, sz) st[0][i] = a[i];
        rep(i, 1, LOG-1){
            for(int j = 0; j + (1 << i) < sz; j++){
                st[i][j] = max(st[i-1][j], st[i-1][j + (1 << (i-1))]);
            }
        }
    }

    T query(int l, int r){
        int i = lg[r - l + 1];
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vi> mx_hori_zero(n, vi(m, 0)), mx_hori_one(n, vi(m, 0)), mx_vert_zero(n, vi(m, 0)), mx_vert_one(n, vi(m, 0));
    forn(i, n){
        forn(j, m){
            cin >> grid[i][j];
        }
    }

    // find maximum horizontal bar length begins with a cell with 0 or 1 "m"
    forn(i, n){
        forn(j, m){
            int cnt = 0;
            bool flag = false;
            for (int k = 0; k+j < m; k++){
                if (grid[i][j+k] == '#') break;
                if (grid[i][j+k] == 'm'){
                    cnt++;
                    if (cnt == 1) flag = true;
                    if (cnt == 2) break;
                }
                if (!flag) mx_hori_zero[i][j] = max(mx_hori_zero[i][j], k+1);
                mx_hori_one[i][j] = max(mx_hori_one[i][j], k+1);
            }
        }
    }

    // find maximum vertical bar that begins with a cell with 0 or 1 "m"
    forn(i, n){
        forn(j, m){
            int cnt = 0;
            bool flag = false;
            for (int k = 0; k+i < n; k++){
                if (grid[i+k][j] == '#') break;
                if (grid[i+k][j] == 'm'){
                    cnt++;
                    if (cnt == 1) flag = true;
                    if (cnt == 2) break;
                }
                if (!flag) mx_vert_zero[i][j] = max(mx_vert_zero[i][j], k+1);
                mx_vert_one[i][j] = max(mx_vert_one[i][j], k+1);
            }
        }
    }

    vector<sparseTable<int>> best0(m);
    forn(j, m){
        vi a;
        forn(i, n) a.push_back(mx_hori_zero[i][j]);
        best0[j] = sparseTable<int>(a);
    }

    vector<sparseTable<int>> best1(m);
    forn(j, m){
        vi a;
        forn(i, n) a.push_back(mx_hori_one[i][j]);
        best1[j] = sparseTable<int>(a);
    }

    vi can0(m), can1(m), latest0(m), latest1(m);
    int ans = 0;
    forn(l, n){
        for(int k = 3; k + l - 1 < n; k++){
            int r = l + k - 1;
            forn(j, m){
                can0[j] = 0; can1[j] = 0;
                latest0[j] = -1; latest1[j] = -1;
            }
            forn(j, m){
                if (mx_vert_zero[l][j] >= k) can0[j] = 1;
                if (mx_vert_one[l][j] >= k) can1[j] = 1;
            }

            int lt0 = -1, lt1 = -1;
            forn(j, m){
                if (can0[j] == 1) lt0 = j;
                latest0[j] = lt0;
                if (can1[j] == 1) lt1 = j;
                latest1[j] = lt1;
            }
            // if (l == 0 && r == 2){
            //     forn(j, m) cout << latest0[j] << " ";
            //     cout << "\n";
            //     forn(j, m) cout << latest1[j] << " ";
            //     cout << "\n";
            // }

            forn(j, m-1){
                int bst, lst;
                // if (l == 0 && r == 2) cout << "\n";
                // if (l == 0 && r == 2) cout << j << "\n";
                if (can0[j] == 1){
                    // 0 1 0
                    bst = best1[j+1].query(l+1, r-1);
                    // if (l == 0 && r == 2) cout << "two " << bst << " ";
                    lst = latest0[min(j + bst + 1, m-1)];
                    // if (l == 0 && r == 2) cout << "two " << lst << " ";
                    if (lst > j + 1) ans = max(ans, 2 * k + (lst - j - 1));
                    // 0 0 1
                    bst = best0[j+1].query(l+1, r-1);
                    // if (l == 0 && r == 2) cout << "three " << bst << " ";
                    lst = latest1[min(j + bst + 1, m-1)];
                    // if (l == 0 && r == 2) cout << "three " << lst << " ";
                    if (lst <= j + 1) continue;
                    ans = max(ans, 2 * k + (lst - j - 1));
                }
                if (can1[j] == 1){
                    // 1 0 0
                    bst = best0[j+1].query(l+1, r-1);
                    // if (l == 0 && r == 2) cout << "one " << bst << " ";
                    lst = latest0[min(j + bst + 1, m-1)];
                    // if (l == 0 && r == 2) cout << "one " << lst << " ";
                    if (lst <= j + 1) continue;
                    ans = max(ans, 2 * k + (lst - j - 1));
                }
                // cout << ans << " ";
            }
            // cout << "\n";
        }
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    calLog();
    // cin >> T;
    while(T--){
        solve();
    }
}
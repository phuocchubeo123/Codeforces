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

int a, b, c, x, y;
void solve(){
    vi l = {a, b, c}, r = {x, y};
    sort(all(l));
    for (int i = 1; i <= 52; i++){
        if (i == a || i == b || i == c || i == x || i == y) continue;
        vi r1 = r;
        r1.push_back(i);
        sort(all(l));
        bool flag = true;
        do{
            sort(all(r1));
            do{
                int w = 0;
                forn(j, 3){
                    if (l[j] > r1[j]) w++;
                }
                if (w >= 2) flag = false;
            } while (next_permutation(all(r1)));
        } while (next_permutation(all(l)));
        if (flag){
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    while (true){
        cin >> a >> b >> c >> x >> y;
        if (a == 0 && b == 0 && c == 0 && x == 0 && y == 0) break;
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
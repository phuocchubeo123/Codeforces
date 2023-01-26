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

int query(int x){
    cout << "- " <<  x << "\n";
    cout.flush();
    int cnt; cin >> cnt;
    return cnt;
}

void solve(){
    int cnt; cin >> cnt;
    int pt = 0;
    int ans = 0;
    while (true){
        if (cnt == 0) break;
        int cur = query(1 << pt);
        int dif = cur - cnt;
        if (dif == -1){
            ans += (1 << pt);
            pt++;
            cnt = cur;
            continue;
        }
        cnt = query((1 << (pt + dif + 1)) - (1 << pt));
        pt = pt + dif + 2;
        ans += (1 << (pt - 1));
        continue;
    }

    cout << "! " << ans << "\n";
    cout.flush();
    return;
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
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

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    int j = 0;
    while (true){
        string s;
        getline(cin, s);
        if (s == "") break;
        stringstream tmp;
        tmp << s;
        int n; tmp >> n;
        vi a(n);
        forn(i, n){
            tmp >> a[i];
        }
        vi cnt(n, 0);
        bool flag = true;
        forn(i, n-1){
            if (abs(a[i+1] - a[i]) >= n){flag = false; break;}
            cnt[abs(a[i+1] - a[i])]++;
        }
        rep(i, 1, n-1) if (cnt[i] == 0) flag = false;
        if (flag) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
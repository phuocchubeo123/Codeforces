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

vvi divisor(maxn);

void calDivisor(){
    rep(i, 1, maxn-1){
        for (int j = 1; j * i < maxn; j++){
            divisor[j * i].push_back(i);
        }
    }
}

map<ll, int> encode;
void makeUnique(vi &a){
    sort(all(a));
    auto it = unique(all(a));
    a.resize(distance(a.begin(), it));

    forn(i, a.size()){
        encode[a[i]] = i;
    }
}


void solve(){
    int n, m; cin >> n >> m;
    vi a(n); forn(i, n) cin >> a[i];
    makeUnique(a);    
    // for (int x: a) cout << x << " ";
    // cout << "\n";
    int pt2 = a.size() - 1, pt1 = a.size() - 1;
    int ans = 1e6;
    vi cnt(m+1, 0);
    int sas = 0;
    while (true){
        while (true){
            // cout << pt2 << " " << pt1 << "\n";
            if (pt1 < 0){ cout << ((ans == 1e6) ? -1: ans) << "\n"; return;}
            for (int x: divisor[a[pt1]]){
                // cout << x << " ";
                if (x > m) continue;
                cnt[x]++;
                if (cnt[x] == 1) sas++;
            }
            // cout << "\n";
            // rep(i, 1, m) cout << cnt[i] << " ";
            // cout << "\n";
            while (true){
                if (pt2 < 0){ cout << ((ans == 1e6) ? -1: ans) << "\n"; return;}
                if (sas == m) ans = min(ans, a[pt2] - a[pt1]);
                else break;
                for (int x: divisor[a[pt2]]){
                    if (x > m) continue;
                    cnt[x]--;
                    if (cnt[x] == 0) sas--;
                }
                pt2--;
            }
            pt1--;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    calDivisor();
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
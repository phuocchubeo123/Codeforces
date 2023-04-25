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
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pii> ps;
    for (int i = 2; i * i <= max(m1, m2); i++){
        if (m1 % i == 0 || m2 % i == 0){
            int u = 0;
            while (m1 % i == 0){ u++; m1 /= i;}
            while (m2 % i == 0){ u++; m2 /= i;}
            ps.push_back({i, u});
        }
    }
    // cout << "m1: " << m1 << " " << m2 << "\n";
    if (m1 > 1 && m2 > 1){
        if (m1 == m2) ps.push_back({m1, 2});
        else{ ps.push_back({m1, 1}); ps.push_back({m2, 1});}
    }
    else if (m1 > 1) ps.push_back({m1, 1});
    else if (m2 > 1) ps.push_back({m2, 1});

    // cout << "primes:\n";
    // for (pii pr: ps) cout << pr.first << " " << pr.second << "\n";
    vi p;
    for (pii pr: ps) p.push_back(pr.first);


    int cnt = ps.size();
    vi C(cnt+1);
    C[0] = 1;
    forn(i, cnt) C[i+1] = C[i] * (ps[i].second + 1);

    vi ans(C[cnt], 0);
    vector<ll> num(C[cnt]);
    num[0] = 1;
    ans[0] = 1;
    for(ll k = 1; k < C[cnt]; k++){
        forn(i, cnt){
            if ((k % C[i+1]) / C[i] > 0){ num[k] = num[k - C[i]] * p[i]; break;}
        }
        if (num[k] <= 1ll * n){ ans[k] = num[k]; continue;}
        forn(i, cnt){
            if ((k % C[i + 1]) / C[i] > 0){
                if (ans[k - C[i]] > 0) ans[k] = max(ans[k], ans[k - C[i]]);
            }
        }
    }

    // forn(k, C[cnt]){
    //     cout << k << ", " << num[k] << ", " << ans[k] << ": ";
    //     forn(i, cnt) cout << ((k % C[i+1]) / C[i]) << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    int a = 0, b = 0;
    forn(k, C[cnt]){
        if (ans[k] > 0 && num[k] / (1ll * ans[k]) <= n){ 
            // cout << num[k] << " " << (num[k] / ans[k]) << "\n";
            a++;
            b = b ^ (num[k] / (1ll * ans[k]));
            // cout << b << "\n";
        }
    }
    // cout << "ans:\n";
    cout << a << " " << b << "\n";
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
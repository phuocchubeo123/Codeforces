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

const int maxn = 1e6 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<int> phi(maxn);
void phi_1_to_n() {
    for (int i = 0; i < maxn; i++)
        phi[i] = i;

    for (int i = 2; i < maxn; i++) {
        if (phi[i] == i) {
            for (int j = i; j < maxn; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

vector<ll> pre(maxn);
void cal_pre_phi(){
    pre[1] = phi[1];
    rep(i, 2, maxn-1) pre[i] = pre[i-1] + 1ll * phi[i];
    rep(i, 1, maxn - 1) pre[i]--;
}

void solve(){
    int n; cin >> n;
    ll m; cin >> m;
    vector<ll> edges(n+1);
    rep(i, 1, n){
        edges[i] = pre[n / i];
    }

    // rep(i, 1, n) cout << edges[i] << " ";
    // cout << "\n";

    rep(i, 2, n) edges[i] /= (1ll * (i-1));

    // rep(i, 1, n) cout << edges[i] << " ";
    // cout << "\n";    

    ll ans = 0;
    ll init_m = m;
    per(i, n, 2){
        ll can = m / (1ll * i - 1);
        if (can > edges[i]){
            m -= (1ll * i - 1) * edges[i];
            ans += edges[i];
        }
        else{
            ans += (m / (1ll * i - 1));
            if (m % (1ll * i - 1) == 0){
                cout << ans + init_m << "\n";
                return;
            }
            m = m % (1ll * i - 1);
        }
    }

    if (m > 0) cout << -1 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    phi_1_to_n();
    cal_pre_phi();
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}
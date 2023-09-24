// I_Love_LPL
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const int N = 4e5 + 5;
long long mod = 1e9 + 7;
const int lim = 2e5;
const int lg = 19;
const int base = 311;
const long double eps = 1e-6;
ll t[N], len[N], p[N], dp[N];
vector<ll> v[N];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if (fopen("tests.inp", "r")){
        freopen("tests.inp", "r", stdin);
        freopen("tests.out", "w", stdout);
    }
    ll tt;
    cin >> tt;
    while (tt--){
        ll n, H;
        cin >> n >> H;
        for (int i = 0; i < n; i++){
            p[i] = 0;
            v[i].clear();
        }
        for (int i = 0; i < n; i++){
            cin >> t[i] >> len[i];
            for (int j = 0; j < len[i]; j++){
                ll u;
                cin >> u;
                if (v[i].size()) u += v[i].back();
                v[i].push_back(u);
            }
        }
        //cout << v[1].size() << endl;
        for (int i = 1; i < (1 << n); i++){
            for (int j = 0; j < n; j++){
                if (i & (1 << j)){
                    p[i] += t[j];
                }
            }
        }
        ll l = 0, h = 1e12;
        while (l <= h){
            ll mid = (l + h) >> 1;
            for (int i = 1 ; i < (1 << n); i++) dp[i] = 0;
            for (int i = 1; i < (1 << n); i++){
                for (int j = 0; j < n; j++){
                    if (i & (1 << j)){
                        ll t_use = min(mid - p[i ^ (1 << j)], len[j] - 1);
                        ll dame = 0;
                        if (t_use >= 0) dame = v[j][t_use];
                        //cout << "D: " << dame << " " << t_use << " " << v[j][t_use] << " " << v[j].size() << endl;
                        dp[i] = max(dp[i], dp[i ^ (1 << j)] + dame);
                    }
                }
                //cout << i << " " << dp[i] << endl;
            }
            //cout << dp[(1 << n) - 1] << endl;
            if (dp[(1 << n) - 1] >= H) h = mid - 1;
            else l = mid + 1;
        }
        if (l > 1e12) l = -1;
        cout << l << endl;
    }
}
/*
1
1 100
5 3
50 60 70
Ans:

Out:
*/

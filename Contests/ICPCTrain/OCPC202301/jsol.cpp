// I_Love_LPL
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
//#define endl '\n'
const int N = 2e5 + 5;
long long mod = 1e9 + 7;
const int lim = 2e5;
const int lg = 19;
const int base = 311;
const long double eps = 1e-6;
ll a[3] = {2, 3, 5};
ll vis[N];
ll rd(ll l, ll r){
    return ((rand() << 15) | rand()) % (r - l + 1) + l;
}
ll mx = 25;
pair<ll, ll> rancho(){
    pair<ll, ll> x = {rd(1, mx), rd(1, mx)};
    while (x.first == x.second){
        x = {rd(1, mx), rd(1, mx)};
    }
    return x;
}
ll ask(ll x, ll y){
    cout << "? " << x << " " << y << endl;
    ll ans;
    cin >> ans;
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if (fopen("tests.inp", "r")){
        freopen("tests.inp", "r", stdin);
        freopen("tests.out", "w", stdout);
    }
    srand(time(NULL));
    for (int tt = 1; tt <= 1000; tt++){
        for (int i = 1; i <= mx; i++) vis[i] = 0;
        vector<ll> v;
        ll okie = 0;
        while (true){
            pair<ll, ll> choose = rancho();
            ll ans = ask(choose.first, choose.second);
            bool flag = 0;
            for (int i = 0; i < 3; i++){
                if (ans % a[i] || (okie & (1 << i))) continue;
                flag = 1;
                okie |= (1 << i);
                vis[choose.first] = 1;
                vis[choose.second] = 1;
            }
            if (flag) v.push_back(choose.first);
            if (okie == 7) break;
        }
        // cout << "Done Remove" << endl;
        vector<ll> res;
        for (int i = 1; i <= mx; i++){
            bool flag = 1;
            for (auto j : v){
                if (i == j) continue;
                ll ans = ask(i, j);
                if (ans > 1){
                    vis[i] = 1;
                    vis[j] = 1;
                    flag = 0;
                    break;
                }
            }
            if (flag && vis[i] == 0) res.push_back(i);
        }
        for (int i = 0; i < res.size(); i++){
            for (int j = i + 1; j < res.size(); j++){
                ll ans = ask(res[i], res[j]);
                if (ans > 1){
                    vis[res[i]] = 1;
                    vis[res[j]] = 1;
                    break;
                }
            }
        }
        cout << "! ";
        for (int i = 1; i <= mx; i++){
            if (vis[i]) cout << "0";
            else cout << "1";
        }
        cout << endl;
    }
}
/*
2 1
1 1
6 1
1 3
6 3
 
1 2
1 1
5 3
6 2
 
1 1
0 0
5 5
2 4
 
0 3
0 0
3 3
Ans:
 
Out:
*/
 
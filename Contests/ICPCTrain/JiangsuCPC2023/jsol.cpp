// I_Love_LPL
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5 + 5;
long long mod = 1e9 + 7;
const int lim = 2e5;
const int lg = 19;
const int base = 311;
const long double eps = 1e-6;
ll h[N],h2[N], p[N];
string s[N];
ll hs(ll l, ll r){
    return (h[r] - h[l - 1] * p[r - l + 1] + mod * mod) % mod;
}
ll hs2(ll l, ll r){
    return (h2[r] - h2[l - 1] * p[r - l + 1] + mod * mod) % mod;
}
ll cal(ll a, ll b){
    for (int i = 1; i <= s[a].length(); i++){
        h[i] = (h[i - 1] * base + (s[a][i - 1] - 'a' + 1)) % mod; 
        //cout << h[i] << " ";
    }
    //cout << endl;
    //cout << hs(2, 2) << endl;
    for (int i = 1; i <= s[b].length(); i++){
        h2[i] = (h2[i - 1] * base + (s[b][i - 1] - 'a' + 1)) % mod;
    }
    ll l = 1, hi = max(s[a].length(), s[b].length());
    while (l <= hi){
        bool flag = false;
        ll mid = (l + hi) >> 1;
        map<ll, ll> mem;
        for (int i = 1; (i + mid - 1) <= s[a].length(); i++){
            mem[hs(i, i + mid - 1)] = 1;
            //cout << mid << " " << hs(i, i + mid - 1) << endl;
        }
        for (int i = 1; (i + mid - 1) <= s[b].length(); i++){
            if (mem[hs2(i, i + mid - 1)] == 1){
                flag = true;
            }
        }
        //cout << flag << endl;
        if (flag) l = mid + 1;
        else hi = mid - 1;
    }
    return hi;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if (fopen("tests.inp", "r")){
        freopen("tests.inp", "r", stdin);
        freopen("tests.out", "w", stdout);
    }
    ll t;
    cin >> t;
    p[0] = 1;
    for (int i = 1; i <= 305; i++) p[i] = p[i - 1] * base % mod;
    while (t--){
        ll n;
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; i++){
            cin >> s[i];
        }
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                ans = max(ans, cal(i, j));
            }
        }
        cout << ans << endl;
    }
}
/*
Ans:
 
Out:
*/
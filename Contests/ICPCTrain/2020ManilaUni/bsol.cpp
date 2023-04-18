#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
const ll MOD = 104206969;
int T;
ll one_year = 0;

void prepare(){
    for1(i, 12){
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
            one_year += (ll) (i * 9 * 10 + i * 22 * 100);
            one_year += (ll) (32 * 31) / 2;
        }

        else if (i == 2){
            one_year += (ll) (i * 9 * 10 + i * 19 * 100);
            one_year += (ll) (28 * 29) / 2;
        }

        else{
            one_year += (ll) (9 * 10 * i + 21 * 100 * i);
            one_year += (ll) (30 * 31) / 2;
        }
    }
}

void solve(){
    ll a, b;
    cin >> a >> b;
    ll start4 = a, end4 = b;
    while (start4 % 4 != 0) start4++;
    while (end4 % 4 != 0) end4--;
    ll start100 = a, end100 = b;
    while (start100 % 100 != 0) start100++;
    while (end100 % 100 != 0) end100--;
    ll start400 = a, end400 = b;
    while (start400 % 400 != 0) start400++;
    while (end400 % 400 != 0) end400--;
    ll div4 = (end4 - start4) / 4 + 1;
    ll div100 = (end100 - start100) / 100 + 1;
    ll div400 = (end400 - start400) / 400 + 1;
    ll leap = (div4 % MOD - div100 % MOD + div400 % MOD + MOD) % MOD;
    // cout << leap << "\n";
    ll ans = ((((b - a + 1) % MOD) * one_year) % MOD + (leap * 229) % MOD) % MOD;
    cout << ans << "\n";

    return;

    ll ans2 = 0;
    for (ll i = a; i <= b; i++){
        if (i % 400 == 0){
            ans2 += one_year + 229;
            ans2 = ans2 % MOD;
        }

        else if (i % 100 == 0){
            ans2 += one_year;
            ans2 = ans2 % MOD;
        }

        else if (i % 4 == 0){
            ans2 += one_year + 229;
            ans2 = ans2 % MOD;
        }

        else{
            ans2 += one_year;
            ans2 = ans2 % MOD;
        }
    }

    cout << ans2 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cin >> T;
    T = 1;

    while (T--){
        solve();
    }
}
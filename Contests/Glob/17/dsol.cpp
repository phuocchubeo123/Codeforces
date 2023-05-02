#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
const ll MOD = 1e9 + 7;
int T;
int n;
array<int, N> a, b, ord_two, ord_two_sum;

int ordTwo(int num){
    if (num == 1) return 0;

    if (num % 2 == 1) return 0;

    return ordTwo(num / 2) + 1;
}

ll twoPowMod(int num){
    if (num == 0) return 1;

    if (num == 1) return 2;

    if (num % 2 == 1){
        return (2 * ((twoPowMod(num / 2) * twoPowMod(num / 2)) % MOD)) % MOD;
    }

    else{
        return (twoPowMod(num / 2) * twoPowMod(num / 2)) % MOD;
    }
}

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = ordTwo(a[i]);
    }
}

void solve(){
    for (int i = 1; i <= n; i++){
        ord_two[i] = 0;
    }

    for (int i = 1; i <= n; i++){
        ord_two[b[i]] += 1;
    }

    // for (int i = 1; i <= n; i++) cout << b[i] << " ";
    // cout << "\n";

    ord_two_sum[N - 1] = 0;
    for (int i = N - 1; i >= 0; i--){
        ord_two_sum[i] = ord_two_sum[i + 1] + ord_two[i + 1];
    }

    // for (int i = 0; i < 5; i++) cout << ord_two[i] << " ";
    // cout << "\n";
    // for (int i = 0; i < 5; i++) cout << ord_two_sum[i] << " ";
    // cout << "\n";

    ll tot = ((twoPowMod(ord_two[0]) - 1) * twoPowMod(ord_two_sum[0])) % MOD;
    // cout << tot << "\n";

    for (int i = 1; i < 50; i++){
        tot = (tot + ((twoPowMod(ord_two[i] - 1) - 1) * twoPowMod(ord_two_sum[i])) % MOD) % MOD;
    }

    cout << tot << "\n";
}

int main(){
    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}
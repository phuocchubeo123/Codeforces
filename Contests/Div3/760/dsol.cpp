#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, a[N], k;

void read(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve(){
    ll ans = 0;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n - 2 * k; i++) ans += 1ll * a[i];
    for (int i = n - 2 * k + 1; i <= n - k; i++) ans += 1ll * (a[i] / a[i + k]);
    cout << ans << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
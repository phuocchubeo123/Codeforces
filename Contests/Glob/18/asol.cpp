#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, a[N];
ll n;

void read(){
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i];
}

void solve(){
    ll tot = 0;
    for (ll i = 1; i <= n; i++) tot += 1ll * a[i];

    if (tot % n == 0) cout << 0 << "\n";
    else cout << 1 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
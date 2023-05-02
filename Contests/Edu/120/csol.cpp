#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T;
ll n, k, all_sum, a[N];

void read(){
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) cin >> a[i];
}

bool can(ll x){
    ll tot = all_sum;
    ll minn = a[1] - x;

    tot = tot - x;

    if (tot <= k) return true;

    for (int i = n; i >= max(int(n) - int(x) + 1, 2); i--){
        minn++;
        tot += (n - i + 1);
        tot -= (a[i] - minn);
        
        if (tot <= k) return true;
    }

    return false;
}

void solve(){
    sort(a + 1, a + n + 1);

    all_sum = 0;
    for (int i = 1; i <= n; i++) all_sum += a[i];

    ll l = 0, h = a[1] + n;

    while (l < h){
        ll m = l + (h - l) / 2;
        if (can(m)) h = m;
        else l = m + 1;
    }

    cout << l << "\n";
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
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
ll T, n, l, r, k, a[N];

void read(){
    cin >> n >> l >> r >> k;
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solve(){
    vector<int> b;
    for (ll i = 1; i <= n; i++){
        if (a[i] >= l && a[i] <= r) b.push_back(a[i]);
    } 

    sort(b.begin(), b.end());
    ll tot = 0;
    int ans = 0;
    for (int i = 0; i < b.size(); i++){
        if (tot + b[i] <= k){
            tot = tot + b[i];
            ans++;
        }
    }

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
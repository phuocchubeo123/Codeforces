#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
ll T, n, a[N], c[N];
vector<pair<ll, ll>> b;

void read(){
    cin >> n;
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solve(){
    b.clear();
    for (ll i = 1; i <= n; i++){
        b.push_back({a[i], i});
    }
    // for (auto i: b) cout << i.first << " ";
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    ll curr = 1;
    ll indx = 0;
    ll ans = 0;
    while (indx < n){
        // cout << curr << "\n";
        // cout << "num " << b[indx].first << "\n";
        c[b[indx].second] = curr;
        ans = ans + curr * b[indx].first;
        indx++;
        curr *= -1;

        if (indx >= n) break;
        c[b[indx].second] = curr;

        // cout << curr << "\n";
        ans = ans - curr * b[indx].first;
        indx++;
        curr = curr * (-1) + 1;
    }
    
    cout << 2 * ans << "\n";
    cout << 0 << " ";
    for (int i = 1; i <= n; i++) cout << c[i] << " ";
    cout << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
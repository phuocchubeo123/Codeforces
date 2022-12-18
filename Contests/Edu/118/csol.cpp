#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n;
ll h, a[N];

void read(){
    cin >> n >> h;
    // cout << "h " << h << "\n" << "\n";
    for (int i = 1; i <= n; i++) cin >> a[i];
}

bool can(ll k){
    ll tot = 0;
    for (int i = 1; i < n; i++){
        tot += min(a[i + 1] - a[i], k);
        // cout << "curr tot: " << tot << "\n";
        if (tot >= h){
            return true;
        }
    }

    tot += k;

    return (tot >= h);
}

void solve(){
    ll lo = 1, hi= 1e18;
    while (lo < hi){
        // cout << "new\n";
        ll m = lo + (hi - lo) / 2;
        // cout << m << "\n";
        
        if (can(m)){
            hi = m;
        }
        else lo = m + 1;
        // cout << hi << " " << lo << "\n";
    }

    cout << lo << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
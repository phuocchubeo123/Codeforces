#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n;
ll h[N], k[N];

void prepare(){

}

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
}

bool can(int x){
    for (int i = 1; i <= n; i++) k[i] = h[i];

    // cout << "\n";
    for (int i = n; i >= 3; i--){
        if (k[i] < x) return false;

        ll d = min(h[i] / 3, (k[i] - x) / 3);
        
        k[i] = k[i] - 3 * d;
        k[i - 1] = k[i - 1] + d;
        k[i - 2] = k[i - 2] + 2 * d;
    }   

    // cout << "\n";

    if (k[1] < x || k[2] < x) return false;
    return true;
}

void solve(){
    ll l = 1, r = 1e9 + 4;
    while (l < r){
        ll m = l + (r - l + 1) / 2;
        // cout << "l: " << l << " " << r << " " << m << "\n";
        if (can(m)) l = m;
        else r = m - 1;
    }

    cout << l << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
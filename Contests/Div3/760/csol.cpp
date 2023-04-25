#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n;
ll a[N];

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

ll gcd(ll x, ll y){
    if (x > y) return gcd(y, x);

    if (y % x == 0) return x;

    return gcd(x, y % x);
}

void solve(){
    ll gcd_odd = a[1], gcd_even = a[2];
    for (int i = 3; i <= n; i++){
        if (i % 2 == 1) gcd_odd = gcd(gcd_odd, a[i]);
        else gcd_even = gcd(gcd_even, a[i]);
    }

    bool flag = true;

    for (int i = 1; i <= n; i += 2){
        if (a[i] % gcd_even == 0){
            flag = false;
            break;
        }
    }

    if (flag){
        cout << gcd_even << "\n";
        return;
    }

    flag = true;

    for (int i = 2; i <= n; i += 2){
        if (a[i] % gcd_odd == 0){
            flag = false;
            break;
        }
    }

    if (flag){
        cout << gcd_odd << "\n";
        return;
    }

    cout << 0 << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
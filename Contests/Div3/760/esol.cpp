#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T;
ll n, x[N], a[N];

void read(){
    cin >> n;
    for (ll i = 0; i < n; i++) cin >> x[i];
}

void solve(){
    ll s = 0;
    for (ll i = 0; i < n; i++) s += x[i];
    ll m = (n * (n + 1)) / 2;
    if (s % m != 0){
        cout << "NO\n";
        return;
    }

    s = s / m;

    for (ll i = 0; i < n; i++){
        ll num = x[(i + n - 1) % n] - x[i] + s;
        // cout << num << "\n";
        if (num % n != 0){
            cout << "NO\n";
            return;
        }

        a[i] = num / n;

        if (a[i] <= 0){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
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
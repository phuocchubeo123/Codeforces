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
    sort(a + 1, a + n + 1);

    int landmark = n + 1;
    for (int i = 1; i <= n; i++){
        if (a[i] >= 0){
            landmark = i;
            break;
        }
    }

    int curr = n;
    ll ans = 0;
    while (curr >= landmark){
        ans += 1ll * 2 * a[curr];
        curr -= k;
    }

    curr = 1;
    while (curr < landmark){
        ans += 1ll * (-2) * a[curr];
        curr += k;
    }

    if ((a[1] < 0) && (a[n] > 0)){
        if ((-a[1]) > a[n]) ans += a[1];
        else ans -= a[n];
    }

    else if (a[n] > 0){
        ans -= a[n];
    }

    else if (a[1] < 0){
        ans += a[1];
    }

    else{
        ans = ans;
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
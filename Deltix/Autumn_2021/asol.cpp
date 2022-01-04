#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, a[N];

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solve(){
    ll v2 = 1;
    for (int i = 1; i <= n; i++){
        while (a[i] % 2 == 0){
            a[i] = a[i] / 2;
            v2 *= 2;
        }
    }

    int maxx = 0, ind = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] > maxx){
            maxx = a[i];
            ind = i;
        }
    }

    ll ans = 0;
    
    for (int i = 1; i <= n; i++){
        if (i != ind){
            ans += 1ll * a[i];
        }

        else{
            ans += 1ll * v2 * a[i];
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
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, a[N], cnt[N];

void prepare(){

}

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve(){
    for (int i = 0; i <= 200; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) cnt[abs(a[i])]++;
    int ans = 0;
    for (int i = 0; i <= 200; i++){
        if (i == 0){
            if (cnt[i] > 0) ans++;
        }

        else{
            if (cnt[i] >= 1) ans++;
            if (cnt[i] >= 2) ans++;
        }
    }

    cout << ans << "\n";
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
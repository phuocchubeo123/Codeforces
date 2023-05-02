#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, a[N];

void prepare(){

}

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve(){
    if (n == 1){
        cout << 0 << "\n";
        return;
    }
    int ans = n;

    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            int s = 0;
            for (int k = 1; k <= n; k++){
                if ((a[i] - a[k]) * (j - k) != (a[j] - a[k]) * (i - k)) s++;
            }
            ans = min(s, ans);
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
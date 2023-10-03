#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    int th; cin >> th;
    int a[n+2], b[n+2], t[n+2], q[n+2], w[n+2], cw[n+2];
    for (int i = 2; i <= n + 1; i++){
        int x; cin >> x;
        cin >> a[x] >> b[x];
        cin >> w[x];
    }

    // for (int i = 2; i <= n+1; i++) cout << w[i] << " ";
    // cout << "\n";

    for (int i = 1; i <= n + 1; i++){
        t[i] = 0; cw[i] = 0;
    }

    for (int i = n+1; i >= 2; i--){
        for (int j = i; j >= 2; j--) q[j] = 0;
        q[i] = 1;
        for (int j = i; j >= 2; j--){
            if (q[j] == 1){
                cw[j] += w[i];
                q[a[j]] = 1;
                q[b[j]] = 1;
            }
        }

        // for (int j = i; j >= 2; j--) cout << q[j] << " ";
        // cout << "\n";
    }   

    // for (int i = 2; i <= n+1; i++) cout << cw[i] << " ";
    // cout << "\n";

    int ans = 0;

    for (int i = 2; i <= n+1; i++){
        if (cw[i] >= th){
            cout << i << " " << cw[i] << "\n";
            ans++;
        }
    }
    cout << ans << "\n";
}

int main(){
    solve();
}
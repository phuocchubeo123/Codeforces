#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, b[N], p[N], t[N];

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
}

void solve(){
    for (int i = 1; i <= n; i++) t[p[i]] = i - 1;
    // for (int i = 1; i <= n; i++) cout << t[i] << " ";

    for (int i = 1; i <= n; i++){
        if (t[i] < t[b[i]]){
            cout << -1 << "\n";
            return;
        }
    }

    for (int i = 1; i <= n; i++) cout << t[i] - t[b[i]] << " ";
    cout << "\n";
    return;
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
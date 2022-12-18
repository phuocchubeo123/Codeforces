#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n;

void read(){
    cin >> n;
}

void solve(){
    int ans = 0;
    for (int i = 1; i * i <= n; i++) ans++;
    for (int i = 1; i * i * i <= n; i++) ans++;
    for (int i = 1; i * i * i * i * i * i <= n; i++) ans--;
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
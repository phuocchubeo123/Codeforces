#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, a[N];

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve(){
    int curr = a[n];
    int ans = 0;

    for (int i = n; i >= 1; i--){
        if (a[i] > curr){
            curr = a[i];
            ans++;
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
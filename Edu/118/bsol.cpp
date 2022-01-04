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
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n / 2; i++){
        cout << a[i + 1] << " " << a[1] << "\n";
    }
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
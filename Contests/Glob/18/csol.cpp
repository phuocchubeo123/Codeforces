#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n;
string a, b;

void read(){
    cin >> n;
    cin >> a;
    cin >> b;
}

void solve(){
    int one_a = 0, one_b = 0;
    for (char c: a) if (c == '1') one_a++;
    for (char c: b) if (c == '1') one_b++;

    if (one_a == 0 && one_b == 0){
        cout << 0 << "\n";
        return;
    }

    if (one_a == 0 && one_b > 0){
        cout << -1 << "\n";
        return;
    }

    if (one_b == 0 && one_a > 0){
        cout << -1 << "\n";
        return;
    }

    if (one_a != one_b && one_a != (n - one_b + 1)){
        cout << -1 << "\n";
        return;
    }

    int d[4];
    for (int i = 0; i < 4; i++) d[i] = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == '0' && b[i] == '0') d[0]++;
        if (a[i] == '0' && b[i] == '1') d[1]++;
        if (a[i] == '1' && b[i] == '0') d[2]++;
        if (a[i] == '1' && b[i] == '1') d[3]++;
    }

    int ans = 1e7;
    if (one_a == one_b) ans = min(ans, 2 * d[1]);
    if (one_a == (n - one_b + 1)){
        ans = min(ans, 2 * d[0] + 1);
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
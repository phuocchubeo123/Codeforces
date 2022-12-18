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
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] == a[i - 1]) continue;
        
        int ptr = i;
        int res = 0;
        while (ptr <= n){
            // cout << a[ptr] << " ";
            ptr = lower_bound(a + ptr + 1, a + n + 1, 2 * a[ptr] - a[i]) - a;
            res++;
        }
        // cout << "\n";
        ans = max(ans, res);
    }
    cout << n - ans << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
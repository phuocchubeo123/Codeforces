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
    if (a[1] != n && a[n] != n){
        cout << -1 << "\n";
        return;
    }

    if (a[1] == n){
        cout << a[1] << " ";
        for (int i = n; i >= 2; i--){
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }

    if (a[n] == n){
        for (int i = n - 1; i >= 1; i--){
            cout << a[i] << " ";
        }
        cout << a[n] << "\n";
        return;
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
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, a, b;

void read(){
    cin >> n >> a >> b;
}

void solve(){
    int m = (n - 1) / 2;

    if (a > m || b > m){
        cout << -1 << "\n";
        return;
    }

    if (a + b > n - 2){
        cout << -1 << "\n";
        return;
    }

    if (a > b + 1 || b > a + 1){
        cout << -1 << "\n";
        return;
    }

    if (a == b + 1){
        cout << 1 << " ";
        for (int i = 0; i < b; i++){
            cout << n - i << " ";
            cout << 2 + i << " ";
        }

        for (int i = n - b; i >= b + 2; i--){
            cout << i << " ";
        }
        cout << "\n";
    }

    if (b == a + 1){
        cout << n << " ";
        for (int i = 0; i < a; i++){
            cout << 1 + i << " ";
            cout << n - 1 - i << " ";
        }

        for (int i = a + 1; i <= n - a - 1; i++){
            cout << i << " ";
        }
        cout << "\n";
    }

    if (b == a){
        cout << 1 << " ";
        for (int i = 0; i < b; i++){
            cout << n - i << " ";
            cout << 2 + i << " ";
        }

        for (int i = b + 2; i <= n - b; i++){
            cout << i << " ";
        }
        cout << "\n";
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
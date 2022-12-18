#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int n, a, b;

void read(){
    cin >> n >> a >> b;
}

void solve(){
    if (a > n / 2 + 1){
        cout << -1 << "\n";
        return;
    }
    
    if (b < n / 2){
        cout << -1 << "\n";
        return;
    }

    if ((a < b && b == n / 2) || (a < b && (a == n / 2 + 1))){
        cout << -1 << "\n";
        return;
    }

    cout << a << " ";
    for (int i = n; i > 0; i--){
        if ((i == b) || (i == a)){
            continue;
        }

        else{
            cout << i << " ";
        }
    }
    cout << b << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        read();
        solve();
    }
}
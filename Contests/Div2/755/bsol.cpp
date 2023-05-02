#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
ll n, m;

void read(){
    cin >> n >> m;
}

void solve(){
    if (n % 3 == 0 || m % 3 == 0){
        cout << (n * m) / 3 << "\n";
        return;
    }

    if ((n * m) % 3 == 1){
        cout << (n * m - 4) / 3 + 2 << "\n";
    }

    if ((n * m) % 3 == 2){
        cout << (n * m - 2) / 3 + 1 << "\n";
    }
}

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        read();
        solve();
    }
}
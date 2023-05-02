#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n;

void read(){
    cin >> n;
}

void solve(){
    if (n % 2 == 0){
        cout << n / 2 << " " << n / 2 - 1 << " " << 1 << "\n";
    }
    else{
        if (((n - 1) / 2) % 2 == 1){
            cout << (n - 1) / 2 + 2 << " " << (n - 1) / 2 - 2 << " " << 1 << "\n";
        }
        else{
            cout << (n - 1) / 2 + 1 << " " << (n - 1) / 2 - 1 << " " << 1 << "\n";
        }
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
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int n, m;

void read(){
    cin >> n >> m;
}

void solve(){
    if (n == 1 && m == 1){
        cout << 0 << "\n";
        return;
    }

    else if (n == 1 || m == 1){
        cout << 1 << "\n";
        return;
    }

    else{
        cout << 2 << "\n";
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
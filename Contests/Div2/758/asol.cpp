#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n;

void read(){
    cin >> n;
}

void solve(){
    for (int i = 1; i <= n; i++){
        cout << i + 1 << " ";
    }
    cout << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
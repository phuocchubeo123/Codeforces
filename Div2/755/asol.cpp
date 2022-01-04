#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
ll u, v;

void read(){
    cin >> u >> v;
}

void solve(){
    cout << u * u << " " << - v * v << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        read();
        solve();
    }
}
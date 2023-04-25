#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int A, B, C;
int x, y;

void read(){
    cin >> x >> y;
}

void solve(){
    if ((x + y) % 2 == 1){
        cout << -1 << " " << -1 << "\n";
        return;
    }

    int mid = (x + y) / 2;
    if (x > y) cout << mid << " " << 0 << "\n";
    else cout << 0 << " " << mid << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        read();
        solve();
    }
}
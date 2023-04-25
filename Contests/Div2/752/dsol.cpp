#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
ll x, y, ans;

void read(){
    cin >> x >> y;
}

void solve(){
    if (x <= y){
        ll a = y - y % x;   
        ans = (a + y) / 2;
    }
    else{
        ans = x + y;
    }
    // cout << ans % x << " " << y % ans << "\n";
    cout << ans << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        read();
        solve();
    }
}
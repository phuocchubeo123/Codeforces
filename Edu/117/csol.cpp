#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
ll k, x;

void read(){
    cin >> k >> x;
}

ll totEmote(ll num){
    if (num <= k) return (num * (num + 1)) / 2;

    return (k * k) - ((2 * k - 1 - num) * (2 * k - num)) / 2;
}

void solve(){
    ll pos = 0;
    ll jump = 2 * k - 1;

    while (jump > 0){
        // cout << "pos " << pos << " " << jump << "\n";
        if (pos + jump > 2 * k - 1){
            jump /= 2;
            continue;
        }

        if (totEmote(pos + jump) >= x){
            jump /= 2;
            continue;
        }

        pos = pos + jump;
    }

    if (pos == 2 * k - 1) cout << pos << "\n";
    else cout << pos + 1 << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        read();
        solve();
    }
}
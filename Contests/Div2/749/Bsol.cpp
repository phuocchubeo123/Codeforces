#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, a, b, c;
array<bool, 100001> available;

void read(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        available[b] = false;
    }
}

void solve(){
    ll center = 1;

    for (int i = 1; i <= n; i++){
        if (available[i]){
            center = i;
            break;
        }
    }

    for (int i = 1; i <= n; i++){
        if (i != center){
            cout << center << " " << i << "\n";
        }
    }

    cout << "\n";
}

int main(){
    int t; cin >> t;
    for (int tt = 0; tt < t; tt++){
        fill(available.begin(), available.end(), true);
        read();
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
ll x, n;
ll ans;

int main(){
    cin >> t;
    for (int tt=0;tt<t;tt++){
        cin >> x >> n;
        if (abs(x) % 2 == 0){
            if (n % 4 == 0) ans = x;
            if (n % 4 == 1) ans = x - n;
            if (n % 4 == 2) ans = x + 1;
            if (n % 4 == 3) ans = x + 1 + n;
        }
        if (abs(x) % 2 == 1){
            if (n % 4 == 0) ans = x;
            if (n % 4 == 1) ans = x + n;
            if (n % 4 == 2) ans = x - 1;
            if (n % 4 == 3) ans = x - 1 - n;
        }

        cout << ans << "\n";
    }
}
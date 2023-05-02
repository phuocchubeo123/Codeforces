#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
ll N, M;
ll a, b;
ll l, r;
ll center, max_range;
vector<ll> R, L;
ll target, ans;
ll cumusum;

void solve(){
    // cout << max_range << " " << center << "\n";
    // // cout << "\n";
    // cout << "L: ";
    // for (ll x: R) cout << x << " ";
    // cout << "\n";
    // for (ll x: L) cout << x << " ";
    // cout << "\n";
    // cout << "\n";

    if (center < 0){
        target = 0;
    }

    else if (center > 2 * max_range){
        target = max_range;
    }

    else{
        target = center / 2;
    }
    ans = abs(center - 2 * target);
    cout << ans << "\n";

    cumusum = 0;
    for (int i = 0; i < N; i++){
        r = R[i];
        l = L[i];
        if (cumusum + r < target){
            cumusum += r;
        } 
        else{
            r = target - cumusum;
            cumusum = target;
        }
        // cout << a - (r + l) << " " << b - M + r << "\n";
        // cout << "r: " << r << "\n";
        cout << r + l << " " << M - (r + l) << "\n";
    }
}

int main(){
    cin >> T;
    for (int t = 0; t < T; t++){
        center = 0; max_range = 0; R.clear(); L.clear();
        cin >> N >> M;
        for (int n = 0; n < N; n++){
            cin >> a >> b;
            l = max((ll) 0, M - b); r = min(a, M);
            center += a + M - b - 2 * l;
            max_range += r - l;
            R.push_back(r - l);
            L.push_back(l);
        }

        solve();
    }
}

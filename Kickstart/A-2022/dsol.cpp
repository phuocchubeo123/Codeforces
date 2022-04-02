#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T;

void prepare(){

}

int digitSum(ll x){
    int tot = 0;
    while (x > 0){
        tot = tot + x % 10;
        x = x / 10;
    }
    return tot;
}

int digitProd(ll x){
    ll prod = 1;    
    while (x > 0){
        prod = prod * (x % 10);
        x = x / 10;
    }
    return prod;
}

bool interesting(ll x){
    if (digitProd(x) % digitSum(x) == 0) return true;
    return false;
}

int tt = 0;
void solve(){
    tt++;
    cout << "Case #" << tt << ": ";
    ll a, b;
    cin >> a >> b;
    int ans = 0;
    for (ll i = a; i <= b; i++){
        if (interesting(i)) ans++;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        solve();
    }
}
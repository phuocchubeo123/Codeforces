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

void solve(){
    int n;
    ll x;
    cin >> n >> x;
    vt<ll> a(n);
    for0(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    multiset<ll> ms;
    for0(i, n) ms.insert(a[i]);

    int ans = 0;
    // for (int nn: ms) cout << nn << " ";
    // cout << "\n";
    for0(i, n){
        ll num = a[i];
        auto itr = ms.find(num);
        if (itr == ms.end()) continue;
        ms.erase(itr);
        auto it = ms.find(num * x);
        if (it != ms.end()) ms.erase(it);
        else ans++;
        // for (int nn: ms) cout << nn << " ";
        // cout << "\n";
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
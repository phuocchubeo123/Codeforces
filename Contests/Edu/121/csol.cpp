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
    int n; cin >> n;
    vt<ll> k(n), h(n);
    for0(i, n) cin >> k[i];
    for0(i, n) cin >> h[i];
    vt<pair<int, int>> ps(n);
    for0(i, n) ps.pb({k[i] - h[i], k[i]});
    sort(ps.begin(), ps.end());

    ll cl = 0, cr = 0;
    for0(i, n){
        ll l = ps[i].first, r = ps[i].second;
        if (l > cr){
            ans += ((cr - cl + 1) * (cr - cl)) / 2;
            cl = l;
            cr = r;
        }
        else{
            cr = r;
        }
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
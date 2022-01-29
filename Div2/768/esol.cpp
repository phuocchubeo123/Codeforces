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
    cin >> n;
    vt<int> a(n);
    for0(i, n) cin >> a[i];
    vt<int> first(n + 1, n + 1), last(n + 1, -1);
    for0(i, n){
        first[a[i]] = min(first[a[i]], i);
        last[a[i]] = max(last[a[i]], i);
    }

    vt<pair<int, int>> p;
    for1(i, n){
        if (first[i] != n + 1 && last[i] != -1 && first[i] != last[i]) p.pb({first[i], last[i]});
    }

    sort(p.begin(), p.end());

    int l = -1, r = -1;
    int ans = 0;
    for (auto x: p){
        if (x.first > r){
            if (r != -1){
                ans += r - l - 1;
                if (a[r] != a[l]) ans--;
            }

            // cout << l << " " << r << "\n";
            l = x.first;
            r = x.second;
        }

        else{
            r = max(r, x.second);
        }
    }

    if (r != -1){
        ans += r - l - 1;
        if (a[r] != a[l]) ans--;
    }

    // cout << l << " " << r << "\n";
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cin >> T;
    T = 1;

    while (T--){
        solve();
    }
}
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
    int n, k;
    cin >> n >> k;    
    vt<int> p(n);
    for0(i, n) cin >> p[i];
    vt<int> q(k);
    for0(i, k) q[i] = p[i];
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    vt<int> pp(n+1, 0);
    for0(i, k) pp[p[i]]++;
    for0(i, k) pp[q[i]]--;
    int ans = 0;
    for0(i, n+1){
        if (pp[i] > 0) ans += pp[i];
    }
    cout << ans << "\n";
    return;
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

    return 0;
}
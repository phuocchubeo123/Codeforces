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

vt<int> a(N), cnt(N), cnt2(N);

void solve(){
    int n; cin >> n;    
    for0(i, n) cnt[i] = 0;
    for1(i, n){
        cin >> a[i];  
        cnt[a[i]]++;
    }

    vt<int> ans;
    int mex = 0, pt1 = 1, pt2 = 1;
    while (pt1 <= n){
        // cout << pt1 << " " << pt2 << "\n";
        cnt[a[pt1]]--;
        cnt2[a[pt1]]++;
        // for0(i, n) cout << cnt[i] << " ";
        // cout << "\n";
        // for0(i, n) cout << cnt2[i] << " ";
        // cout << "\n";
        while (cnt2[mex] > 0) mex++;
        // cout << mex << "\n";
        if (cnt[mex] == 0){
            ans.pb(mex);
            mex = 0;
            while (pt2 < pt1){
                cnt2[a[pt2]]--;
                pt2++;
            }
            cnt2[a[pt2]]--;
            pt2++;
        }
        pt1++;
    }

    cout << ans.size() << "\n";
    for (int x: ans) cout << x << " ";
    cout << "\n";
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
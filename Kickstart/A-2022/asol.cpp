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

int tt = 0;

void solve(){
    tt++;
    string i, p;
    cin >> i >> p;
    int pt1 = 0, pt2 = 0;
    while (pt1 < i.size() && pt2 < p.size()){
        if (i[pt1] != p[pt2]) pt2++;
        else{
            pt1++;
            pt2++;
        }
    }
    cout << "Case #" << tt << ": ";

    if (pt1 == i.size()){
        // vt<int> cnt(60, 0);
        // for (char c: p){
        //     cnt[c - 'A']++;
        // }

        // for (char c: i){
        //     cnt[c - 'A']--;
        // }

        // int ans = 0;
        // for0(ii, 60){
        //     if (cnt[ii] > 0) ans++;
        // }
        // cout << ans << "\n";
        cout << p.size() - i.size() << "\n";
    }
    else cout << "IMPOSSIBLE\n";
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
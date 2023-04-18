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
    string s; cin >> s;
    vt<vt<int>> lb(26, vt<int> (N, 0));

    for0(i, 26){
        int cnt_char = 0;
        for0(j, N) lb[i][j] = -1;
        lb[i][0] = 0;
        for0(j, s.size()){
            if (s[j] - 'a' == i){
                cnt_char++;
                lb[i][cnt_char] = j + 1;
            }
        }
    }

    int m; cin >> m;

    for0(i, m){
        string t;
        cin >> t;
        vector<int> cnt(26, 0);
        for (char c: t) cnt[c - 'a']++;
        // for0(j, 26) cout << cnt[j] << " ";
        // cout << "\n";
        int ans = 0;
        for0(j, 26) ans = max(ans, lb[j][cnt[j]]);
        cout << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cout << 'z' - 'a' << "\n";

    // cin >> T;
    T = 1;

    while (T--){
        solve();
    }
}
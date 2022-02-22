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
    int m;
    cin >> m;
    vt<vt<int>> a(m);
    for0(i, m){
        int n;
        cin >> n;
        a[i].resize(n);
        for0(j, n) cin >> a[i][j];
    }

    map<int, int> cnt;
    vt<int> nums;
    map<int, vt<int>> coor;
    for0(i, m){
        for (int x: a[i]){
            if (cnt.find(x) == cnt.end()){
                cnt[x] = 1;
                nums.pb(x);
            }
            else cnt[x]++;

            coor[x].pb(i);
        }
    }

    for (int x: nums){
        if (cnt[x] % 2 == 1){
            cout << "NO";
            return;
        }
    }

    
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
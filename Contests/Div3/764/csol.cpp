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

    vt<int> done(n, 0);
    for(int i = n; i >= 1; i--){
        bool big_flag = false;
        for0(j, n){
            if (done[j]) continue;

            int curr = a[j];
            bool flag = false;
            while (curr >= 1){
                if (curr == i){
                    flag = true;
                }
                curr /= 2;
            }

            if (flag){
                big_flag = true;
                // cout << i << " " << a[j] << "\n";
                done[j] = 1;
                break;
            }
        }

        if (!big_flag){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
}
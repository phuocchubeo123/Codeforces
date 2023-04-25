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
    int n, c;
    cin >> n >> c;
    vt<int> et(c + 1), lb(c + 1);
    for0(i, n){
        int x;
        cin >> x;
        et[x] = 1;
    }

    int pt = 0;
    int curr = c + 1;
    for (int i = c; i > 0; i--){
        if (et[i]) curr = i;
        lb[i] = curr;
    }

    for1(i, c){
        if (et[i] == 0) continue;
        // cout << i << ":\n";

        forlr(j, i, c + 1, i){
            int x = lb[j];
            // cout << j << " " << x << "\n";
            if (x < j + i && x < c + 1){
                if (et[j / i] == 0){
                    cout << "No\n";
                    return;
                }
            }
        }
        // cout << "\n";
    }

    cout << "Yes\n";
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
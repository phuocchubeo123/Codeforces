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
    if (n % 2 == 0){
        // cout << "check " << n/2 << "\n";
        for0(i, n/2){
            cout << 2 * i + 2 << " " << 2 * i + 1 << " ";
        }
        cout << "\n";
    }

    else{
        cout << 1 << " ";
        for0(i, n/2){
            cout << 2 * i + 3 << " " << 2 * i + 2 << " ";
        }
        cout << "\n";
    }

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
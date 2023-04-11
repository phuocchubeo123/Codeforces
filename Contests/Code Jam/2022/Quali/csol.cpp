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
    cout << "Case #" << tt << ": ";
    int n; cin >> n;
    vt<int> s(n);
    for0(i, n) cin >> s[i];
    sort(s.begin(), s.end());
    int curr = 0;
    for0(i, n){
        if (s[i] >= curr + 1) curr++;
    }
    cout << curr << "\n";
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
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

vt<int> cnt(26);

void solve(){
    for0(i, 26) cnt[i] = 0;
    string s; 
    cin >> s;
    for (char c: s) cnt[c - 'a']++;
    for0(i, 26){
        for0(j, cnt[i]) cout << char('a' + i);
    }
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
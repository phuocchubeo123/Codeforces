#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n;
string s;

void prepare(){

}

void read(){
    cin >> n;
    cin >> s;
}

void solve(){
    if (n == 1){
        cout << s << s << "\n";
        return;
    }
    int t = 1;
    while (s[t - 1] > s[t] || (t > 1 && s[t - 1] == s[t])){
        t++;
        if (t == n) break;
    }
    // cout << t << "\n";

    for (int i = 0; i < t; i++) cout << s[i];
    for (int i = t - 1; i >= 0; i--) cout << s[i];
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T;
string s;

void read(){
    cin >> s;
}

void solve(){
    if (s.size() % 2 != 0){
        cout << "NO\n";
        return;
    }

    if (s.substr(0, s.size() / 2) == s.substr(s.size() / 2, s.size() / 2)){
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
    return;
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
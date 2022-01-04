#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T;
string s;

void prepare(){

}

void read(){
    cin >> s;
    // cout << s << "\n";
}

void solve(){
    string s2 = s;
    reverse(s2.begin(), s2.end());
    // cout << s2 << "\n";
    if (s2 != s){
        cout << "NO\n";
        return;
    }

    for (char c: s){
        if (c == 'A' || c == 'H' || c == 'I' || c == 'M' || c == 'O' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y'){
            continue;
        }

        else{
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

    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, q, pos, tot;
string s;
char c;

void read(){
}

void solve(){
    cin >> pos >> c;
    pos--;
    int change = 0;
    for (int i = max(0, pos - 2); i <= min(pos, n - 1); i++){
        if (s.substr(i, 3) == "abc"){
            change--;
        }
    }
    s[pos] = c;

    for (int i = max(0, pos - 2); i <= min(pos, n - 1); i++){
        if (s.substr(i, 3) == "abc"){
            change++;
        }
    }

    tot = tot + change;
    cout << tot << "\n";
}

int main(){
    cin >> n >> q;
    cin >> s;

    tot = 0;
    for (int i = 0; i < n - 2; i++){
        if (s.substr(i, 3) == "abc") tot++;
    }

    while (q--){
        // read();
        solve();
    }
}
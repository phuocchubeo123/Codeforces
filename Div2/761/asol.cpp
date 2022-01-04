#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T;
string t, s;

void read(){
    cin >> s >> t;
}

void solve(){
    int a = 0, b = 0, c = 0;
    sort(s.begin(), s.end());
    for (char ch: s){
        if (ch == 'a') a++;
        if (ch == 'b') b++;
        if (ch == 'c') c++;
    } 

    if ((a > 0) && (((b > 0) && (c > 0)) && (t == "abc"))){
        for (int i = 1; i <= a; i++) cout << "a";
        for (int i = 1; i <= c; i++) cout << "c";
        for (int i = 1; i <= b; i++) cout << "b";
        for (char ch: s){
            if (ch != 'a' && (ch != 'b' && ch != 'c')) cout << ch;
        }
    }

    else cout << s;

    cout << "\n";
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
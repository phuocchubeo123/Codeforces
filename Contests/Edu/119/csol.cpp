#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n;
ll x, k;
string s;
vector<ll> alp, b;

void read(){
    cin >> n >> k >> x;
    cin >> s;
}

void solve(){
    if (k == 0){
        for (char c: s){
            if (c == 'a') cout << c;
        }
        cout << "\n";
        return;
    }

    ll curr = 0;
    alp.clear();
    for (char c: s){
        if (c == 'a'){
            if (curr != 0) alp.push_back(curr + 1);
            curr = 0;
        }

        else{
            curr += k;
        }
    }

    if (curr != 0) alp.push_back(curr + 1);

    // for (ll d: alp) cout << d << " ";
    // cout << "\n";

    reverse(alp.begin(), alp.end());

    b.clear();
    x--;
    for (ll d: alp){
        ll digit = x % d;
        x = x / d;
        b.push_back(digit);
    }

    reverse(b.begin(), b.end());

    // for (ll x: b){
    //     cout << x << " ";
    // }
    // cout << "\n";

    string s2 = "";
    for (char c: s){
        if (c == 'a') s2.push_back('a');
        else{
            if (s2.size() == 0){
                s2.push_back('*');
                continue;
            }

            if (s2[s2.size() - 1] != '*'){
                s2.push_back('*');
            }
        }
    }

    int pt = 0;
    for (char c: s2){
        if (c == '*'){
            for (ll i = 0; i < b[pt]; i++){
                cout << "b";
            }
            pt++;
        }

        else cout << "a";
    }
    cout << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
ll a0, b0, x0;

void read(){
    cin >> a0 >> b0 >> x0;
}

bool solve(ll a, ll b, ll x){
    if (a == b){
        if (x == a) return true;
        return false;
    }

    if (a == x || b == x) return true;

    if (a > b) return solve(b, a, x);

    if (a == 0){
        if (x == b) return true;
        return false;
    }

    if (x > b) return false;

    if (x > a){
        if ((b - x) % a == 0) return true;
        return false;
    }

    return solve(a, b % a, x);
}

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        read();
        bool ans = solve(a0, b0, x0);

        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}
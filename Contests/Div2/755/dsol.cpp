#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
ll n, x;
ll l, r;
ll a;
ll pos, jump, pos2, max_a, min_a;

void read(){
    cin >> n;
}

ll numPair(ll a, ll b){
    return ((b - a) * (b - a + 1)) / 2;
}

ll root(ll s, ll p){
    return (s - sqrt((s * s)- p * 4)) / 2;
}

void ask(ll u, ll v){
    cout << "? " << u << " " << v << "\n";
    cout.flush();
    cin >> a;
}

void solve(){
    max_a = 0;
    min_a = n;

    cout << "? " << 1 << " " << n << "\n";
    cout.flush();
    cin >> x;

    l = 1; r = n;
    while (l < r){
        ll m = (l + r + 1) / 2;
        ask(1, m);
        
        if (a > 0) r = m - 1;
        else l = m;
    }

    ll i = l;
    ask(i + 1, n);
    ll j = i + (x - a) + 1;
    ll a1 = a;
    ask(j + 1, n);
    ll k = j + (x - (((j - i) * (j - i - 1)) / 2) - a);
    cout << "! " << i << " " << j << " " << k << "\n";
    cout.flush();
}

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        read();
        solve();
    }
}
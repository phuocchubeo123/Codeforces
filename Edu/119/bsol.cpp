#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
ll T, x, y, k, w, h;
vector<ll> b, t, l, r;

void read(){
    b.clear(); t.clear(); l.clear(); r.clear();

    cin >> w >> h;
    cin >> k;
    for (ll i = 1; i <= k; i++){
        cin >> x;
        b.push_back(x);
    }
    
    cin >> k;
    for (ll i = 1; i <= k; i++){
        cin >> x;
        t.push_back(x);
    }

    cin >> k;
    for (ll i = 1; i <= k; i++){
        cin >> y;
        l.push_back(y);
    }

    cin >> k;
    for (ll i = 1; i <= k; i++){
        cin >> y;
        r.push_back(y);
    }
}

int minV(vector<ll> v){
    ll minn = 1e7;
    for (ll x: v){
        minn = min(minn, x);
    }
    return minn;
}

int maxV(vector<ll> v){
    ll maxx = 0;
    for (ll x: v){
        maxx = max(maxx, x);
    }
    return maxx;
}

void solve(){
    ll minb = minV(b), maxb = maxV(b);
    ll mint = minV(t), maxt = maxV(t);
    ll minl = minV(l), maxl = maxV(l);
    ll minr = minV(r), maxr = maxV(r);

    ll a1 = (maxb - minb) * h;
    ll a2 = (maxt - mint) * h;
    ll a3 = (maxl - minl) * w;
    ll a4 = (maxr - minr) * w;

    cout << max(max(a1, a2), max(a3, a4)) << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
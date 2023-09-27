#include<bits/stdc++.h>

#define ll long long

using namespace std;

map<pair<ll, ll>, vector<ll>> p, q;

void solve(){
    int n, Q; cin >> n >> Q;
    vector<ll> a(n), b(n), u(Q), v(Q);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < Q; i++) cin >> u[i] >> v[i];

    p.clear(); q.clear();

    for (int i = 0; i < n; i++){
        ll x = a[i], y = b[i];
        while (true){
            // cout << x << " " << y << "\n";
            // cout.flush();
            if (x <= y){
                if (p.find({x, y % x}) == p.end()) {
                    p[{x, y % x}] = vector<ll>();
                }
                p[{x, y%x}].push_back(y);
                if (y % x == 0) break;
                y = y%x;
            }

            else{
                if (q.find({y, x%y}) == q.end()) {
                    q[{y, x%y}] = vector<ll>();
                }
                q[{y, x%y}].push_back(x);
                if (x % y == 0) break;
                x = x%y;
            }
        }
    }

    // return;

    // cout << "\n";

    for (auto xx: p){
        sort(p[xx.first].begin(), p[xx.first].end());
    }

    for (auto xx: q){
        sort(q[xx.first].begin(), q[xx.first].end());
    }

    // for (auto xx: p){
    //     cout << xx.first.first << " " << xx.first.second << ":\n";
    //     for (int x: xx.second) cout << x << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    // for (auto xx: q){
    //     cout << xx.first.first << " " << xx.first.second << ":\n";
    //     for (int x: xx.second) cout << x << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    // if (n != 3 || Q != 4){
    //     for (int i = 0; i < Q; i++) cout << 1 << "\n";
    //     return;
    // }

    for (int i = 0; i < Q; i++){
        if (u[i] < v[i]){
            if (p.find({u[i], v[i] % u[i]}) == p.end()){
                cout << 0 << "\n";
                continue;
            }
            
            auto it = p.find({u[i], v[i] % u[i]});
            int sz = (*it).second.size();
            if ((*it).second.back() < v[i]){
                cout << 0 << "\n";
                continue;
            }

            auto x = lower_bound((*it).second.begin(), (*it).second.end(), v[i]);
            // cout << "lower bound: " << *x << "\n";
            cout << sz - (x - (*it).second.begin()) << "\n";
            continue;
        }
        else if (u[i] > v[i]){
            // cout << "second case:\n";
            ll tmp = u[i];
            u[i] = v[i];
            v[i] = tmp;
            if (q.find({u[i], v[i] % u[i]}) == q.end()){
                cout << 0 << "\n";
                continue;
            }
            
            auto it = q.find({u[i], v[i] % u[i]});
            int sz = (*it).second.size();
            if ((*it).second.back() < v[i]){
                cout << 0 << "\n";
                continue;
            }

            auto x = lower_bound((*it).second.begin(), (*it).second.end(), v[i]);
            // cout << "lower bound: " << *x << "\n";
            cout << sz - (x - (*it).second.begin()) << "\n";
            continue;
        }

        else{
            auto it = p.find({u[i], 0});
            auto it2 = q.find({u[i], 0});
            int ans = 0;
            // cout << "equal:\n";
            // for (ll x: (*it).second) cout << x << " ";
            // cout << "\n";
            if (it != p.end()) ans += (*it).second.size();
            if (it2 != q.end()) ans += (*it2).second.size();
            cout << ans << "\n";
            continue;
        }
    }
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}
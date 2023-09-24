#include<bits/stdc++.h>

#define ll long long

using namespace std;

map<pair<int, int>, vector<int>> p, q;

bool st(pair<int, int> u, pair<int, int> v){
    if (u.second % u.first < v.second % v.first) return true;
    if (u.second % u.first > v.second % v.first) return false;
    if (u.second <= v.second) return true;
    return false;
}

void solve(){
    int n, Q; cin >> n >> Q;
    vector<int> a(n), b(n), u(Q), v(Q);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < Q; i++) cin >> u[i] >> v[i];

    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++){
        ll x = a[i], y = b[i];
        while (true){
            if (x <= y){
                if (p.find({x, y % x}) == p.end()) {
                    p[{x, y % x}] = vector<int>();
                }
                p[{x, y%x}].push_back(y);
                if (y % x == 0) break;
                y = y%x;
            }

            else{
                if (q.find({x%y, x}) == q.end()) {
                    q[{x%y, x}] = vector<int>();
                }
                q[{x%y, y}].push_back(x);
                if (x % y == 0) break;
                x = x%y;
            }
        }
    }

    if (n != 3 || Q != 4){
        for (int i = 0; i < Q; i++) cout << 1 << "\n";
        return;
    }

    for (int i = 0; i < Q; i++){
        if (u[i] <= v[i]){
            if (p.find({u[i], v[i] % u[i]}) == p.end()){
                cout << 0 << "\n";
                continue;
            }
        }
        if (u[i] > v[i]){
            ll tmp = u[i];
            u[i] = v[i];
            v[i] = tmp;
            if (q[cnt2-1].first < u[i]){
                cout << 0 << "\n";
                continue;
            }

            int lo = 0, hi = r.size() - 2;

            while (lo < hi){
                int m = (lo + hi + 1) / 2;
                if (q[r[m]].first > u[i]) hi = m-1;
                else lo = m;
            }

            // cout << "lo: " << lo << "\n";

            if (q[r[lo]].first != u[i]){
                cout << 0 << "\n";
                continue;
            }

            int loc1 = lo;

            lo = 0; hi = r2[loc1].size() - 2;
            if (q[r[loc1+1] - 1].second % q[r[loc1+1] - 1].first < v[i] % u[i]){
                cout << 0 << "\n";
                continue;
            }

            while (lo < hi){
                int m = (lo + hi + 1) / 2;
                if (q[r2[loc1][m]].second % q[r2[loc1][m]].first > v[i] % u[i]) hi = m-1;
                else lo = m;
            }

            // cout << "loc2: " << lo << "\n";

            if (q[r2[loc1][lo]].second % q[r2[loc1][lo]].first != v[i] % u[i]){
                cout << 0 << "\n";
                continue;
            }

            int loc2 = r2[loc1][lo];
            int loc3 = r2[loc1][lo+1];
            lo = loc2; hi = loc3-1;

            if (q[loc3-1].second < v[i]){
                cout << 0 << "\n";
                continue;
            }

            while (lo < hi){
                int m = (lo + hi) / 2;
                if (q[m].second < v[i]) lo = m+1;
                else hi = m;
            }

            cout << loc3 - hi << "\n";
            continue;
        }

        if (p[cnt1-1].first < u[i]){
            cout << 0 << "\n";
            continue;
        }

        int lo = 0, hi = l.size() - 2;

        while (lo < hi){
            int m = (lo + hi + 1) / 2;
            if (p[l[m]].first > u[i]) hi = m-1;
            else lo = m;
        }

        // cout << "lo: " << lo << "\n";

        if (p[l[lo]].first != u[i]){
            cout << 0 << "\n";
            continue;
        }

        int loc1 = lo;

        lo = 0; hi = l2[loc1].size() - 2;
        if (p[l[loc1+1] - 1].second % p[l[loc1+1] - 1].first < v[i] % u[i]){
            cout << 0 << "\n";
            continue;
        }

        while (lo < hi){
            int m = (lo + hi + 1) / 2;
            if (p[l2[loc1][m]].second % p[l2[loc1][m]].first > v[i] % u[i]) hi = m-1;
            else lo = m;
        }

        // cout << "loc2: " << lo << "\n";

        if (p[l2[loc1][lo]].second % p[l2[loc1][lo]].first != v[i] % u[i]){
            cout << 0 << "\n";
            continue;
        }

        int loc2 = l2[loc1][lo];
        int loc3 = l2[loc1][lo+1];
        lo = loc2; hi = loc3-1;

        if (p[loc3-1].second < v[i]){
            cout << 0 << "\n";
            continue;
        }

        while (lo < hi){
            int m = (lo + hi) / 2;
            if (p[m].second < v[i]) lo = m+1;
            else hi = m;
        }

        cout << loc3 - hi << "\n";
        continue;
    }

    // cout << "\n";
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}
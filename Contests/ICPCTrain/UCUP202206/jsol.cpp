#include<bits/stdc++.h>

using namespace std;

struct lazySegTree{
    int s;
    vector<int> seg;
    vector<int> lazy;

    lazySegTree(int n){
        s = n;
        seg.resize(4*n);
        lazy.resize(4*n);
        for (int i = 1; i < 4*n; i++){
            seg[i] = 0;
            lazy[i] = 0;
        }
    }

    void dump(int nd, int st, int en){
        seg[nd] += lazy[nd];
        if (st == en){
            lazy[nd] = 0;
            return;
        }
        lazy[nd<<1] += lazy[nd];
        lazy[nd<<1^1] += lazy[nd];
        lazy[nd] = 0;
    }

    void upd(int p, int val){
        upd(1, 1, s, p, val);
    }

    void upd(int nd, int st, int en, int p, int val){
        if (st > p || en < p) return;
        dump(nd, st, en);
        if (st == en){
            seg[nd] += val;
            return;
        }
        int m = (st + en) / 2;
        upd(nd<<1, st, m, p, val);
        upd(nd<<1^1, m+1, en, p, val);
        seg[nd] = seg[nd<<1] + seg[nd<<1^1];
    }

    void update(int l, int r, int val){
        update(1, 1, s, l, r, val);
    }

    void update(int nd, int st, int en, int l, int r, int val){
        if (st > r || en < l) return;
        dump(nd, st, en);
        if (st >= l && en <= r){
            lazy[nd] += val;
            dump(nd, st, en);
            return;
        }
        int m = (st + en) / 2;
        update(nd<<1, st, m, l, r, val);
        update(nd<<1^1, m+1, en, l, r, val);
        seg[nd] = seg[nd<<1] + seg[nd<<1^1];
    }

    int query(int l, int r){
        if (l > r) return 0;
        return query(1, 1, s, l, r);
    }

    int query(int nd, int st, int en, int l, int r){
        if (st > r || en < l) return 0;
        dump(nd, st, en);
        if (st >= l && en <= r) return seg[nd];
        int m = (st + en) / 2;
        int q1 = query(nd<<1, st, m, l, r);
        int q2 = query(nd<<1^1, m+1, en, l, r);
        return q1 + q2;
    }
};

struct pref{
    vector<int> pr;
    pref(int n){
        pr.resize(n+1);
        for (int i = 0; i <= n; i++) pr[i] = 0;
        pr[0] = 0;
    }

    int query(int l, int r){
        if (l > r) return 0; 
        return pr[r] - pr[l-1];
    }
};

void solve(){
    int n, k, m, q;
    cin >> n >> k >> m >> q;
    pref way(n+m+1);
    lazySegTree avai(n+m+1);

    for (int i = 1; i <= n+m+1; i++) avai.upd(i, 1);

    vector<int> c(n+m+2);
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = n+1; i <= n+m+1; i++) cin >> c[i];
    for (int i = 1; i <= n+m+1; i++) way.pr[i] = way.pr[i-1] + c[i];

    for (int _ = 0; _ < q; _++){
        char C; cin >> C;

        if (C == 'c'){
            int i; cin >> i;
            int cur = avai.query(i, i);
            if (cur == 0) avai.upd(i, 1);
            else avai.upd(i, -1);
        }

        else if (C == 'x'){
            int j; cin >> j;
            int cur = avai.query(n + 1 + j, n + 1 + j);
            if (cur == 0) avai.upd(n+1+j, 1);
            else avai.upd(n+1+j, -1);
        }

        else{
            int u, v; 
            cin >> u >> v;

            if (u == v){
                cout << 0 << "\n";
                continue;
            }

            if (u > v){
                int tmp = u;
                u = v;
                v = tmp;
            }

            int ans = 1e9 + 5;

            if (u <= n && v <= n){
                if (avai.query(u, v-1) == v - u) ans = min(ans, way.query(u, v-1));
                int x1 = avai.query(v, n);
                int x2 = avai.query(n+1, n+1+m);
                int x3 = avai.query(1, u-1);
                if (x1 + x3 == n - v + 1 + u - 1) ans = min(ans, way.query(v, n) + way.query(1, u-1));
                if (u > k){
                    if (x1 + x2 + avai.query(k, u-1) == n - v + 1 + m + 1 + u - k) ans = min(ans, way.query(v, n) + way.query(n+1, n+1+m) + way.query(k, u-1));
                }
                else if (u == k){
                    if (x1 + x2 == n - v + 1 + m + 1) ans = min(ans, way.query(v, n) + way.query(n+1, n+1+m));
                }
                else if (v > k){
                    if (u > 1) if (avai.query(k, v-1) + x2 + x3 == v - k + m + 1 + u - 1) ans = min(ans, way.query(k, v-1) + way.query(n+1, n+1+m) + way.query(1, u-1));
                    if (x1 + x2 + avai.query(u, k-1) == n - v + 1 + m + 1 + k - u) ans = min(ans, way.query(v, n) + way.query(n+1, n+1+m) + way.query(u, k-1));
                }
                else if (v == k){
                    if (u > 1) if (x2 + x3 == m + 1 + u - 1) ans = min(ans, way.query(n+1, n+1+m) + way.query(1, u-1));
                }
                else{
                    if (avai.query(v, k-1) + x2 + x3 == k - v + m + 1 + u - 1) ans = min(ans, way.query(v, k-1) + way.query(n+1, n+1+m) + way.query(1, u-1));
                }
            }

            else if (u <= n){
                int x1 = avai.query(n+1, v);
                int x2 = avai.query(v+1, n+m+1);
                if (x1 + avai.query(1, u-1) == v - n + u - 1) ans = min(ans, way.query(n+1, v) + way.query(1, u-1));
                if (x1 + avai.query(u, n) == v - n + n - u + 1) ans = min(ans, way.query(n+1, v) + way.query(u, n));
                if (u < k){
                    if (x2 + avai.query(u, k-1) == n+m+1-v + k - u) ans = min(ans, way.query(v+1, n+m+1) + way.query(u, k-1));
                    if (x2 + avai.query(k, n) + avai.query(1, u-1) == n+m+1-v + n - k + 1 + u-1) ans = min(ans, way.query(v+1, n+m+1) + way.query(k, n) + way.query(1, u-1));
                }
                else if (u == k){
                    if (x2 == n+m+1-v) ans = min(ans, way.query(v+1, n+m+1));
                }
                else{
                    if (x2 + avai.query(k, u-1) == n+m+1-v + u-k) ans = min(ans, way.query(v+1, n+m+1) + way.query(k, u-1));
                    if (x2 + avai.query(u, n) + avai.query(1, k-1) == n+m+1-v + n - u + 1 + k-1) ans = min(ans, way.query(v+1, n+m+1) + way.query(u, n) + way.query(1, k-1));
                }
            }

            else{
                int x1 = avai.query(n+1, u) + avai.query(v+1, n+m+1);
                if (avai.query(u+1, v) == v - u) ans = min(ans, way.query(u+1, v));
                if (x1 + avai.query(1, k-1) == u - n + n+m+1-v + k-1) ans = min(ans, way.query(n+1, u) + way.query(v+1, n+m+1) + way.query(1, k-1));
                if (x1 + avai.query(k, n) == u - n + n+m+1-v + n-k+1) ans = min(ans, way.query(n+1, u) + way.query(v+1, n+m+1) + way.query(k, n));
            }

            if (ans == 1e9+5){
                cout << "impossible\n";
            }
            else{
                cout << ans << "\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    solve();
}
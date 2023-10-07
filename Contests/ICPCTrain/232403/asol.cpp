#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;

int n, q;
int m;

int seg[4*maxn], lazy[4*maxn];
int a[maxn], p[maxn];

void dump(int nd, int st, int en){
    if (lazy[nd] != -1) seg[nd] = lazy[nd] * (en - st + 1);
    if (st == en){
        lazy[nd] = -1;
        return;
    }
    lazy[nd*2] = lazy[nd];
    lazy[nd*2+1] = lazy[nd];
    lazy[nd] = -1;
    return;
}

void build(int nd, int st, int en){
    if (st == en){
        if (p[st] == m) seg[nd] = 1;
        if (p[st] > m) seg[nd] = 2;
        if (p[st] < m) seg[nd] = 0;
        return;
    }
    int mid = (st + en) / 2;
    build(nd*2, st, mid);
    build(nd*2+1, mid+1, en);
    seg[nd] = seg[nd*2] + seg[nd*2+1];
}

void update(int nd, int st, int en, int l, int r, int val){
    dump(nd, st, en);
    if (st > r || en < l) return;
    if (st >= l && en <= r){
        lazy[nd] = val;
        dump(nd, st, en);
        return;
    }
    int mid = (st + en) / 2;
    update(nd*2, st, mid, l, r, val);
    update(nd*2+1, mid+1, en, l, r, val);
    seg[nd] = seg[nd*2] + seg[nd*2+1];
}

int query(int nd, int st, int en, int l, int r){
    dump(nd, st, en);
    if (st > r || en < l) return 0;
    if (st >= l && en <= r) return seg[nd];
    int mid = (st + en) / 2;
    return query(nd*2, st, mid, l, r) + query(nd*2+1, mid+1, en, l, r);
}

void solve(){
    cin >> n >> q;
    m = (n + 1) / 2;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) p[a[i]] = i;
    build(1, 1, n);
    for (int i = 1; i <= 4*n; i++) lazy[i] = -1;

    // for (int i = 1; i <= n; i++) cout << query(1, 1, n, i, i) << " ";
    // cout << "\n";

    int cent = a[m];

    for (int _ = 0; _ < q; _++){
        int l, r; cin >> l >> r;
        if (l < r){
            int sz = r - l + 1;
            int u = query(1, 1, n, l, r);
            // cout << u << "\n";
            int ri = u / 2;
            int mi = u % 2;
            // cout << l << " " << l + sz - ri - mi - 1 << "\n";
            update(1, 1, n, l, l + sz - ri - mi - 1, 0);
            update(1, 1, n, r - ri + 1, r, 2);
            if (mi > 0){
                update(1, 1, n, r - ri, r - ri, 1);
                cent = r - ri;
            }
        }
        else{
            int sz = l - r + 1;
            int u = query(1, 1, n, r, l);
            // cout << u << "\n";
            int ri = u / 2;
            int mi = u % 2;
            // cout << l - sz + ri + mi + 1 << " " << l << "\n";
            update(1, 1, n, r, r + ri - 1, 2);
            update(1, 1, n, l - sz + ri + mi + 1, l, 0);
            if (mi > 0){
                update(1, 1, n, r + ri, r + ri, 1);
                cent = r + ri;
            }
        }

        // for (int i = 1; i <= 4*n; i++) cout << seg[i] << " ";
        // cout << "\n";
        // for (int i = 1; i <= 4*n; i++) cout << lazy[i] << " ";
        // cout << "\n";

        for (int i = 1; i <= n; i++){
            cout << query(1, 1, n, i, i) << " ";
        }
        cout << "\n";
    }

    cout << cent << "\n";
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    solve();
}
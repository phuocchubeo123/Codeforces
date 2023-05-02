#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 4;
int T, n, m, x[N], y[N], a[2 * N], done[N], p[N], last[N];

int seg_sz, seg[4 * N];

void buildSegTree(){
    seg_sz = 1;
    while (seg_sz < n) seg_sz = seg_sz * 2;
    for (int i = n; i < seg_sz; i++) a[i] = 0;
    for (int i = 0; i < seg_sz; i++) seg[seg_sz + i] = a[i];
    for (int i = seg_sz - 1; i > 0; i--) seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

void updateSegTree(int pos, ll val){
    int ps = seg_sz + pos;
    while (ps > 0){
        seg[ps] += val;
        ps = ps / 2;
    }
}

ll querySegTree(int l, int r){
    l = seg_sz + l;
    r = seg_sz + r;
    ll qr = 0;

    while (l <= r){
        if (l & 1) qr += seg[l++];
        if (!(r & 1)) qr += seg[r--];
        l = l / 2;
        r = r / 2;
    }
    return qr;
}

void prepare(){

}

void read(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> x[i] >> y[i];
        y[i]--;
    }
}

void solve(){
    for (int i = 0; i < n; i++) a[i] = 0;
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 0; i < n; i++) p[i] = 0;
    buildSegTree();

    for (int i = 0; i < m; i++){
        if (done[x[i]]) continue;
        // cout << i << " ";

        // cout << querySegTree(y[i], seg_sz - 1) << "\n";
        int l = 0, h = y[i];

        while (l < h){
            int m = l + (h - l + 1) / 2;
            if (m + querySegTree(m, seg_sz - 1) <= y[i]) l = m;
            else h = m - 1;
        }

        // cout << l << " " << l + querySegTree(l, seg_sz - 1) << "\n";

        if (l + querySegTree(l, seg_sz - 1) != y[i] || p[l] != 0){
            cout << -1;
            return;
        }

        p[l] = x[i];
        done[x[i]] = 1;
        updateSegTree(l, 1);
    }

    // for (int i = 0; i < n; i++) cout << p[i] << " ";
    
    for (int i = 1; i <= n; i++) last[i] = -1;
    for (int i = 0; i < m; i++) a[i] = 0;
    buildSegTree();

    for (int i = 0; i < m; i++){
        if (last[x[i]] == -1){
            updateSegTree(i, 1);
            last[x[i]] = i;
            continue;
        }

        int t = querySegTree(last[x[i]] + 1, i - 1);
        if (t != y[i]){
            cout << -1;
            return;
        }

        updateSegTree(last[x[i]], -1);
        updateSegTree(i, 1);
        last[x[i]] = i;
    }

    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 0; i < m; i++) done[x[i]] = 1;
    vector<int> notdone;
    for (int i = 1; i <= n; i++) if (!done[i]) notdone.push_back(i);

    int pt = 0;
    for (int i = 0; i < n; i++){
        if (p[i] == 0){
            p[i] = notdone[pt];
            pt++;
        }
    }

    for (int i = 0; i < n; i++) cout << p[i] << " ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}
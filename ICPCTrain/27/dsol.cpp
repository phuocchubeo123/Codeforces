#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 3e5 + 4;
int T;

struct segTree{
    vt<int> seg;
    int sz;

    segTree(vt<int> v, int n){
        sz = 1;
        while (sz < n) sz = sz * 2;
        seg = vt<int> (2 * sz);
        build(v, n);
    }

    void build(vt<int> v, int n){
        for (int i = 0; i < sz; i++){
            if (sz + i < n) seg[sz + i] = v[i];
            else seg[sz + i] = 0;
        }
        for (int i = sz - 1; i > 0; i--) seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }

    void update(int pos, ll val){
        int ps = sz + pos;
        while (ps > 0){
            seg[ps] += val;
            ps = ps / 2;
        }
    }

    ll query(int l, int r){
        if (r < l) return 0;

        l = sz + l;
        r = sz + r;
        ll qr = 0;

        while (l <= r){
            // cout << l << " " << r << "\n";
            if (l & 1) qr += seg[l++];
            if (!(r & 1)) qr += seg[r--];
            l = l / 2;
            r = r / 2;
        }
        return qr;
    }
};

void prepare(){

}

void solve(){
    int n; cin >> n;
    vt<int> a(n), b(n);
    for0(i, n) cin >> a[i];
    for0(i, n) cin >> b[i];
    vt<int> id;
    for0(i, n) id.pb(i);
    sort(id.begin(), id.end(), [&](int x, int y){
        return a[x] > a[y] || (a[x] == a[y] && x < y);
    });

    vt<vt<int>> lb(n + 1);
    for0(i, n) lb[b[i]].pb(i);
    vt<int> lbc(n + 1, 0), bef(n), aft(n);
    for (int i: id){
        if (lbc[a[i]] >= lb[a[i]].size()){
            cout << "NO\n";
            return;
        }

        aft[i] = lb[a[i]][lbc[a[i]]];
        lbc[a[i]]++;
    } 

    vt<int> inc(n, 0), alr(n, 0);
    segTree seg_inc(inc, n), seg_alr(alr, n);

    // for0(i, n){
    //     cout << id[i] << " ";
    //     cout << aft[id[i]] << "\n";
    // }

    for0(i, n){
        int curr = id[i];
        int new_pos = curr - seg_inc.query(0, curr);
        int l = curr, r = n - 1;
        while (l < r){
            int m = l + (r - l + 1) / 2;
            // cout << m << "\n";
            if (seg_alr.query(curr, m - 1) > 0) r = m - 1;
            else{
                if (m - curr - seg_inc.query(curr, m) > aft[curr] - new_pos) r = m - 1;
                else l = m;
            } 
        }

        // cout << curr << " " << new_pos << " " << l << "\n";

        if (seg_alr.query(curr, l - 1) > 0){
            // cout << "alr NO\n";
            cout << "NO\n";
            return;
        }

        if (l - curr - seg_inc.query(curr, l) < aft[curr] - new_pos){
            // cout << "inc NO\n";
            cout << "NO\n";
            return;
        }

        seg_inc.update(curr + 1, 1);
        if (l < n - 1) seg_inc.update(l + 1, -1);
        seg_alr.update(l, 1);
    }
    cout << "YES\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        solve();
    }
}
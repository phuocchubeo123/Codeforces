#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 1e9;
int T;

void prepare(){

}

template<typename T>
struct segTree{
    vt<T> seg;
    int sz = 1;

    segTree(int n){
        while (sz < n) sz *= 2;
        seg.resize(2 * sz);
    }

    segTree(vt<T> v, int n){
        while (sz < n) sz *= 2;
        seg.resize(2 * sz);
        for0(i, n) update(i, v[i]);
    }

    void update(int pos, T x){
        int ps = sz + pos;
        seg[ps] = x;
        ps /= 2;
        while (ps > 0){
            seg[ps] = seg[ps * 2] + seg[ps * 2 + 1];
            ps /= 2;
        }
    }

    T query(int l, int r){
        if (r < l) return 0;

        l += sz;
        r += sz;
        T qr;

       while (l <= r){
            if (l & 1) qr += seg[l++];
            if (!(r & 1)) qr += seg[r--];
            l /= 2;
            r /= 2;
        }
        return qr;
    }
};

struct node{
    int val;

    node(){
        val = N;
    }

    node(int x){
        val = x;
    }

    node operator+(const node& other){
        return node(min(val, other.val));
    }

    void operator+=(const node& other){
        val = min(val, other.val);
    }
};

struct maxnode{
    int val;

    maxnode(){
        val = 0;
    }

    maxnode(int x){
        val = x;
    }

    maxnode operator+(const maxnode& other){
        return maxnode(max(val, other.val));
    }

    void operator+=(const maxnode& other){
        val = max(val, other.val);
    }
};

void solve(){
    int n, k;
    cin >> n >> k;
    vt<int> a(n);
    vt<pair<int, int>> b(n);
    for0(i, n) cin >> a[i];

    if (n == 2){
        if (k == 1) cout << max(a[0], a[1]) << "\n";
        else cout << 1000000000 << "\n";
        return;
    }

    if (k == n){
        cout << 1000000000 << "\n";
        return;
    }

    for0(i, n) b[i] = {a[i], i};
    sort(b.begin(), b.end());
    for0(i, k-1){
        auto curr = b[i];
        int pos = curr.second;
        a[pos] = 1e9;
    }

    segTree<node> st(n);
    for0(i, n) st.update(i, node(a[i]));
    segTree<maxnode> adj(n-1);
    for0(i, n-1) adj.update(i, maxnode(st.query(i, i+1).val));

    int ans = 0;
    
    for0(i, n){
        node ori = st.query(i, i);
        st.update(i, node());
        int mn = st.query(0, n-1).val;
        if (i < n-1){
            adj.update(i, maxnode(st.query(i, i+1).val));
        }
        if (i > 0){
            adj.update(i-1, maxnode(st.query(i-1, i).val));
        }
        int mx = adj.query(0, n-2).val;
        ans = max(ans, min(mx, 2 * mn));

        st.update(i, ori);
        if (i < n-1){
            adj.update(i, maxnode(st.query(i, i+1).val));
        }
        if (i > 0){
            adj.update(i-1, maxnode(st.query(i-1, i).val));
        }
    }

    cout << ans << "\n";
    return;
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
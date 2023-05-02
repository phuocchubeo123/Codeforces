#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T;

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

int gcd(int x, int y){
    if (x == 0 && y == 0) return 0;
    if (x == 0) return y;
    if (y == 0) return x;
    if (x > y) return gcd(y, x);
    if (y % x == 0) return x;
    return gcd(x, y % x);
}

struct node{
    int val;
    node(){
        val = 0;
    }

    node(int x){
        val = x;
    }

    node operator+(const node& other){
        return node(gcd(val, other.val));
    }

    void operator+=(const node& other){
        val = gcd(val, other.val);
    }
};

void prepare(){

}

void solve(){
    int n;
    cin >> n;
    vt<int> a(n);
    for0(i, n) cin >> a[i];

    segTree<node> st(n);
    for0(i, n) st.update(i, node(a[i]));

    int ans = 0;
    for0(i, n){
        int r = i, l = 0;
        while (l < r){
            int m = l + (r - l) / 2;
            if (st.query(m, i).val < i - m + 1) l = m + 1;
            else r = m;
        }

        if (st.query(l, i).val == i - l + 1){
            st.update(i, node(1));
            ans++;
        }

        cout << ans << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cin >> T;
    T = 1;

    while (T--){
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 1e5;
int n;
ll a[2 * N];

//segTree template
int seg_sz, seg[4 * N];

template<typename T>
struct segTree{
    vt<T> seg;
    vt<T> lazy;
    int sz = 1;

    segTree(int n, bool lz){
        while (sz < n) sz *= 2;
        seg.resize(2 * sz);
        if (lz) lazy.resize(2 * sz);
    }

    segTree(vt<T> v, int n, bool lazy){
        while (sz < n) sz *= 2;
        seg.resize(2 * sz);
        for0(i, n) update(i, v[i]);
        if (lz) lazy.resize(2 * sz);
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
    
    void lazy_update(int pos, T x){

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

int main(){
    n = 4;
    vector<int> a(4);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;

    segTree<int> sega(a, 4);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define vt vector

const int N = 1e5;
int n;
ll a[2 * N];

//segTree template
int seg_sz, seg[4 * N];

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

int main(){
    n = 4;
    vector<int> a(4);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;

    segTree sega(a, 4);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5;
int n;
ll a[2 * N];

//segTree template
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
        // cout << l << " " << r << "\n";
        if (l & 1) qr += seg[l++];
        if (!(r & 1)) qr += seg[r--];
        l = l / 2;
        r = r / 2;
    }
    return qr;
}


int main(){
    n = 4;
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    buildSegTree();
    updateSegTree(0, 2);
    updateSegTree(1, 2);
    cout << querySegTree(1, 3);
    return 0;
}
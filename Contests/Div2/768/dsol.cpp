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

void prepare(){

}

vt<int> pre_cnt(N);

int sumRange(int x, int y){
    if (x == 0) return pre_cnt[y];
    return pre_cnt[y] - pre_cnt[x - 1];
}

void solve(){
    int n, k; 
    cin >> n >> k;
    vt<int> a(n);
    for0(i, n) cin >> a[i];
    vt<int> cnt(n + 1);
    for0(i, n) cnt[a[i]]++;
    int tot = 0;
    for0(i, n + 1){
        tot += cnt[i];
        pre_cnt[i] = tot;
    }

    int ans = 1e9;
    int ansx = 0, ansy = 0;
    for0(x, n + 1){
        int l = x, r = n;
        while (l < r){
            int m = l + (r - l) / 2;
            if ((2 * sumRange(x, m) - tot) >= k) r = m; 
            else l = m + 1;
        }

        if ((2 * sumRange(x, l) - tot) < k) continue;

        if (l - x <= ans){
            ansx = x;
            ansy = l;
            ans = l - x;
        }
    }

    cout << ansx << " " << ansy << "\n";
    int change = 0;
    int curr = 0;
    int num = 0;
    for0(i, n){
        if (a[i] <= ansy && a[i] >= ansx) change++;
        else change--;

        if (change == 1 && num < k - 1){
            cout << curr + 1 << " " << i + 1 << "\n";
            curr = i + 1;
            change = 0;
            num++;
        }
    }

    cout << curr + 1 << " " << n << "\n";


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
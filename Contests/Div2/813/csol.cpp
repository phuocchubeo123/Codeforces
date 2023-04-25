#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 1e5 + 4;
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

void prepare(){

}

vt<int> indices[N];

void solve(){
    int n;
    cin >> n;
    segTree<node> seg(n);
    vt<int> a(n+1);
    for0(i, n){
        int x;
        cin >> x;
        seg.update(i, node(x));
        indices[x].pb(i);
        a[i] = x;
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int ans = 0;

    for0(i, n){
        if (i != 0 && a[i] == a[i-1]) continue;

        int first = indices[a[i]][0];
        if (first == n-1) continue;
        // cout << a[i] << " " << first << " " << seg.query(first+1, n-1).val << " ";
        if (seg.query(first+1, n-1).val < a[i]){
            // cout << a[i] << "\n";
            ans++;
            for (int indx: indices[a[i]]){
                seg.update(indx, node(0));
            }
        }
    }

    for0(i, n){
        indices[a[i]].clear();
    }

    cout << ans << "\n";
    // cout << "\n";
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
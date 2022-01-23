#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
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

struct node{
    int val;
    node(){
        val = 0;
    }

    node(int x){
        val = x;
    }

    node operator+(const node& other){
        return node(max(val, other.val));
    }

    void operator+=(const node& other){
        val = max(val, other.val);
    }
};

void solve(){
    int n; cin >> n;    
    vector<int> x(n);
    for0(i, n) cin >> x[i]; 
    vector<int> y(n);
    for0(i, n) y[i] = x[i];
    sort(y.begin(), y.end());
    map<int, int> d;
    for0(i, n) d[y[i]] = i;

    segTree<node> st(n);
    for0(i, n){
        int curr = st.query(0, d[x[i]] - 1).val;
        st.update(d[x[i]], node(curr + 1));
    }

    cout << st.query(0, n - 1).val;
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
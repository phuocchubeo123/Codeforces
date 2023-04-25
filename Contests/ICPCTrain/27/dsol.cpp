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
    int val = (int) 1e9;

    node(){

    }

    node(int x){
        val = x;
    }

    node operator+(node& other){
        return node(min(val, other.val));
    }

    inline void operator+=(node& other){
        val = min(val, other.val);
    }
};

void prepare(){

}

string solve(){
    int n; 
    cin >> n;
    vt<int> a(n), b(n);
    for0(i, n) cin >> a[i];
    for0(i, n) cin >> b[i];

    vt<stack<int>> lb(n + 1);
    for (int i = n - 1; i >= 0; i--) lb[a[i]].push(i);

    segTree<node> st(n + 1);
    for1(i, n){
        if (!lb[i].empty()){
            st.update(i, node(lb[i].top()));
        }

        else{
            st.update(i, node());
        }
    }

    // for1(i, n) cout << st.query(i, i).val << " ";
    // cout << "\n";

    for0(i, n){
        // for1(i, n) cout << st.query(i, i).val << " ";
        // cout << "\n";

        if (lb[b[i]].empty()) return "NO\n";

        int curr = lb[b[i]].top(); lb[b[i]].pop();
        if (st.query(1, b[i]).val < curr) return "NO\n";
        
        if (lb[b[i]].empty()) st.update(b[i], node());
        else st.update(b[i], node(lb[b[i]].top()));

    }

    return "YES\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        cout << solve();
    }
}
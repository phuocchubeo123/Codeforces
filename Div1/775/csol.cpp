#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4, MOD = 998244353;
int T;

struct mint{
    int val;

    mint(){
        val = 0;
    }

    mint(int x){
        while (x >= MOD) x -= MOD;
        while (x < 0) x += MOD;
        val = x;
    }

    bool operator==(const mint& other){
        return val == other.val;
    }

    mint operator+(const mint& other){
        return mint(val + other.val);
    }

    mint operator-(const mint& other){
        return mint(val - other.val);
    }

    mint operator*(const mint& other){
        return mint((val * 1ll * other.val) % MOD);
    }

    mint pow(int y){
        mint z(1);
        mint x(val);
        while (y > 0){
            if (y % 2 == 1) z = z * x;
            x = x * x;
            y /= 2;
        }
        return z;
    }

    mint operator/(const mint& other){
        return mint(val) * mint(other.val).pow(MOD - 2);
    }

    void operator+=(const mint& other){
        val = (val + other.val) % MOD;
    }
};

mint factor_mod[N];

void calFactor(){
    factor_mod[0] = mint(1);
    for (int i = 1; i < N; i++) factor_mod[i] = factor_mod[i - 1] * mint(i);
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

void prepare(){
    calFactor();
}

void solve(){
    int n, m;
    cin >> n >> m;
    vt<int> s(n), t(m);
    for0(i, n) cin >> s[i];
    for0(i, m) cin >> t[i];
    vt<int> cnt(N);
    for0(i, n) cnt[s[i]]++;
    set<int> st;
    for0(i, n) st.insert(s[i]);

    mint nume = 1, denom = 1;
    nume = factor_mod[n - 1];
    for (int x: st) denom = denom * factor_mod[cnt[x]];

    segTree<mint> seg(N);
    for0(i, N) seg.update(i, mint(0));
    for (int x: st) seg.update(x, mint(cnt[x]));
    mint ans(0);
    mint curr = nume / denom;
    int summ = n - 1;

    for0(i, n){
        if (i >= m){
            cout << ans.val << "\n";
            return;
        }

        auto it = st.lower_bound(t[i]);
        // cout << ans.val << " " << *it << "\n";
        if (it == st.begin()){
            // cout << "yes\n";
            int x = *it;
            if (x > t[i]){
                // cout << ans.val << "\n";
                return;
            }

            curr = curr / factor_mod[summ];
            curr = curr * mint(cnt[x]);
            cnt[x]--;
            summ = summ - 1;
            if (summ >= 0) curr = curr * factor_mod[summ];
            seg.update(x, mint(cnt[x]));
            if (cnt[x] == 0) st.erase(x);
            if (i == n - 1 && n < m) ans = ans + mint(1);
            continue;
        }

        int x = *it;
        ans = ans + curr * seg.query(0, x - 1);
        // cout << x << " " << seg.query(0, x - 1).val << " qr\n";
        if (x > t[i]){
            // cout << ans.val << "\n";
            return;
        }

        curr = curr / factor_mod[summ];
        curr = curr * mint(cnt[x]);
        cnt[x]--;
        summ = summ - 1;
        if (summ >= 0) curr = curr * factor_mod[summ];
        seg.update(x, cnt[x]);
        if (cnt[x] == 0) st.erase(x);
    }

    cout << ans.val << "\n";
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
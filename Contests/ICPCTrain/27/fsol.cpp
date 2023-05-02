#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4, MOD = 1e9 + 7;
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
        val += other.val;
        while (val >= MOD) val -= MOD;
        while (val < 0) val += MOD;
    }

    void operator-=(const mint& other){
        val -= other.val;
        while (val >= MOD) val -= MOD;
        while (val < 0) val += MOD;
    }

    void operator/=(const mint& other){
        val = (mint(val) / mint(other.val)).val;
    }
};

void prepare(){

}

vt<int> l, r;

mint adj_prob(int id){
    if (l[id + 1] > r[id] || l[id] > r[id + 1]) return mint(0);

    int le = max(l[id], l[id + 1]), ri = min(r[id], r[id + 1]);
    return (mint(ri - le + 1) / mint(r[id] - l[id] + 1)) / mint(r[id + 1] - l[id + 1] + 1);
}

mint three_adj_prob(int id){
    if (l[id + 1] > r[id] || l[id] > r[id + 1]) return mint(0);
    int le = max(l[id], l[id + 1]), ri = min(r[id], r[id + 1]);
    if (le > r[id + 2] || ri < l[id + 2]) return mint(0);
    le = max(le, l[id + 2]); ri = min(ri, r[id + 2]);
    mint res(ri - le + 1);
    for0(i, 3) res /= mint(r[id + i] - l[id + i] + 1);
    return res;
}

void solve(){
    int n;
    cin >> n;
    l.resize(n); r.resize(n);
    for0(i, n) cin >> l[i];
    for0(i, n) cin >> r[i];

    mint ans = mint(n).pow(2);
    mint sum_prob(0);
    for0(i, n - 1) sum_prob += adj_prob(i);
    ans -= (mint(2 * n - 1) * sum_prob);
    ans += sum_prob.pow(2);
    for0(i, n - 2) ans -= mint(2) * (adj_prob(i) * adj_prob(i + 1));
    for0(i, n - 2) ans += mint(2) * three_adj_prob(i);
    for0(i, n - 1) ans -= adj_prob(i).pow(2);
    // cout << (mint(1) / mint(6)).val << "\n";
    // cout << (adj_prob(0) * adj_prob(1)).val << "\n";
    // cout << three_adj_prob(0).val << "\n";
    cout << ans.val;
    return;

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
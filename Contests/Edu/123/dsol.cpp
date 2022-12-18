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
};

void prepare(){

}

void solve(){
    int n, m, k, q;
    cin >> n >> m >> k >> q; 
    map<int, int> lr, lc;
    set<int> sr, sc;
    for0(i, q){
        int x, y;
        cin >> x >> y;
        sr.insert(x);
        sc.insert(y);
        lr[x] = i;
        lc[y] = i;
    }

    int mlr = 1e9, mlc = 1e9;
    for (int i: sr) mlr = min(mlr, lr[i]);
    for (int i: sc) mlc = min(mlc, lc[i]);
    
    if (sr.size() < n) mlr = -1;
    if (sc.size() < m) mlc = -1;

    // for1(i, n) cout << lr[i] << " ";
    // cout << "\n";
    // for1(i, m) cout << lc[i] << " ";
    // cout << "\n";

    vt<int> last(q + 1, 0);
    for (int i: sr) if (lr[i] >= mlc && lr[i] != -1) last[lr[i]] = 1;
    for (int i: sc) if (lc[i] >= mlr && lc[i] != -1) last[lc[i]] = 1;

    mint ans = mint(k);
    int x = 0;
    for0(i, q + 1) if (last[i] == 1) x += 1;
    cout << ans.pow(x).val << "\n";
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
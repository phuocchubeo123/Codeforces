#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4, MOD = 998244353;
int T, n, k, pre_sum[N];
string s;

struct Mint{
    int val;

    Mint(){
        val = 0;
    };

    Mint(int x){
        while (x >= MOD) x -= MOD;
        while (x < 0) x += MOD;
        val = x;
    };

    bool operator==(const Mint& other){
        return val == other.val;
    }

    Mint operator+(const Mint& other){
        return Mint(val + other.val);
    }

    Mint operator-(const Mint& other){
        return Mint(val - other.val);
    }

    Mint operator*(const Mint& other){
        return Mint((val * 1ll * other.val) % (1ll * MOD));
    }

    Mint pow(int y){
        Mint x(val);
        Mint z(1);
        while (y > 0){
            if (y % 2 == 1) z = z * x;
            x = x * x;
            y /= 2;
        }

        return z;
    }

    Mint operator/(const Mint& other){
        return Mint(val) * Mint(other.val).pow(MOD - 2);
    }
};

void read(){
    cin >> n >> k;
    cin >> s;
}

Mint factor[N];

void calFactor(){
    factor[0] = Mint(1);
    for (int i = 1; i < N; i++){
        factor[i] = factor[i - 1] * Mint(i);
    }
}

Mint xCy(int x, int y){
    return factor[x] / (factor[x - y] * factor[y]);
}

int segSum(int x, int y){
    if (x == 0) return pre_sum[y];
    return pre_sum[y] - pre_sum[x - 1];
}

Mint numPer(int x, int y){
    // cout << y - x + 1 << " " << segSum(y, x) << "\n";
    return xCy(x - y + 1, segSum(y, x));
}

void solve(){
    int tot = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '1') tot++;
        pre_sum[i] = tot;
    }

    Mint ans(0);

    vector<pair<int, int>> segs;

    for (int l = 0; l < n; l++){
        for (int r = l; r < n; r++){
            if (segSum(l, r) != k) continue;
            if (l == 0 && l == n - 1){
                // cout << l << " " << r << "\n";
                segs.push_back({l, r});
                // ans = ans + xCy(r - l + 1, k);
                continue;
            }

            if (l == 0){
                if (segSum(l, r + 1) != k){
                    // cout << l << " " << r << "\n";
                    segs.push_back({l, r});
                    // ans = ans + xCy(r - l + 1, k);
                }
                continue;
            }

            if (r == n - 1){
                if (segSum(l - 1, r) != k){
                    // ans = ans + xCy(r - l + 1, k);
                    segs.push_back({l, r});
                    // cout << l << " " << r << "\n";
                }
                continue;
            }

            if (segSum(l - 1, r) == k) continue;

            if (segSum(l, r + 1) == k) continue;

            segs.push_back({l, r});
            // cout << l << " " << r << "\n";
            // ans = ans + xCy(r - l + 1, k);
        }
    }

    if (segs.size() == 0){
        cout << 1 << "\n";
        return;
    }
    ans = Mint(1);

    ans = ans + numPer(segs[0].second, segs[0].first) - Mint(1);

    for (int i = 1; i < segs.size(); i++){
        // cout << segs[i].first << " " << segs[i].second << "\n";
        // cout << numPer(segs[i].second, segs[i].first).val << "\n";
        ans = ans + numPer(segs[i].second, segs[i].first) - Mint(1);
        if (segs[i].first <= segs[i - 1].second){
            ans = ans - numPer(segs[i - 1].second, segs[i].first);
            ans = ans + Mint(1);
        }

        else{
            continue;
        }
    }

    cout << ans.val << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> T;
    T = 1;
    calFactor();

    // cout << xCy(4, 2).val << "\n";

    while (T--){
        read();
        solve();
    }
}
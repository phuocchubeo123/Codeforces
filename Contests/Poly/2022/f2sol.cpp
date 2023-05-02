#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T a, T b){while(b){b^=a^=b^=a%=b;} return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 8e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

struct mint{
    ll val;
    mint(){
        val = 0;
    }
    mint(ll x){
        val = 1ll * x;
        if (val < 0) val = MOD - (-val) % MOD;
        if (val >= MOD) val %= MOD;
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
    void operator+=(const mint& other){
        val = (mint(val) + other).val;
    }
    mint pow(int y){
        if (y == 0) return mint(1);
        if (y == 1) return mint(val);
        mint x = mint(val).pow(y/2);
        if (y % 2 == 0) return x * x;
        else return x * x * mint(val);
    }
    mint operator/(const mint& other){
        return mint(val) * mint(other.val).pow(MOD - 2);
    }

    friend ostream& operator<<(ostream& os, const mint& x);
};

ostream& operator<<(ostream& cout, const mint& x){
    cout << x.val;
    return cout;
}

ll pow_mod[maxn];
void calPowMod(){
    pow_mod[0] = 1;
    for (int i = 1; i < maxn; i++) pow_mod[i] = (pow_mod[i - 1] * 2) % MOD;
}

void solve(){
    // The idea is, given a pig spawned originally at operation t, we can compute how much of it was replicated,
    // and also how much of it would be killed, using binary search

    // we first divide the times into intervals t_1, t_2, ..., t_m
    // let d_i be the total damage up to t_i (no replication involved)
    // if a pig was spawned at time t_i < t < t_{i+1}
    // then it would take d damages
    // the first replication of it would take d - d_i damages
    // second replication: d - d_i - d_{i+1}
    // 3rd: d - d_i - d_{i+1} - d_i
    // 4th: d - d_i - d_{i+1} - d_i - d_{i+2}
    // 5th: d - d_i - d_{i+1} - d_i - d_{i+2} - d_i
    // we noticed a pattern:
    // 0
    // 0 1 0
    // 0 1 0 2 0 1 0
    // 0 1 0 2 0 1 0 3 0 1 0 2 0 1 0 

    // how should we calculate this damage fast, to use binary search?
    // if we calculate this in logn, then maybe the time complexity is n logn logn, which, given n = 8e5, should be around 3 seconds, not fast enough
    // so we need to calculate it in O(1)
    // can we do both binary search and calculation at the same time? can
    // another thing is, the numbers could be hugh, how should we begin the binary search?
    // we could search from end to beginning. We already known that the last spawn of this pig would take D damages (just the sum of all damages until last)
    // doubling jump binary search 1 -> 2 -> 4 -> 5 -> 6 -> 7

    int n; cin >> n;
    vector<pii> spawn;
    vi replicate;
    vector<ll> d, cd;
    ll damage = 0;
    ll cumulative_damage = 0;
    forn(i, n){
        int q; cin >> q;
        if (q == 1){
            int x; cin >> x;
            spawn.push_back({i, x});
        }
        if (q == 2){
            int x; cin >> x;
            damage += x;
            cumulative_damage += x;
        }
        if (q == 3){
            replicate.push_back(i);
            cumulative_damage *= 2;
            if (cumulative_damage > 1e9) cumulative_damage = 1e9+1;
        }
        d.push_back(damage);
        cd.push_back(cumulative_damage);
    }

    // forn(i, n) cout << cd[i] << " ";
    // cout << "\n";

    vi next_rep(n, n);

    if (replicate.size() == 0){
        ll ans = 0;
        for (pii p: spawn){
            int i = p.first; ll x = p.second;
            if (x > damage - d[i]) ans = (ans + 1) % MOD;
        }
        cout << ans % MOD;
        return;
    }

    forn(i, replicate[0]+1) next_rep[i] = 0;
    forn(i, replicate.size()-1){
        rep(j, replicate[i]+1, replicate[i+1]) next_rep[j] = i+1;
    }

    int pt = 0;
    vi next_drep(n);
    forn(i, n){
        if (next_rep[i] == n) next_drep[i] = n;
        while (pt < replicate.size() && d[replicate[pt]] - d[i] == 0){
            pt++;
        }
        if (pt == replicate.size()) next_drep[i] = n;
        else next_drep[i] = pt;
    }

    // forn(i, n) cout << next_drep[i] << " ";
    // cout << "\n";

    // we need to find the first replication that induces damage

    ll ans = 0;

    for (pii p: spawn){
        int i = p.first;
        int j = next_rep[i];

        if (cd[i] == 0 && d[n-1] - d[i] == 0){
            // cout << "one\n";
            if (j == n) ans = (ans + 1) % MOD;
            else ans = (ans + pow_mod[replicate.size() - j]) % MOD; 
            continue;
        }

        ll x = p.second;
        ll curr = damage - d[i];
        ll c_damage = 0;
        // cout << i << " " << curr << "\n";
        if (curr >= x) continue;

        int L = next_rep[i];
        if (cd[i] == 0) L = next_drep[i];
        // cout << i << " " << L << "\n";
        ans = (ans + pow_mod[L - next_rep[i]]) % MOD;
        // cout << pow_mod[L - next_rep[i]] << "\n";
        ll add_damage = 0;

        ll l = 0, r = 0;
        bool flag = false;
        int jump;
        // cout << i << "\n";
        for (int k = 0; k + L < replicate.size(); k++){
            // cout << r << " " << c_damage << " " << add_damage << "\n";
            c_damage = c_damage * 2 + cd[i];
            add_damage = add_damage * 2 + d[replicate[L+k]] - d[i];
            r = r * 2 + 1;
            if (curr + c_damage + add_damage >= x){
                jump = k;
                flag = true;
                break;
            }
        }

        // cout << i << " " << r << "\n";
        // cout << r << "\n";

        if (!flag){ ans = (ans + (((r % MOD) * pow_mod[L - next_rep[i]])) % MOD) % MOD ; continue;}

        ll new_c_damage, new_add_damage;
        for (int k = jump; k >= 0; k--){
            // cout << l << " " << r << " " << c_damage << " " << add_damage << "\n";
            new_c_damage = (c_damage - cd[i]) / 2;
            new_add_damage = (add_damage - d[replicate[L+k]] + d[i]) / 2;
            // cout << new_c_damage << " " << new_add_damage << " ";
            // cout << curr << " " << cd[i] << " " << d[replicate[j+k]] - d[i] << " ";
            if (curr + new_c_damage + new_add_damage + cd[i] + d[replicate[L+k]] - d[i] < x){
                // cout << "one\n";
                curr = curr + new_c_damage + new_add_damage + cd[i] + d[replicate[L+k]] - d[i];
                l = (l + r + 1) / 2;
            }
            else{
                // cout << "two\n";
                r = (l + r - 1) / 2;
            }
            c_damage = new_c_damage;
            add_damage = new_add_damage;
        }

        // cout << i << " " << l << "\n";
        l = l % MOD;
        ans = (ans + (l * pow_mod[L - next_rep[i]]) % MOD) % MOD;
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    calPowMod();
    while(T--){
        solve();
    }
}
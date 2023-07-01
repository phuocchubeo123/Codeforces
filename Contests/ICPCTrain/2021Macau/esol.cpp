#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <complex>
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
#define M_PI 3.14159265358979323846
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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';

void fft(vector<complex<double>>& x, bool inverse = false) {
    const int n = x.size();
    if (n <= 1) return;

    vector<complex<double>> even(n / 2), odd(n / 2);
    for (int i = 0; 2 * i < n; ++i) {
        even[i] = x[2 * i];
        odd[i] = x[2 * i + 1];
    }

    fft(even, inverse);
    fft(odd, inverse);

    double theta = 2 * M_PI / n * (inverse ? -1 : 1);
    complex<double> w(1), wn(cos(theta), sin(theta));

    for (int i = 0; 2 * i < n; ++i) {
        x[i] = even[i] + w * odd[i];
        x[i + n / 2] = even[i] - w * odd[i];
        if (inverse) {
            x[i] /= 2;
            x[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

vector<ll> multiplyHankelMatrix(const vector<ll>& firstColumn) {
    const int n = firstColumn.size();
    vector<complex<double>> transformedFirstColumn(n), transformedFirstRow(n);
    transformedFirstRow[0] = transformedFirstColumn[0] = firstColumn[0];
    for (int i = 1; i < n; ++i) {
        transformedFirstColumn[i] = firstColumn[i];
        transformedFirstRow[i] = firstColumn[n - i];
    }
    fft(transformedFirstColumn);
    fft(transformedFirstRow);
    vector<complex<double>> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = transformedFirstColumn[i] * transformedFirstRow[i];
    }
    fft(result, true);
    vector<ll> finalResult(n);
    for (int i = 0; i < n; ++i) {
        finalResult[i] = static_cast<ll>(round(result[i].real()));
    }
    return finalResult;
}

int n, q;
vi p;
vector<bool> visisted;

void dfs(int s,  vector<ll>& cycle) {
    visisted[s] = true;
    cycle.push_back(s);

    int nxt = p[s];
    if (!visisted[nxt]) {
        dfs(nxt, cycle);
    }
}

vector<vector<ll>> breakCycle() {
    visisted = vector<bool>(n+1, false);
    vector<vector<ll>> cycles;
    for (int i = 1; i <= n; i++) {
        if (!visisted[i]) {
            vector<ll> cycle;
            dfs(i, cycle);
            cycles.push_back(cycle);
        }
    }
    return cycles;
}

void solve(){
    cin >> n >> q;
    p = vi(n+1, 0);
    vector<ll> ans(n+1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        p[x] = i;
    }
    vector<vector<ll>> cycles = breakCycle();
    vector<vector<ll>> cycles_ans;
    map<int, vector<ll>> ans_len;
    for (vector<ll> v : cycles) {
        vector<ll> cur = multiplyHankelMatrix(v);
        cycles_ans.push_back(cur);
        int s = cur.size();
        if (ans_len[s].size() == 0) {
            ans_len[s] = cur;
        } else {
            vector<ll> tmp = ans_len[s];
            for (int i = 0; i < s; i++) {
                tmp[i] += cur[i];
            }
            ans_len[s] = tmp;
        }
    }

    forn(i, n) {
        for (auto p : ans_len) {
            auto l = p.first;
            auto v = p.second;
            ans[i] += v[i%l];
        }
    }

    while(q--) {
        ll x; cin >> x;
        cout << ans[x%n] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}
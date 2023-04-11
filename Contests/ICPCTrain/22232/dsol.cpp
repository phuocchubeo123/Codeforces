#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef complex<double> cd;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))
 
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;
 
void solve(){
    int n, k; cin >> n >> k;
    vector<ll> x(n), y(n);
    forn(i, n){
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x[i] = x1+x2;
        y[i] = y1+y2;
    }
    
    vector<pair<ll, int>> xs, ys;
    forn(i, n){
        xs.push_back({x[i], i});
        ys.push_back({y[i], i});
    }
    sort(all(xs)); sort(all(ys));
    vi alr(n, 0);
 
    int i, cnt;
 
    int L=0, R=n-1, U=n-1, D=0;
    ll a, b, c, d;
    ll ans = 1e18 * 4;
    forn(l, k+1){
        // cout << "l: " << l << "\n";
        i = 0; cnt = 0;
        while (cnt < l){
            pair<ll, int> curr = xs[i];
            // cout << curr.first << "\n";
            i++; L++;
            if (i >= n) break;
            alr[curr.second]++;
            if (alr[curr.second]>1) continue;
            cnt++;
        }
 
        forn(u, k-l+1){
            // cout << "u: " << u << "\n";
            i = 0; cnt = 0;
            while (cnt < u){
                pair<ll, int> curr = ys[n-i-1];
                i++; U--;
                alr[curr.second]++; 
                if (alr[curr.second]>1) continue;
                cnt++;
            }
 
            forn(r, k-l-u+1){
                // cout << "r: " << r << "\n";
                i = 0; cnt = 0;
                while (cnt < r){
                    pair<ll, int> curr = xs[n-i-1];
                    i++; R--;
                    alr[curr.second]++;
                    if (alr[curr.second]>1) continue;
                    cnt++;
                }
 
                int d = k-l-u-r;
                // cout << "d: " << d << "\n";
                i = 0; cnt = 0;
                while (cnt < d){
                    pair<ll, int> curr = ys[i];
                    i++; D++;
                    alr[curr.second]++;
                    if (alr[curr.second]>1) continue;
                    cnt++;
                }
 
                rep(j, L, n-1) if (alr[xs[j].second] == 0){ a = xs[j].first; break;}
                per(j, U, 0) if (alr[ys[j].second] == 0){ b = ys[j].first; break;}
                per(j, R, 0) if (alr[xs[j].second] == 0){ c = xs[j].first; break;}
                rep(j, D, n-1) if (alr[ys[j].second] == 0){ d = ys[j].first; break;}
                ll ans1 = 1;
                if ((c-a) & 1) ans1 *= c-a+1;
                else{
                    if (c-a > 0) ans1 *= c-a;
                    else ans1 *= 1;
                }

                if ((b-d) & 1) ans1 *= b-d+1;
                else{
                    if (b-d > 0) ans1 *= b-d;
                    else ans1 *= 1;
                }
                ans = min(ans, ans1);
 
                while (D > 0){
                    D--; alr[ys[D].second]--;
                }
                while (R < n-1){
                    R++; alr[xs[R].second]--;
                }
            }
            
            while (U < n-1){
                U++; alr[ys[U].second]--;
            }
        }
 
        while (L > 0){
            L--; alr[xs[L].second]--;
        }
    }
 
    cout << ans / 4 << "\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
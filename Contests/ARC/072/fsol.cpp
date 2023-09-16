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

bool compare(ll x, ll y, ll z, ll t){
    if (y / x > t / z) return false;
    if (y / x < t / z) return true;
    ll u = y % x, v = t % z;
    if (u * z <= v * x) return true;
    else return false;
}

void solve(){
    int n; cin >> n;
    ll l; cin >> l;
    deque<pair<ll, ll>> q;
    vector<ll> ans;
    ll totx = 0, toty = 0;
    for (int i = 0; i < n; i++){
        ll t, v;
        cin >> t >> v;
        if (i == 0){
            ans.push_back(t * v);
            q.push_front({v, t*v});
            totx += v; toty += t*v;
            continue;
        }
        else{
            q.push_front({v, t*v});
            totx += v;
            toty += t*v;

            // find cut V
            while (true){
                pair<ll, ll> cur = q.back();
                ll x1 = cur.first, y1 = cur.second;
                if (totx - x1 < l){
                    ans.push_back(y1);
                }
            }
            
            ll x = v, y = t*v;

            while (true){
                pair<ll, ll> cur = q.front();
                ll x1 = cur.first, y1 = cur.second;
                bool b = compare(x, y, x1, y1);
                if (b){
                    q.push_front({x, y});
                    break;
                }
                else{

                }
            }
        }
    }
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
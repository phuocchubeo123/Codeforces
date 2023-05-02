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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

map<ll, int> encode;
void makeUnique(vector<ll> &a){
    sort(all(a));
    auto it = unique(all(a));
    a.resize(distance(a.begin(), it));

    forn(i, a.size()){
        encode[a[i]] = i;
    }
}

void solve(){
    int n; cin >> n;
    ll p; cin >> p;
    vector<ll> a(n+1, 0); rep(i, 1, n) cin >> a[i];

    if (p < 400){
        vector<bool> has(p, false);
        int ans = 0;
        while (true){
            ll rem = 0;
            per(i, n, 0){
                a[i] += rem;
                rem = 0;
                if (a[i] == p){
                    a[i] = 0;
                    rem = 1;
                }
            }
            if (a[0] == 1) has[1] = true;
            rep(i, 1, n) has[a[i]] = true;
            int cnt = 0;
            forn(i, p) if (has[i]) cnt++;
            if (cnt == p){ cout << ans << "\n"; return;}
            ans++;
            a[n]++;
            // cout << ans << " ";
        }        
    }

    if (a[n] <= 200){
        vector<bool> has(a[n], false);
        rep(i, 1, n) if (a[i] < a[n]) has[a[i]] = true;
        int cnt=0;
        rep(i, 0, a[n]-1) if (has[i]) cnt++;
        // cout << "cnt: " << cnt << "\n";
        if (cnt == a[n]){
            vector<ll> alr;
            rep(i, 1, n) if (a[i] > a[n]) alr.push_back(a[i]);
            makeUnique(alr);
            if (alr.size() == 0){ cout << p - 1 - a[n] << "\n"; return;}
            per(i, alr.size()-1, 0){
                if (alr[i] == p - (alr.size() - i)) continue;
                cout << p - (alr.size() - i) - a[n] << "\n";
                return;
            }
        }
        // forn(i, n+1) cout << a[i] << " ";
        // cout << "\n";
        int x = a[n];
        int rem = 0;
        a[n] = p; 
        per(i, n, 0){
            a[i] += rem;
            rem = 0;
            if (a[i] == p){
                a[i] = 0;
                rem = 1;
            }
        }

        // forn(i, n+1) cout << a[i] << " ";
        // cout << "\n";

        rep(i, 0, n) if (a[i] < x)  has[a[i]] = true;      
        // rep(i, 0, x-1) cout << has[i] << " ";
        // cout << "\n";
        int ans = 0;
        rep(i, 0, x-1) if (!has[i]) ans = max(ans, i);
        cout << p - (x - ans) << "\n";
        return;
    }

    int x = a[n];
    vector<ll> alr;
    rep(i, 1, n) if (a[i] < x) alr.push_back(a[i]);

    int rem = 0;
    a[n] = p; 
    per(i, n, 0){
        a[i] += rem;
        rem = 0;
        if (a[i] == p){
            a[i] = 0;
            rem = 1;
        }
    }

    rep(i, 0, n) if (a[i] < x) alr.push_back(a[i]);
    makeUnique(alr);

    if (alr.size() == 0){
        cout << p-1 << "\n";
        return;
    }

    per(i, alr.size()-1, 0){
        if (alr[i] == x - (alr.size() - i)) continue;
        cout << p - x + x - (alr.size() - i) << "\n";
        return;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}
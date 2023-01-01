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

const int maxn = 2e2 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

bool isp[maxn];

void eratosthenesSieve(){
    forn(i, maxn) isp[i] = true;
    isp[0] = false;
    rep(i, 1, maxn){
        if (i == 1){
            isp[i] = false;
            continue;
        }

        for (int j = 2; i * j < maxn; j++) isp[i * j] = false;
    }
}

vi primes;

void findPrimes(){
    forn(i, maxn) if (isp[i]) primes.push_back(i);
}

void solve(){
    int n; cin >> n;
    vector<ll> a(n); forn(i, n) cin >> a[i];

    // cout << primes.size() << " " << primes[primes.size() - 1] << "\n";

    for (int p: primes){
        vi can(p, 1);
        forn(i, n){
            rep(j, i+1, n-1){
                if (a[i] == a[j]){ cout << "NO\n"; return;}
                if ((a[i] - a[j]) % p == 0){
                    can[(p - (a[i] % p)) % p] = 0;
                    can[(p - (a[j] % p)) % p] = 0;
                }
            }
        }
        bool flag = false;
        forn(i, p){
            if (can[i] == 1){ flag = true; break;}
        }
        if (flag) continue;
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    eratosthenesSieve();
    findPrimes();
    while(T--){
        solve();
    }
}
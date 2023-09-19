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

const ll maxn = 1e6 + 5;
const ll mod = 1e9 + 7; // 998244353
const ll INF = 1e9;
const ll LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;
ll mo(ll a,ll b){
    b=b%(mod-1);
    b=(b+mod-1)%(mod-1);
    if(b==0){
        return 1ll;
    }
    ll vmod=mo(a,b/2);
    vmod=(vmod*vmod)%mod;
    if(b%2==0){
        return vmod;
    }
    return (vmod*a)%mod;
}
ll fac[maxn+2],fac1[maxn+2];
ll Ckn(ll k,ll n){
    if(k<0||k>n){
        return 0;
    }
    ll ans=(fac[n]*fac1[k])%mod;
    ans=(ans*fac1[n-k])%mod;
    return ans;
}
ll mu1(ll a){
    if(a%2==0){
        return 1ll;
    }
    return -1ll;
}
void solve(){
    ll n,i,j;
    cin >> n;
    fac[0]=0;fac1[0]=1;
    ll ans=0;
    for(i=1;i<=n;i++){
        fac[i]=(fac[i-1]*i)%mod;
        fac1[i]=mo(fac[i],mod-2);
    }
    for(i=0;i<=n;i++){
        ll sum=(Ckn(i,n)*mo(2,n*i))%mod;
        sum=sum*mu1(i);
        ll k=(mo(3,n-i)-mo(2,n-2*i))%mod;
        sum=(sum*mo(k,n));
        ans=(ans+sum)%mod;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
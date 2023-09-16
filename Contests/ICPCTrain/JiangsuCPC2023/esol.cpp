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

const int maxn = 1e6 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;
ll uoc[maxn+1],num[maxn+1];
ll fac[1400],fac1[1400];

mo(ll a,ll b){
    if(b==0){
        return 1ll;
    }
    ll vmod=mo(a,b/2);
    vmod=(vmod*vmod)%MOD;
    if(b%2==0){
        return vmod;
    }
    return (vmod*a)%MOD;
}
ll nCk(ll n,ll k){
    if(k<0||k>n){
        return 0;
    }
    ll ans=(fac[n]*fac1[k])%MOD;
    ans=(ans*fac1[n-k])%MOD;
    return ans;
}
void solve(){
    ll n,i,j;
    ll x,k;
    cin >> x >> k;
    fac[0]=1;fac1[0]=1;
    for(i=1;i<1400;i++){
        fac[i]=(fac[i-1]*i)%MOD;
        fac1[i]=mo(fac[i],MOD-2);
    }
    for(i=1;i<maxn;i++){
        uoc[i]=0;
        num[i]=0;
    }
    for(i=1;i<maxn;i++){
        uoc[i]++;
        ll so=nCk(uoc[i],k);
        num[i]=(num[i]+so)%MOD;
        for(j=2;j*i<maxn;j++){
            uoc[i*j]++;
            num[i*j]=(num[i*j]-num[i])%MOD;
        }
    }
    for(i=1;i<maxn;i++){
        for(j=2;j*i<maxn;j++){
            num[i*j]=(num[i*j]-num[i])%MOD;
        }
    }
    ll sq=sqrt(x);
    vector<ll> uocx;
    ll y,z;
    for(i=1;i<=sq;i++){
        if(i*i==x){
            uocx.push_back(i);
            continue;
        }
        else if(x%i==0){
            uocx.push_back(i);
            uocx.push_back(x/i);
        }
    }
    ll ans=0;
    ll num1[1400],uoc1[1400];
    for(auto z:uocx){
        y=x/z-1;
        if(y==0){
            continue;
        }
        if(y<maxn){
            ans=ans+num[y];
            continue;
        }
        sq=sqrt(y);
        vector<ll> uocy;
        for(i=1;i<=sq;i++){
            if(i*i==y){
                uocy.push_back(i);
                continue;
            }
            else if(y%i==0){
                uocy.push_back(i);
                uocy.push_back(y/i);
            }
        }
        sort(uocy.begin(),uocy.end());
        ll m=uocy.size();
        for(i=0;i<m;i++){
            num1[i]=0;
            uoc1[i]=0;
        }
        for(i=0;i<m;i++){
            uoc1[i]++;
            ll so=nCk(uoc1[i],k);
            num1[i]=(num1[i]+so)%MOD;
            for(j=i+1;j<m;j++){
                if(uocy[j]%uocy[i]!=0){
                    continue;
                }
                uoc1[j]++;
                num1[j]=(num1[j]-num1[i])%MOD;
            }
        }
        for(i=0;i<m;i++){
            for(j=i+1;j<m;j++){
                if(uocy[j]%uocy[i]!=0){
                    continue;
                }
                num1[j]=(num1[j]-num1[i])%MOD;
            }
        }
        ans=(ans+num1[m-1])%MOD;
    }
    ans=(ans+MOD)%MOD;
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
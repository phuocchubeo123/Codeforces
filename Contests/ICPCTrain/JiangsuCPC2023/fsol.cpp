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
    ll A,B,P,Q,i,j;
    cin >> A >> B >> P >> Q;
    double dp[A+1];
    for(i=0;i<B;i++){
        dp[i]=0.0;
    }
    double Pd,Qd;
    Pd=P*1.0;
    Qd=Q*1.0;
    for(i=B;i<=A;i++){
        if(B==1){
            if(100*100>=(100+P)*(100-Q)){
                dp[i]=dp[i-1]+100.0/(100.0-Qd);
            }
            else{
                dp[i]=dp[i-1]+(100.0+Pd)/(100);
            }
        }
        else{
            if(Qd*dp[i-B+1]>=Pd+Qd*dp[i-B]){
                dp[i]=1.0+dp[i-B]+Qd/100.0*(dp[i-B+1]-dp[i-B]);
            }
            else{
                dp[i]=1.0+dp[i-B]+Pd/100.0;
            }
        }
    }
    cout << fixed << setprecision(10) << dp[A];
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
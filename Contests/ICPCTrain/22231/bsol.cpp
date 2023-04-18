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
    ll b, d, s;
    cin >> b >> d >> s;
    ll b1, d1, s1;
    ll ans = 2000000000000000002;
    forn(i, 4){
        forn(o, 4){
            // cout << i << " " << o << ":\n";
            ll l = 0, r = 1000000000000000002;
            while (l < r){
                ll m = (l + r) / 2;
                // cout << l << " " << r << " " << m << ":\n";
                b1 = 0; d1 = 0; s1 = 0;
                if (m == 0){
                    if (i >= o){
                        l = m+1;
                        continue;
                    }
                    if (i == 0){ b1++; d1++; s1++;}
                    else if (i == 1){ d1++; s1++;}
                    else if (i == 2){ s1++;}

                    if (o == 1){ d1--; s1--;}
                    else if (o == 2){ s1--;}

                    // cout << b1 << " " << d1 << " " << s1 << "\n";
                    if (b1 >= b && d1 >= d && s1 >= s) r = m;
                    else l = m+1;
                    continue;
                }

                if (i == 0){ b1++; d1++; s1++;}
                else if (i == 1){ d1++; s1++;}
                else if (i == 2){ s1++;}

                if (o == 1){ b1++;}
                else if (o == 2){ b1++; d1++;}
                else if (o == 3){ b1++; d1++; s1++;}

                b1 += m-1;
                d1 += m-1;
                s1 += m-1;

                // cout << b1 << " " << d1 << " " << s1 << " ";
                // cout << (b1 >= b && d1 >= d && s1 >= s) << "\n";
                if (b1 >= b && d1 >= d && s1 >= s){
                    // cout << "can\n";
                    r = m;
                }
                else{
                    // cout << "cannot\n";
                    l = m+1;
                }
            }
            b1 = 0; d1 = 0; s1 = 0;
            if (l == 0){
                if (i >= o){
                    continue;
                }
                if (i == 0){ b1++; d1++; s1++;}
                else if (i == 1){ d1++; s1++;}
                else if (i == 2){ s1++;}

                if (o == 1){ d1--; s1--;}
                else if (o == 2){ s1--;}

                // cout << b1 << " " << d1 << " " << s1 << "\n";
                ans = min(b1-b + d1-d + s1-s, ans);
                continue;
            }

            if (i == 0){ b1++; d1++; s1++;}
            else if (i == 1){ d1++; s1++;}
            else if (i == 2){ s1++;}

            if (o == 1){ b1++;}
            else if (o == 2){ b1++; d1++;}
            else if (o == 3){ b1++; d1++; s1++;}

            b1 += l-1;
            d1 += l-1;
            s1 += l-1;
            // cout << b1 << " " << d1 << " " << s1 << "\n";
            ans = min(b1-b + d1-d + s1-s, ans);
        }
    }
    cout << ans << "\n";
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
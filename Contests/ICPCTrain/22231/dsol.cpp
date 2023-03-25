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
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    string s;
    if (n2 == 0){
        if (n1 == 0){
            forn(i, n3+1) s.push_back('1');
            cout << s << "\n";
            return;
        }
        if (n3 == 0){
            forn(i, n1+1) s.push_back('0');
            cout << s << "\n";
            return;
        }
    }

    if (n2 & 1){
        forn(i, n1) s.push_back('0');
        forn(i, n2/2+1){
            s.push_back('0'); 
            s.push_back('1');
        }
        forn(i, n3) s.push_back('1');
        cout << s << "\n";
        return;
    }
    else{
        forn(i, n1) s.push_back('0');
        forn(i, n2/2){
            s.push_back('0'); 
            s.push_back('1');
        }
        forn(i, n3) s.push_back('1');
        s.push_back('0');
        cout << s << "\n";
        return;
    }
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
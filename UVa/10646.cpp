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
    vector<int> pile;
    vector<string> real_pile(52);
    forn(i, 52){
        char c; cin >> c;
        real_pile[i].push_back(c);
        if (c >= '2' && c <= '9') pile.push_back(c - '0');
        else pile.push_back(10);
        cin >> c;
        real_pile[i].push_back(c);
    }

    vi pile2;
    vector<string> real_pile2;
    rep(i, 27, 51){
        pile2.push_back(pile[i]);
        real_pile2.push_back(real_pile[i]);
    }
    rep(i, 27, 51){
        real_pile.pop_back();
        pile.pop_back();
    }

    int pt = 26;
    int y = 0;
    forn(_, 3){
        int x = pile.back();
        y += x;
        pile.pop_back();
        real_pile.pop_back();
        forn(i, 10 - x){
            pile.pop_back();
            real_pile.pop_back();
        }
    }

    forn(i, 25){
        real_pile.push_back(real_pile2[i]);
    }
    cout << real_pile[y-1] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    int tt = 1;
    while(T--){
        cout << "Case " << tt << ": ";
        solve();
        tt++;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
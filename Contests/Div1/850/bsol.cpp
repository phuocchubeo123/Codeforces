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
    int m; cin >> m;
    vi w, n, i, wi, wn, ni, nw, in, iw;
    forn(_, m){
        string s;
        cin >> s;
        int W = 0, I = 0, N = 0;
        forn(j, 3){
            if (s[j] == 'w') W++;
            if (s[j] == 'n') N++;
            if (s[j] == 'i') I++;
        }

        if (W == 3) w.push_back(_);
        if (I == 3) i.push_back(_);
        if (N == 3) n.push_back(_);
        if (W == 2 && I == 1) wi.push_back(_);
        if (W == 2 && N == 1) wn.push_back(_);
        if (I == 2 && W == 1) iw.push_back(_);
        if (I == 2 && N == 1) in.push_back(_);
        if (N == 2 && W == 1) nw.push_back(_);
        if (N == 2 && I == 1) ni.push_back(_);
    }

    vector<pair<pair<int, char>, pair<int, char>>> ans;
    while (true){
        if (w.size() > 0){
            if (in.size() > 0){
                int x = w.back();
                int y = in.back();
                w.pop_back(); in.pop_back();
                wi.push_back(x);
                ans.push_back({{x, 'w'}, {y, 'i'}});
                continue;
            }
            if (ni.size() > 0){
                int x = w.back();
                int y = ni.back();
                w.pop_back(); ni.pop_back();
                wn.push_back(x);
                ans.push_back({x, 'w'}, {y, 'n'});
                cout << x << " w " << y << " n \n";
                continue;
            }
        }

        if (i.size() > 0){
            if (wn.size() > 0){
                int x = i.back();
                int y = wn.back();
                i.pop_back(); wn.pop_back();
                iw.push_back(x);
                cout << x << " i " << y << " w \n";
                continue;
            }
            if (nw.size() > 0){
                int x = i.back();
                int y = nw.back();
                i.pop_back(); nw.pop_back();
                in.push_back(x);
                cout << x << " i " << y << " n \n";
                continue;
            }
        }

        if (n.size() > 0){
            if (wi.size() > 0){
                int x = n.back();
                int y = wi.back();
                n.pop_back(); wi.pop_back();
                nw.push_back(x);
                ans.push_back({{x, 'n'}, {y, 'w'}});
                continue;
            }
            if (iw.size() > 0){
                int x = n.back();
                int y = iw.back();
                n.pop_back(); iw.pop_back();
                ni.push_back(x);
                ans.push_back({{x, 'n'}, {y, 'i'}});
                continue;
            }
        }

        if (w.size() > 0 || i.size() > 0 || n.size() > 0) continue;

        if (wi.size() > ni.size()){
            
        }
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
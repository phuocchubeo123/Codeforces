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

vector<vector<int>> v;
vector<vector<int>> new_v;
int mx = 4;

void solve() {
    v.push_back({1, 2});
    v.push_back({2, 1});

    for (int i = 4; i <= mx*2; i *= 2){
        vector<pair<int, int>> vp;
        for (int j = 1; j <= i; j+=2){
            vp.push_back({j, j+1});
        }
    
        for (auto a: v){
            vector<int> p;
            for (int x: a){
                p.push_back(vp[x-1].first);
                p.push_back(vp[x-1].second);
            }
            new_v.push_back(p);
        }

        vector<int> p(i);
        for (int j = 0; j < i/2; j++){
            p[j] = vp[j].first;
            p[i-j-1] = vp[j].second;
        }
        
        new_v.push_back(p);
        reverse(p.begin(), p.end());
        new_v.push_back(p);

        for (int j = 0; j < i/2; j++){
            p[j] = vp[i/2-j-1].first;
            p[i-j-1] = vp[i/2-j-1].second;
        }

        new_v.push_back(p);
        reverse(p.begin(), p.end());
        new_v.push_back(p);

        v = new_v;
        new_v.clear();
    }

    cout << v.size() << "\n";

    for (int i = 0; i < v.size(); i++){
        for (int x: v[i]){
            if (x <= mx) cout << x << " ";
        }
        cout << "\n";
    }
}

void test(){
    vector<vector<int>> p;
    for (int i = 0; i <v.size(); i++){
        vector<int> ps(v[i].size() + 1);
        for (int j = 0; j < v[i].size(); j++){
            ps[v[i][j]] = j;
        }
        p.push_back(ps);
    }

    for (int i = 1; i <= mx; i++){
        for (int j = 1; j <= mx; j++){
            if (i == j) continue;
            for (int k = 1; k <= mx; k++){
                if (k == i || k == j) continue;
                bool flag = false;
                for (int l = 0; l < v.size(); l++){
                    if (p[l][i] < p[l][j] && p[l][j] < p[l][k]) flag = true;
                }
                if (!flag) cout << i << " " << j << " " << k << "\n";
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
        test();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
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

vector<int> delta(vector<int> v){
    vector<int> q;
    for (int i = 0; i < v.size() - 1; i++) q.push_back(v[i+1] - v[i]);
    return q;
}

void print_vector(vector<int> v){
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";
}

vector<ll> ans;

void solve(){
    ll n; cin >> n;

    if (n < 6){
        cout << ans[n] << "\n";
        return;
    }

    // for (int i = 0; i < 6; i++) cout << ans[i] << " ";
    // for (int i = 6; i < 25; i++) cout << ans[5] + 148 * (i - 5) + 28 * (i - 5) * (i - 6) / 2 << " "; 
    ll uu = (ans[5] + 1ll * 148 * (n - 5) + 1ll * 28 * (1ll * (n - 5) * (n - 6) / 2));
    cout << uu << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;

    ////////
    // vector<int> uu = {1, 9, 41, 109, 205, 325, 473, 649, 853, 1085, 1345, 1633, 1949, 2293, 2665, 3065, 3493, 3949, 4433, 4945, 5485, 6053, 6649, 7273, 7925, 8605};
    // print_vector(delta(uu));
    // print_vector(delta(delta(uu)));


    int tc = 0;
    set<pair<int, int>> s1;
    set<pair<int, int>> s2;

    s1.insert({0, 0});


    ans.push_back(s1.size());

    vector<pair<int, int>> dir = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    for (int i = 0; i < 6; i++){
        for (pair<int, int> p: s1){
            for (pair<int, int> d: dir){
                s2.insert({p.first+d.first, p.second+d.second});
            }
        }
        for (auto p: s2) s1.insert(p);
        s2.clear();

        ans.push_back(s1.size());
    }
    while(T--){
        tc++;
        cout << "Case #" << tc << ": ";
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
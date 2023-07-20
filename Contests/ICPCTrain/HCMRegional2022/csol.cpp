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
    int n; cin >> n;
    vi a(n), b(n);
    forn(i, n){
        cin >> a[i];
    }
    forn(i, n){
        cin >> b[i];
    }

    if (n % 2 == 0){
        cout << -1 << "\n";
        return;
    } 

    int pivot;
    vi can;
    forn(i, n){
        if (a[i] == 0 || b[i] == 0) pivot = i;
        else can.push_back(i);
    }

    int z;
    int st = 0;
    vi steps;
    if (a[pivot] == 0){
        z = b[pivot];
        steps.push_back(b[pivot]);
        st = 1;
    }
    else{
        z = a[pivot];
    }

    forn(i, n/2){
        int c1 = can[i*2];
        int c2 = can[i*2+1];

        int x1 = a[c1], x2 = a[c2], y1 = b[c1], y2 = b[c2];

        steps.push_back(x1);
        steps.push_back(y1);
        steps.push_back(x2);
        steps.push_back(x1);
        steps.push_back(z);
        steps.push_back(x2);
        steps.push_back(x1);
        steps.push_back(y2);
        steps.push_back(x2);
        steps.push_back(z);
    }

    if (st == 0) steps.push_back(z);

    cout << steps.size() << "\n";
    for (int x: steps) cout << x << " ";
    cout << "\n";
    return;
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
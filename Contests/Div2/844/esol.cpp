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
    vi u(n), d(n), l(n), r(n);
    forn(i, n) cin >> u[i] >> l[i] >> d[i] >> r[i];
    vi one, two, ot;
    forn(i, n){
        if (u[i] == 1 && d[i] == 1) one.push_back(i);
        if (u[i] == 1 && d[i] == 2) ot.push_back(i);
        if (u[i] == 2 && d[i] == 2) two.push_back(i);
    }

    auto sortl = [&](int x, int y){
        return (l[x] < l[y]);
    };

    sort(all(one), sortl); 
    sort(all(two), sortl);
    sort(all(ot), sortl);

    // cout << "before:\n";
    // forn(i, one.size()){
    //     int blk = one[i];
    //     cout << blk << " " << l[blk] << " " << r[blk] << "\n";
    // }

    int curr = 0;
    forn(i, one.size()){
        int blk = one[i];
        if (l[blk] > curr){ curr = r[blk]; continue;}
        if (r[blk] <= curr){ l[blk] = 0; r[blk] = 0; continue;}
        l[blk] = curr+1; curr = r[blk];
    }
    sort(all(one), sortl); 

    curr = 0;
    forn(i, two.size()){
        int blk = two[i];
        if (l[blk] > curr){ curr = r[blk]; continue;}
        if (r[blk] <= curr){ l[blk] = 0; r[blk] = 0; continue;}
        l[blk] = curr+1; curr = r[blk];
    }
    sort(all(two), sortl); 

    curr = 0;
    forn(i, ot.size()){
        int blk = ot[i];
        if (l[blk] > curr){ curr = r[blk]; continue;}
        if (r[blk] <= curr){ l[blk] = 0; r[blk] = 0; continue;}
        l[blk] = curr+1; curr = r[blk];
    }
    sort(all(ot), sortl); 

    // cout << "after\n";
    // forn(i, one.size()){
    //     int blk = one[i];
    //     cout << blk << " " << l[blk] << " " << r[blk] << "\n";
    // }

    // cout << "\n";

    // forn(i, one.size()){
    //     int blk = one[i];
    //     cout << l[blk] << " " << r[blk] << "; ";
    // }
    // cout << "\n";
    // forn(i, two.size()){
    //     int blk = two[i];
    //     cout << l[blk] << " " << r[blk] << "; ";
    // }
    // cout << "\n";
    // forn(i, ot.size()){
    //     int blk = ot[i];
    //     cout << l[blk] << " " << r[blk] << "; ";
    // }
    // cout << "\n";

    int pt1 = 0;
    forn(i, ot.size()){
        int blk12 = ot[i];
        while (true){
            // cout << pt1 << " ";
            if (pt1 >= one.size()) break;
            int blk1 = one[pt1];
            if (l[blk1] > r[blk12]) break;
            if (r[blk1] < l[blk12]){ pt1++; continue;}
            if (r[blk1] <= r[blk12]){
                if (l[blk1] >= l[blk12]){ l[blk1] = 0; r[blk1] = 0; pt1++; continue;}
                r[blk1] = l[blk12] - 1;
                pt1++;
                continue;
            }
            if (l[blk1] < l[blk12]){
                u[blk12] = 2;
                d[blk12] = 2;
                // pt1++;
                break;
            }
            l[blk1] = r[blk12] + 1;
            // pt1++;
            continue;
        }
    }

    // cout << "\nbefore clear 2\n";
    // forn(i, two.size()){
    //     int blk = two[i];
    //     cout << l[blk] << " " << r[blk] << "; ";
    // }
    // cout << "\n";
    // forn(i, ot.size()){
    //     int blk = ot[i];
    //     cout << l[blk] << " " << r[blk] << "; ";
    // }
    // cout << "\n";

    int pt2 = 0;
    forn(i, ot.size()){
        int blk12 = ot[i];
        while (true){
            if (pt2 >= two.size()) break;
            int blk2 = two[pt2];
            if (l[blk2] > r[blk12]) break;
            if (r[blk2] < l[blk12]){ pt2++; continue;}
            if (r[blk2] <= r[blk12]){
                if (l[blk2] >= l[blk12]){ l[blk2] = 0; r[blk2] = 0; pt2++; continue;}
                r[blk2] = l[blk12] - 1;
                pt2++;
                continue;
            }
            if (l[blk2] <= l[blk12]){
                // cout << blk12 << "\n";
                if (u[blk12] == 1) d[blk12] = 1;
                else{ d[blk12] = 0; u[blk12] = 0;}
                // pt2++;
                break;
            }
            l[blk2] = r[blk12] + 1;
            // pt2++;
            continue;
        }
    }

    // cout << "\n";
    // cout << "after clear 2\n";
    // forn(i, two.size()){
    //     int blk = two[i];
    //     cout << l[blk] << " " << r[blk] << "; ";
    // }
    // cout << "\n";
    // forn(i, ot.size()){
    //     int blk = ot[i];
    //     cout << l[blk] << " " << r[blk] << "; ";
    // }
    // cout << "\n";


    // cout << "\n";

    ll ans = 0;
    forn(i, n){
        if (u[i] == 0 || d[i] == 0){ l[i] = 0; r[i] = 0;}
        if (l[i] == 0 || r[i] == 0){ u[i] = 0; d[i] = 0;}
        if (u[i] != 0) ans += 1ll * (d[i] - u[i] + 1) * 1ll * (r[i] - l[i] + 1);
    }

    cout << ans << "\n";
    forn(i, n){
        cout << u[i] << " " << l[i] << " " << d[i] << " " << r[i] << "\n";
    }

    // cout << "\n";
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
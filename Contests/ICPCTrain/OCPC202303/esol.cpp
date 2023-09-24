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

int find_CCPC(string s){
    int a = 0;
    for (int i = 0; i < s.size() - 3; i++){
        // cout << i << " " << s.substr(i, 4) << "\n";
        if (s.substr(i, 4) == "CCPC") a++;
    }
    return a;
}

void tst(){
    vector<string> s;
    for (int mask = 0; mask < 8; mask++){
        string t;
        for (int bit = 0; bit < 3; bit++){
            if ((mask >> bit) & 1) t.push_back('C');
            else t.push_back('P');
        }
        s.push_back(t);
    }

    for (string t1: s){
        for (string t2: s){
            string s1 = t1;
            for (char c: t2) s1.push_back(c);
            string s2 = t1;
            s2.push_back('C');
            for (char c: t2) s2.push_back(c);
            string s3 = t1;
            s3.push_back('P');
            for (char c: t2) s3.push_back(c);

            cout << s1 << " " << s2 << " " << s3 << " " << find_CCPC(s2) - find_CCPC(s1) << " " << find_CCPC(s3) - find_CCPC(s1) << "\n";
        }
    }
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    // cout << s << "\n";

    if (s.size() <= 2){
        cout << 0 << "\n";
        return;
    }

    if (s.size() == 3){
        if (s == "CPC" || s == "CCP" || s == "CCC"){
            cout << 1 << "\n";
            return;
        }
        
        cout << 0 << "\n";
        return;
    }

    int ans = find_CCPC(s);

    // int p2 = 0;
    // for (int i = 0; i < n-5; i++){
    //     if (s.substr(i, 6) == "CCPCPC") p2++;
    // }
    // if (p2 == 2){
    //     cout << ans + 3 << "\n";
    //     return;
    // }

    // if (p2 == 1){
    //     cout << ans + 2 << "\n";
    //     return;
    // }

    
    // cout << s << "\n";

    if (s.substr(0, 3) == "CPC"){
        cout << ans + 1 << "\n";
        return;
    }

    if (s.substr(n-3, 3) == "CCP"){
        cout << ans + 1 << "\n";
        return;
    }

    for (int i = 1; i < n; i++){
        int l = max(i-3, 0);
        int r = min(i+3, n-1);
        // cout << i << " " << l << " " << r << "\n";
        int len1 = i - 1 - l + 1;
        int len2 = r - i + 1;
        string t1 = s.substr(l, len1);
        string t2 = s.substr(i, len2);

        // cout << i << " " << t1 << " " << t2 << "\n";
        
        string s1 = t1;
        for (char c: t2) s1.push_back(c);
        string s2 = t1;
        s2.push_back('C');
        for (char c: t2) s2.push_back(c);
        string s3 = t1;
        s3.push_back('P');
        for (char c: t2) s3.push_back(c);

        if (find_CCPC(s2) > find_CCPC(s1) || find_CCPC(s3) > find_CCPC(s1)){
            cout << ans+1 << "\n";
            return;
        }
    }   

    cout << ans << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    // tst();
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
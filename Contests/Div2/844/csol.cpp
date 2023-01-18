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
    string s; cin >> s;

    vi cnt(26, 0);
    forn(i, n) cnt[s[i] - 'a']++;
    vector<char> alphabet;
    forn(i, 26) alphabet.push_back('a' + i);
    sort(all(alphabet), [&](char x, char y){
        return (cnt[x-'a'] > cnt[y-'a']);
    });

    // forn(i, 26) cout << alphabet[i] << ", " << cnt[alphabet[i] - 'a'] << "; ";
    vvi pos(26);
    forn(i, n) pos[s[i] - 'a'].push_back(i);
    // forn(i, 26){
    //     cout << (char)('a' + i) << "\n";
    //     for (int k: pos[i]) cout << k << " ";
    //     cout << "\n";
    // } 

    int mx = 0, anss;

    vector<int> ans(27);
    vector<string> ans2(27);
    rep(i, 1, 26){
        if (n % i != 0) continue;
        vvi pos2 = pos;
        int freq = n / i;
        int sim = 0;
        forn(j, i){
            int eq = min(cnt[alphabet[j] - 'a'], freq);
            // cout << alphabet[j] << " " << eq << "\n";
            sim += eq;
            while (pos2[alphabet[j] - 'a'].size() > eq){
                pos2[alphabet[j] - 'a'].pop_back();
            }
        }
        vi cnt2(26, freq);
        string s2;
        forn(j, n) s2.push_back('0');
        // forn(j, i) cout << alphabet[j] << " ";
        // cout << "\n";
        forn(j, i) for (int k: pos2[alphabet[j] - 'a']){ s2[k] = alphabet[j]; cnt2[alphabet[j]-'a']--;}
        // cout << i << " " << sim << " " << s2 << "\n";

        int pt = 0;
        forn(j, n){
            while (cnt2[alphabet[pt] - 'a'] == 0) pt++;
            if (s2[j] != '0') continue;
            // cout << alphabet[pt];
            s2[j] = alphabet[pt];
            cnt2[alphabet[pt] - 'a']--;
        }
        // cout << "\n";
        // cout << s2 << "\n";

        ans[i] = n-sim;
        ans2[i] = s2;
        // cout << sim << " " << mx << "\n";
        if (sim >= mx){
            anss = i;
            mx = sim;
        }
    }
    // cout << anss << "\n";
    cout << ans[anss] << "\n";
    cout << ans2[anss] << "\n";
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
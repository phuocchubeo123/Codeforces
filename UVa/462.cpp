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

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    while (true){
        string s;
        getline(cin, s);
        if (s == "") break;
        vector<vector<char>> suits(4);
        forn(i, 13){
            char rank = s[i * 3];
            char suit = s[i * 3 + 1];
            if (suit == 'S') suits[0].push_back(rank);
            if (suit == 'H') suits[1].push_back(rank);
            if (suit == 'D') suits[2].push_back(rank);
            if (suit == 'C') suits[3].push_back(rank);
        }

        int point = 0;
        for (vector<char> st: suits){
            for (char rank: st){
                if (rank == 'A') point += 4;
                if (rank == 'K') point += 3;
                if (rank == 'Q') point += 2;
                if (rank == 'J') point += 1;
            }
        }

        vector<bool> stopped(4, false);
        forn(i, 4){
            vector<char> st = suits[i];
            int a = false, k = false, q = false, j = false;
            for (char rank: st){
                if (rank == 'A') a = true;
                if (rank == 'K') k = true;
                if (rank == 'Q') q = true;
                if (rank == 'J') j = true;
            }

            if (k && st.size() == 1) point--;
            if (q && (st.size() == 1 || st.size() == 2)) point--;
            if (j && st.size() >= 1 && st.size() <= 3) point--;

            if (a) stopped[i] = true;
            if (k && st.size() >= 2) stopped[i] = true;
            if (q && st.size() >= 3) stopped[i] = true;
        }

        if (point >= 16){
            bool no_trump = true;
            forn(i, 4) if (!stopped[i]) no_trump = false;
            if (no_trump){
                cout << "BID NO-TRUMP\n";
                continue;
            }
        }

        for (vector<char> st: suits){
            if (st.size() <= 1) point += 2;
            if (st.size() == 2) point += 1;
        }

        if (point < 14) cout << "PASS\n";
        else{
            char ans;
            int mx = 0;
            forn(i, 4){
                if (suits[i].size() > mx){
                    mx = max(mx, (int) suits[i].size());
                    if (i == 0) ans = 'S';
                    if (i == 1) ans = 'H';
                    if (i == 2) ans = 'D';
                    if (i == 3) ans = 'C';
                }
            }
            cout << "BID " << ans << "\n";
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}
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

bool query(int x, int y){
    cout << "? " << x << " " << y << "\n";
    cout.flush();
    char c;
    cin >> c;
    if (c == 'Y') return true;
    else return false;
}

void solve(){
    int a, b;
    cin >> a >> b;
    int n = a + b;
    if (a <= b){
        cout << "Impossible\n";
        cout.flush();
        return;
    }

    stack<int> st;

    for (int i = 0; i < n; i++){
        if (st.empty()){
            // cout << "empty! " << i << "\n";
            // cout.flush();
            st.push(i);
            continue;
        }

        int lst = st.top(); 
        bool b = query(i, lst);
        if (!b){
            st.pop();
        }
        else{
            st.push(i);
        }
    }

    while (st.size() > 1) st.pop();

    int honest = st.top();
    // cout << "! ";
    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (i == honest){
            ans.push_back(1);
            continue;
        }
        
        if (query(honest, i)){
            ans.push_back(1);
        }
        else{
            ans.push_back(0);
        }
    }

    cout << "! ";
    for (int i = 0; i < n; i++) cout << ans[i];
    cout << "\n";
    cout.flush();
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
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T a, T b){while(b){b^=a^=b^=a%=b;} return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> work(n+1, vi(7, 0));
    for (int i = 1; i <= n; i++){
        int t; cin >> t;
        forn(j, t){
            string s; cin >> s;
            if (s == "Monday") work[i][1] = 1;
            if (s == "Tuesday") work[i][2] = 1;
            if (s == "Wednesday") work[i][3] = 1;
            if (s == "Thursday") work[i][4] = 1;
            if (s == "Friday") work[i][5] = 1;
            if (s == "Saturday") work[i][6] = 1;
            if (s == "Sunday") work[i][0] = 1;
        }
    }

    map<int, int> holiday;
    forn(i, m){
        int h; cin >> h;
        holiday[h] = 1;
    }

    vector<queue<int>> job(k+1);

    for (int i = 1; i <= k; i++){
        int p; cin >> p;
        forn(j, p){
            int a; cin >> a;
            job[i].push(a);
        }
    }

    vector<set<int>> wk(n+1);
    for (int i = 1; i <= k; i++){
        int a = job[i].front();
        wk[a].insert(i);
    }

    vector<set<pii>> qu(7);

    for (int i = 1; i <= n; i++){
        if (!wk[i].empty()){
            int curr_job = *wk[i].begin();
            for (int j = 0; j < 7; j++){
                if (work[i][j] == 1) qu[j].insert({curr_job, i});
            }
        }
    }

    vi ans(k+1);
    int completed = 0;

    for (int d = 1;; d++){
        // cout << "day " << d << "\n";
        if (holiday[d] == 1) continue;
        int diw = d % 7;
        vector<pii> new_work;
        while (!qu[diw].empty()){
            pii curr = *qu[diw].begin();
            int a = curr.second, t = curr.first;
            // cout << a << ", " << t << " done\n";
            ans[t] = d;
            forn(i, 7){
                qu[i].erase({t, a});
            }
            wk[a].erase(t);
            if (!wk[a].empty()){
                int new_job = *wk[a].begin();
                new_work.push_back({new_job, a});
            }

            job[t].pop();
            if (!job[t].empty()){
                int new_person = job[t].front();
                // cout << new_person << " " << t << " continue\n";
                new_work.push_back({t, new_person});
            }
            else{
                // cout << t << " complete\n";
                completed++;
            }
        }
        for (pii curr: new_work){
            int a = curr.second, t = curr.first;
            if (wk[a].empty()){
                forn(i, 7) if (work[a][i] == 1) qu[i].insert({t, a});
                wk[a].insert(t);
                continue;
            }
            int curr_job = *wk[a].begin();
            if (t <= curr_job){
                forn(i, 7){
                    if (work[a][i] == 1){
                        qu[i].erase({curr_job, a});
                        qu[i].insert({t, a});
                    }
                }
            }
            wk[a].insert(t);
        }

        // cout << "\n";

        if (completed == k) break;

        // if (d >= 20) break;
    }

    for (int i = 1; i <= k; i++) cout << ans[i] << " ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}
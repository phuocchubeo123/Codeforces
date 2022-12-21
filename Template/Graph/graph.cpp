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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<vi> adj(maxn), chi(maxn);
vi vis(maxn), par(maxn);

void reRoot(int u){
    forn(i, maxn) par[i] = -1;
    stack<int> st;
    st.push(u);   
    while (!st.empty()){
        int curr = st.top(); st.pop();
        for (int next: adj[curr]){
            if (par[curr] == next) continue;
            par[next] = curr;
            chi[curr].push_back(next);
        }
    }
}

int main(){
    // read graph
    
}
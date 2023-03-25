#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T;

void prepare(){

}

ll dsc[N];
vt<int> ch[N];

void findDsc(int x){
    dsc[x] = 1;
    for (int nx: ch[x]){
        findDsc(nx);
        dsc[x] += dsc[nx];
    }
}

ll dpt[N];

void findDpt(int x){
    dpt[x] = 0;
    for (int nx: ch[x]){
        findDpt(nx);
        dpt[x] += dpt[nx] + dsc[nx];
    }
}

void solve(){
    int n; cin >> n;
    vt<vt<int>> adj(n + 1);
    for1(i, n - 1){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vt<int> pr(n + 1, -1);

    //find children and parents
    stack<int> s;
    s.push(1);
    while (!s.empty()){
        int curr = s.top(); s.pop();
        for (int next: adj[curr]){
            if (pr[curr] != next){
                pr[next] = curr;
                ch[curr].pb(next);
                s.push(next);
            }
        }
    }

    findDsc(1);
    findDpt(1);
    // for1(i, n) cout << dpt[i] << " ";

    vt<ll> upt(n + 1);
    upt[1] = 0;
    stack<int> s2;
    for (int x: ch[1]) s2.push(x);
    while (!s2.empty()){
        int curr = s2.top(); s2.pop();
        upt[curr] = dpt[pr[curr]] + upt[pr[curr]];
        upt[curr] -= (dpt[curr] + dsc[curr]);
        upt[curr] += (n - dsc[curr]);
        for (int next: ch[curr]) s2.push(next);
    }

    // cout << "\n";
    // for1(i, n) cout << upt[i] << " ";

    ll ans = 0;
    for1(i, n) ans = max(ans, dpt[i] + upt[i] + n);
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cin >> T;
    T = 1;

    while (T--){
        solve();
    }
}
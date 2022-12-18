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

vt<vt<int>> adj(N), ch(N);
vt<int> pr(N, -1), bwb(N), c(N), nb(N, 1);

void numBranchWithBlack(int x){
    bwb[x] = 0;
    for (int y: ch[x]){
        numBranchWithBlack(y);
        if (c[y] || (bwb[y] > 0)) bwb[x]++;
    }
}

void upBranchWithBlack(int x){
    for (int y: ch[x]){
        if (c[x] || (bwb[x] - min(bwb[y] + c[y], 1) > 0)) bwb[y]++;
        upBranchWithBlack(y);
    }
}

void noBlack(int x){
    if (c[x]) nb[x] = 1;
    for (int y: ch[x]){
        if (nb[x]) nb[y] = 1;
        noBlack(y);
    }
}

void reRoot(int r){
    stack<int> s;
    s.push(r);
    while (!s.empty()){
        int curr = s.top(); s.pop();
        for (int next: adj[curr]){
            if (pr[curr] != next){
                s.push(next);
                pr[next] = curr;
                ch[curr].pb(next);
            }
        }
    }
}

void solve(){
    int n; cin >> n;        
    for1(i, n) cin >> c[i];
    int u, v;
    for1(i, n - 1){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    reRoot(1);
    numBranchWithBlack(1);
    upBranchWithBlack(1);

    for1(i, n){
        if (bwb[i] > 1){
            for1(i, n) cout << 1 << " ";
            cout << "\n";
            return;
        }
    }

    int root;
    for1(i, n) if (c[i]) root = i;
    reRoot(root);
    nb[root] = 1;
    for (int x: ch[root]){
        noBlack(x);
    }

    vt<int> ans(n + 1);
    for1(i, n) if (nb[i]) ans[i] = 1;
    for1(i, n){
        if (nb[i]) ans[i] = 1;
        else{
            bool flag = false;
            for (int x: ch[i]){
                if (c[x]) flag = true;
            }
            if (flag) ans[i] = 1;
            else ans[i] = 0;
        }
    }
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
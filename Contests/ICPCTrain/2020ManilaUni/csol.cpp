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

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    vt<vt<int>> adj(n+1);
    adj[1] = {2};
    forlr(i, 2, n, 1) adj[i] = {i-1, i+1};
    adj[n] = {n-1};
    for0(i, b){
        int x, y;
        cin >> x >> y;
        while(!adj[x].empty()) adj[x].pop_back();
        adj[x].pb(y);
    }

    vt<int> can(n+1);
    for1(i, n) can[i] = 0;
    stack<int> st;
    st.push(1);
    while (!st.empty()){
        int curr = st.top(); st.pop();
        can[curr] = 1;
        for (int next: adj[curr]){
            if (can[next]) continue;
            st.push(next);
        }
    }

    if (can[a]) cout << "YES";
    else cout << "NO";
    return;
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
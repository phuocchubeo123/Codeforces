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

int n, m, s, t;
vt<int> alr(N);
vt<int> color(N);
vt<int> par(N);
 
pair<int, int> parents = {0, 0};

void printAns(){
    if (parents.first == 0){
        cout << "Impossible";
        return;
    }
 
    else{
        cout << "Possible\n";
        vt<int> seq1 = {t, parents.first};
        int curr = parents.first;
        while (par[curr] != s){
            curr = par[curr];
            seq1.pb(curr);
        }
        if (parents.first != s) seq1.pb(s);
 
        vt<int> seq2 = {t, parents.second};
        curr = parents.second;
        while (par[curr] != s){
            curr = par[curr];
            seq2.pb(curr);
        }
        if (parents.second != s) seq2.pb(s);
 
        reverse(seq1.begin(), seq1.end());
        reverse(seq2.begin(), seq2.end());
        cout << seq1.size() << "\n";
        for (int x: seq1){
            cout << x << " ";
        }
        cout << "\n";
 
        cout << seq2.size() << "\n";
        for (int x: seq2){
            cout << x << " ";
        }
    }
}
 
void solve(){
    cin >> n >> m >> s;
    // cout << n << " " << m << " " << s << "\n";
    vt<vt<int>> adj(n + 1);
 
    for0(e, m){
        int i, j; 
        cin >> i >> j;
        // cout << i << " " << j << "\n";
        adj[i].pb(j);
    }
 
    // for1(i, n){
    //     cout << i << ":\n";
    //     for (int j: adj[i]) cout << j << " ";
    //     cout << "\n";
    // }
    // return;

    for0(i, N) color[i] = s;
 
    queue<int> st;
    st.push(s);
    par[s] = s;
    int cnt = 0;
    while (!st.empty()){
        // queue<int> st2 = st;
        // while (!st2.empty()){
        //     cout << st2.front() << " ";
        //     st2.pop();
        // }
        // cout << "\n";
        int curr = st.front(); st.pop();
        alr[curr] = 1;
        // cout << "curr: " << curr << " " << color[curr] << "\n";
        for (int next: adj[curr]){
            if (next == s) continue;
            if (color[next] != s){
                if (color[curr] == color[next]) continue;
                else{
                    parents = {curr, par[next]};
                    t = next;
                    printAns();
                    return;
                }
            }
 
            par[next] = curr;
            if (curr == s) color[next] = next;
            else color[next] = color[curr];
            st.push(next);
        }
 
        // return;
 
        // cnt++;
        // if (cnt == 10) return;
    }
 
    cout << "Impossible";
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
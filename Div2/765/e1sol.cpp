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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    cout << s << "\n";
    // return;

    stack<int> stk;
    int cnt = 0;
    vt<int> p(n), begin(n), end(n);
    vt<vt<int>> c(n);
    int start = 0;
    for0(i, n){
        if (s[i] == '('){
            start = i;
            break;
        }
    }

    int last = 0;
    for0(i, n){
        if (s[i] == ')'){
            last = i;
        }
    }
    for0(i, n){
        if (s[i] == '('){
            cnt++;
            stk.push(cnt);
            begin[i] = cnt;
        }

        else{
            if (stk.empty()) continue;
            int num = stk.top();
            stk.pop();
            int parent;
            if (stk.empty()) parent = 0;
            else parent = stk.top();
            p[num] = parent;
            c[parent].pb(num);
            end[i] = num;
        }
    }   

    for0(i, cnt + 1){
        cout << i << "\n";
        for (int x: c[i]) cout << x << " ";
        cout << "\n";
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
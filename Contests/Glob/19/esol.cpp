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

set<ll> bad;
map<int, int> cnt;

void solve(){
    bad.clear();
    cnt.clear();
    int n, m; cin >> n >> m;
    vt<int> a(n);
    for0(i, n){
        cin >> a[i];
        cnt[a[i]] = 0;
    }

    for0(i, m){
        int x, y;
        cin >> x >> y;
        bad.insert(1ll * x * 1e9 + 1ll * y);
        bad.insert(1ll * y * 1e9 + 1ll * x);
    }
    
    for0(i, n){
        cnt[a[i]]++;
    }

    set<int> consider;
    vt<vt<int>> cnt_cs(n + 1);
    for0(i, n){
        cnt_cs[cnt[a[i]]].pb(a[i]);
        consider.insert(cnt[a[i]]);
    }

    vt<int> cs;
    for (int x: consider) cs.pb(x);

    for (int x: cs){
        sort(cnt_cs[x].begin(), cnt_cs[x].end());
        reverse(cnt_cs[x].begin(), cnt_cs[x].end());
    }

    ll ans = 0;
    for0(i, cs.size()){
        forlr(j, i, cs.size(), 1){
            int s = 0;
            int sz1 = cnt_cs[cs[i]].size(), sz2 = cnt_cs[cs[j]].size();
            stack<pair<int, int>> st;
            st.push({0, 0});
            while (!st.empty()){
                pair<int, int> curr = st.top(); st.pop();
                ll a = curr.first, b = curr.second;
                if (a >= sz1 || b >= sz2) continue;
                ll aa = cnt_cs[cs[i]][a], bb = cnt_cs[cs[j]][b];
                if (aa == bb || bad.find(aa * 1e9 + bb) != bad.end()){
                    st.push({a + 1, b});
                    st.push({a, b + 1});
                }
                else{
                    ans = max(ans, 1ll * (cs[i] + cs[j]) * (aa + bb));
                }
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        solve();
    }
}
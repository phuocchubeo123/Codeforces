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
    int n; 
    cin >> n;
    vt<int> a(n);
    for0(i, n) cin >> a[i];

    vt<int> first(n + 1, n + 1), last(n + 1, -1);
    for0(i, n){
        first[a[i]] = min(first[a[i]], i);
        last[a[i]] = max(last[a[i]], i);
    }

    vt<pair<int, int>> segs;
    for1(i, n){
        if (first[i] != last[i] && first[i] != n + 1 && last[i] != -1) segs.pb({first[i], last[i]});
    }

    sort(segs.begin(), segs.end());

    vt<pair<int, int>> cont;
    vt<vt<pair<int, int>>> cont_seg;
    int l = -1, r = -1;
    int num = -1;
    for (auto p: segs){
        if (p.first > r){
            cont.pb({l, r});
            num++;
            cont_seg.pb({{p.first, p.second}});
            l = p.first;
            r = p.second;
        }

        else{
            r = max(r, p.second);
            cont_seg[num].pb(p);
        }
        cout << p.first << " " << p.second << " " << num << "\n"; 
    }

    cont.pb({l, r});

    for1(i, num + 1){
        cout << cont[i].first << " " << cont[i].second << "\n";
        for (auto x: cont_seg[i - 1]) cout << x.first << " " << x.second << "\n";
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
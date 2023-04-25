#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 4;
int T, n, q, tmp, a[N], p[N], v, l, k, cnt[N], first[N], seq[N], pos[N], ans[N], lb[N];
vector<int> c[N];
vector<tuple<int, int, int>> queries[N];

void read(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= q; i++){
        cin >> v >> l >> k;
        queries[v].push_back(make_tuple(i, l, k));
    }
}

void swap(int pos1, int pos2){
    pos[seq[pos1]] = pos2;
    pos[seq[pos2]] = pos1;
    tmp = seq[pos1];
    seq[pos1] = seq[pos2];
    seq[pos2] = tmp;
}

void answerQuery(int num){
    for (auto Q: queries[num]){
        int i = get<0>(Q), l = get<1>(Q), k = get<2>(Q);
        int beg = lb[l];

        if (beg + k - 1 > n) ans[i] = -1;
        else ans[i] = seq[beg + k - 1];
    }
}

void dfs(int x){
    // cout << x << "\n";
    cnt[a[x]]++;
    lb[cnt[a[x]]]--;
    swap(pos[a[x]], lb[cnt[a[x]]]);

    // cout << x << ":\n";
    // for (int i = 1; i <= n; i++) cout << seq[i] << " ";
    // cout << "\n";
    // for (int i = 1; i <= n; i++) cout << cnt[seq[i]] << " ";
    // cout << "\n";

    answerQuery(x);

    for (int num: c[x]){
        dfs(num);
    }

    swap(pos[a[x]], lb[cnt[a[x]]]);
    lb[cnt[a[x]]]++;
    cnt[a[x]]--;
}

void solve(){
    for (int i = 2; i <= n; i++){
        c[p[i]].push_back(i);
    }

    lb[0] = 1;
    for (int i = 1; i <= n; i++){
        seq[i] = i;
        pos[i] = i;
        cnt[a[i]] = 0;
        lb[i] = n + 1;
    }

    dfs(1);

    for (int i = 1; i <= q; i++) cout << ans[i] << " ";
    cout << "\n";

    for (int i = 1; i <= n; i++) queries[i].clear();
    for (int i = 1; i <= n; i++) c[i].clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T;

void prepare(){

}

int n, l[N], r[N], c[N];

void read(){
    cin >> n;
    for0(i, n) cin >> l[i] >> r[i] >> c[i];
}

int cost(int x, int y){
    if (x == y) return c[x];
    else return c[x] + c[y];
}

int one[N], one_num[N], two[N], two_num[N];

void solve(){
    int b = 0;
    one[0] = c[0];
    for1(i, n - 1){
        if (r[i] - l[i] + 1 > r[b] - l[b] + 1 || (r[i] - l[i] + 1 == r[b] - l[b] + 1 && c[i] <= c[b])) b = i;
        one[i] = c[b];
        one_num[i] = r[b] - l[b] + 1;
    }

    int bl = 0, br = 0;
    two[0] = c[0];
    for1(i, n - 1){
        if (l[i] < l[bl] || (l[i] == l[bl] && c[i] <= c[bl])) bl = i;
        if (r[i] > r[br] || (r[i] == r[br] && c[i] <= c[br])) br = i;
        two[i] = cost(bl, br);
        two_num[i] = r[br] - l[bl] + 1;
    }

    for0(i, n){
        if (one_num[i] == two_num[i]){
            cout << min(one[i], two[i]) << "\n";
        }

        else{
            cout << two[i] << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
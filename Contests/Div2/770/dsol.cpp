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

int query(int x, int y, int z){
    cout << "? " << x << " " << y << " " << z << "\n";
    cout.flush();
    int a;
    cin >> a;
    return a;
}

vt<int> findBest(int x, int y, int z, int t){
    vt<int> qr(4);

    vt<tuple<int, int, int>> corr(4);
    corr[0] = make_tuple(x, y, z);
    corr[1] = make_tuple(x, y, t);
    corr[2] = make_tuple(x, z, t);
    corr[3] = make_tuple(y, z, t);

    for0(j, 4){
        qr[j] = query(get<0>(corr[j]), get<1>(corr[j]), get<2>(corr[j]));
    }

    vt<int> id(4);
    for0(j, 4) id[j] = j;
    sort(id.begin(), id.end(), [&](int x, int y){
        return qr[x] > qr[y];
    });

    int fir = id[0], sec = id[1];
    vt<int> candidates = {x, y, z, t};
    vt<int> new_xy;

    for (int j: candidates){
        int cnt = 0;
        tuple<int, int, int> corr_tuple = corr[fir];
        if (get<0>(corr_tuple) == j) cnt++;
        if (get<1>(corr_tuple) == j) cnt++;
        if (get<2>(corr_tuple) == j) cnt++;

        corr_tuple = corr[sec];
        if (get<0>(corr_tuple) == j) cnt++;
        if (get<1>(corr_tuple) == j) cnt++;
        if (get<2>(corr_tuple) == j) cnt++;

        if (cnt == 2) new_xy.pb(j);
    }

    return new_xy;
}

void solve(){
    int n;
    cin >> n;    

    int x = 1, y = 2;
    forlr(i, 3, n, 2){
        vt<int> n_xy = findBest(x, y, i, i + 1);
        x = n_xy[0];
        y = n_xy[1];
    }

    if (n % 2 == 1){
        int new_n;
        for1(i, n){
            if (i != x && i != y){
                new_n = i;
                break;
            }
        }
        vt<int> n_xy = findBest(x, y, new_n, n);
        x = n_xy[0];
        y = n_xy[1];
    }

    cout << "! " << x << " " << y << "\n";
    cout.flush();
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
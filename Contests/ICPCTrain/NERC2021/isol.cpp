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

int scanXY(int x, int y){
    cout << "SCAN " << x << " " << y << "\n";
    cout.flush();
    int z; cin >> z;
    return z;
}

int dig(int x, int y){
    cout << "DIG " << x << " " << y << "\n";
    cout.flush();
    int z; cin >> z;
    return z;
}

void solve(){
    int n, m;
    cin >> n >> m;
    int s1 = scanXY(1, 1);
    int s2 = scanXY(1, m);
    int abcd = s1 + 4;
    int ac_bd = s2 - 2 * m + 2;
    int ac = (abcd + ac_bd) / 2;
    int bd = abcd - ac;
    // cout << ac << " " << bd << "\n";
    // cout.flush();
    int ac_div_2 = ac / 2;
    int bd_div_2 = bd / 2;
    int s3 = scanXY(ac_div_2, 1);
    int s4 = scanXY(1, bd_div_2);
    int a_c = s3 - bd + 2;
    int b_d = s4 - ac + 2;

    int a = (ac + a_c) / 2;
    int c = ac - a;
    int b = (bd + b_d) / 2;
    int d = bd - b;

    int q1 = dig(a, b);
    if (q1){
        dig(c, d);
        return;
    }

    else{
        dig(a, d);
        dig(c, b);
        return;
    }
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
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4, LOG = 18;
int T, n;
ll s, a[N], st[N][LOG], prefix_sum[N], pow_two[LOG], log_two[N];

void read(){
    cin >> n >> s;
    s = -s;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void calPrefixSum(){
    prefix_sum[0] = 0;

    ll total = 0;
    for (int i = 1; i <= n; i++){
        total += a[i];
        prefix_sum[i] = total;
    }

    // for (int i = 1; i <= n; i++) cout << prefix_sum[i] << " ";
    // cout << "\n";
}

ll get_sum(int l, int r){
    return prefix_sum[r] - prefix_sum[l - 1];
}

void createSparseTable(){
    for (int i = 1; i <= n; i++){
        st[i][0] = get_sum(i, i);
    }

    for (int j = 0; j < LOG - 1; j++){
        for (int i = 1; i + pow_two[j + 1] - 1 <= n; i++){
            st[i][j + 1] = min(st[i][j], get_sum(i, i + pow_two[j] - 1) + st[i + pow_two[j]][j]);
        }
    }

    // for (int i = 1; i <= n; i++) cout << st[i][1] << " ";
    // cout << "\n";
}

ll min_sum(int l, int r){
    int floor_log = log_two[r - l + 1];
    ll l_sum = st[l][floor_log];
    ll r_sum = get_sum(l, r - pow_two[floor_log]) + st[r - pow_two[floor_log] + 1][floor_log];
    return min(l_sum, r_sum);
}

void calPowTwo(){
    pow_two[0] = 1;
    for (int i = 0; i < LOG - 1; i++){
        pow_two[i + 1] = 2 * pow_two[i];
    }
}

void calLogTwo(){
    log_two[1] = 0;
    for (int i = 2; i < N; i++) log_two[i] = 1 + log_two[i / 2];
}

void solve(){
    calLogTwo();
    calPowTwo();
    calPrefixSum();
    createSparseTable(); 

    int pt1 = 1;
    int pt2 = 1;

    int ans = 0, ans_l = 0, ans_r = 0;

    while (pt1 <= n){
        // cout << pt1 << " " << pt2 << " " << min_sum(pt1, pt2) << " done \n";
        if (min_sum(pt1, pt2) >= s){
            if (pt2 - pt1 + 1 > ans){
                ans = pt2 - pt1 + 1;
                ans_l = pt1;
                ans_r = pt2;
            }
            if (pt2 == n) break;
            pt2++;
        }

        else{
            if (pt1 == pt2){
                pt1++; pt2++;
            }

            else{
                pt1++;
            }
        }
    }

    if (ans == 0) cout << -1 << "\n";
    else cout << ans_l << " " << ans_r << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}
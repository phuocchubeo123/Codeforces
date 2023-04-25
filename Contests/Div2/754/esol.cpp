#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int T, n, q;
ll a[N], b[N], x[N], c[N], d[N], is_prime[N], sum_first[N], square_free[N], num_prime_divisor[N], one_coef[N], prefix_sum[N];
ll pre_ans, ans, lower_num, total, change_first, add_ans;
vector<int> need_change;

void testFindPrime(){
    for (int i = 1; i <= 20; i++){
        cout << is_prime[i] << " ";
    }
    cout << "\n";
}

void findPrime(){
    for (int i = 2; i < N; i++) is_prime[i] = 1;

    for (int i = 2; i < N; i++){
        for (int j = 2; j * i < N; j++){
            is_prime[i * j] = 0;
        }
    }
    // testFindPrime();
}

void testFindSquareFree(){
    for (int i = 1; i <= 20; i++) cout << square_free[i] << " ";
    cout << "\n";
}

void findSquareFree(){
    for (int i = 1; i < N; i++) square_free[i] = 1;

    for (int i = 2; i * i < N; i++){
        for (int j = 1; j * i * i < N; j++){
            square_free[i * i * j] = 0;
        }
    }
    // testFindSquareFree();
}

void testFindNumPrimeDivisor(){
    for (int i = 1; i <= 20; i++){
        cout << num_prime_divisor[i] << " ";
    }
    cout << "\n";
}

void findNumPrimeDivisor(){
    num_prime_divisor[1] = 0;
    for (int i = 2; i < N; i++) num_prime_divisor[i] = 0;

    for (int i = 2; i < N; i++){
        if (!is_prime[i]) continue;

        for (int j = 1; j * i < N; j++){
            num_prime_divisor[i * j] += 1;
        }
    }
    // testFindNumPrimeDivisor();
}

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    cin >> q;
    for (int i = 1; i <= q; i++) cin >> x[i];
}

void testNormalize(){
    cout << "c: ";
    for (int i = 1; i <= 20; i++) cout << c[i] << " ";
    cout << "\n";
}

void normalize(){
    for (int i = 1; i <= n; i++) c[i] = b[i] - a[i];
    // testNormalize();
}

int findOneCoef(int i){
    if (i == 1) return 1;

    if (!square_free[i]) return 0;

    if (num_prime_divisor[i] % 2 == 0) return 1;
    return -1;
}

void testFindOneCoefAll(){
    for (int i = 1; i <= 20; i++) cout << one_coef[i] << " ";
    cout << "\n";
}

void findOneCoefAll(){
    for (int i = 1; i < N; i++){
        one_coef[i] = findOneCoef(i);
        // if (i == 3) cout << one_coef[3] << "\n";
    }
    // testFindOneCoefAll();
}

void testFindChange(){
    cout << "pre ans: " << pre_ans << "\n";

    cout << "c after: ";
    for (int i = 1; i <= 20; i++) cout << c[i] << " ";
    cout << "\n";

    cout << "d: ";
    for (int i = 1; i <= 20; i++) cout << d[i] << " ";
    cout << "\n";
}

void findChange(){
    for (int i = 1; i < N; i++){
        for (int j = 2; j * i <= N; j++){
            c[i * j] = c[i * j] - c[i];
        }
    }

    for (int i = 1; i <= n; i++){
        if (one_coef[i] == 0) pre_ans += abs(c[i]);

        else{
            d[i] = c[i] - one_coef[i] * c[1];
            need_change.push_back(-one_coef[i] * d[i]);
        }
    }
    // testFindChange();
}

void testFindPrefixSum(){
    cout << "need change: ";
    for (auto x: need_change) cout << x << ", ";
    cout << "\n";

    for (int i = 0; i <= 20; i++){
        cout << prefix_sum[i] << " ";
    }
    cout << "\n";
}

void findPrefixSum(){
    sort(need_change.begin(), need_change.end());

    total = 0;
    for (int i = 0; i < need_change.size(); i++){
        total = total + need_change[i];
        prefix_sum[i] = total;
    }
    // testFindPrefixSum();
}

ll findLowerBound(int num){
    ll pos = 0;
    ll jump = n;

    while (jump > 0){
        if (pos + jump >= need_change.size()){
            // cout << "jump: " << jump << "\n";
            jump = jump / 2;
            continue;
        }

        if (need_change[pos + jump] > num){
            // cout << "jump: " << jump << "\n";
            jump = jump / 2;
            continue;
        }
        // cout << "after " << need_change[pos + jump] << "\n";
        pos = pos + jump;
    }

    // cout << "lower num: " << need_change[pos] << "\n";
    return pos;
}

ll sumOfAbsolute(int num){
    ll lower_bound = findLowerBound(num);
    // cout << "lower bound: " << lower_bound << "\n";
    ll larger_abs = (lower_bound + 1) * num - prefix_sum[lower_bound];
    ll smaller_abs = (need_change.size() - lower_bound - 1) * num - (total - prefix_sum[lower_bound]);
    return abs(larger_abs) + abs(smaller_abs);
}

void solve(){
    normalize();
    findOneCoefAll();
    findChange();
    findPrefixSum();

    for (int i = 1; i <= q; i++){
        change_first = x[i] - a[1];
        // cout << "change: " << change_first << "\n";
        add_ans = sumOfAbsolute(change_first);
        // cout << "add ans: " << add_ans << "\n";
        cout << pre_ans + add_ans << "\n";
    }
}

int main(){
    // cin >> T;
    T = 1;

    for (int t = 0; t < T; t++){
        findPrime();
        findSquareFree();
        findNumPrimeDivisor();
        read();
        solve();
    }
}
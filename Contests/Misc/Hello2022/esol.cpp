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

int n, m, stu;
ll s[N], a[N], k[N], b[N], g[N];

void read(){
    cin >> n >> m;
    for0(i, n) cin >> a[i];
    int l = 1, r = 1;
    for0(i, m){
        cin >> k[i];
        r += k[i];
        s[i] = 0;

        forlr(j, l, r, 1){
            cin >> b[j];
            s[i] += b[j];
            g[j] = i;
        }

        l = r;
    }

    stu = r - 1;
}

int pos[N], no_change[N], backd[N], ford[N];
ll ns[N], na[N], nk[N];
vector<int> gr;

void solve(){
    gr.clear();
    for0(i, m) gr.push_back(i);    

    // for0(i, m) cout << k[i] << " ";
    // cout << "\n";
    // for0(i, m) cout << s[i] << " ";
    // cout << "\n";
    
    // return;

    sort(gr.begin(), gr.end(), [&](int x, int y){
        return 1ll * s[x] * k[y] < 1ll * s[y] * k[x];
    });
    for0(i, m) pos[gr[i]] = i;
    for1(i, stu) g[i] = pos[g[i]];
    for0(i, m) nk[i] = k[gr[i]];
    for0(i, m) ns[i] = s[gr[i]];
    for0(i, m) na[i] = (ns[i] + nk[i] - 1) / nk[i];

    sort(a, a + n);
    reverse(a, a + n);
    reverse(a, a + m);

    no_change[0] = 0;
    backd[0] = 0;
    ford[0] = 0;

    for0(i, m){
        if (i == 0) no_change[i] = 0;
        else no_change[i] = no_change[i - 1];

        if (a[i] < na[i]) no_change[i]++;
    }

    for0(i, m){
        if (i == 0){
            backd[i] = 0;
            continue;
        }

        backd[i] = backd[i - 1];
        if (a[i] < na[i - 1]) backd[i]++;
    }

    for0(i, m - 1){
        if (i == 0) ford[i] = 0;
        else ford[i] = ford[i - 1];

        if (a[i] < na[i + 1]) ford[i]++;
    }

    // for0(i, m) cout << a[i] << " ";
    // cout << "\n";
    // for0(i, m) cout << na[i] << " ";
    // cout << "\n";
    // for0(i, m) cout << no_change[i] << " ";
    // cout << "\n";
    // for0(i, m) cout << backd[i] << " ";
    // cout << "\n";
    // for0(i, m) cout << ford[i] << " ";
    // cout << "\n";

    for1(i, stu){
        ll new_s = ns[g[i]] - b[i];
        ll new_k = nk[g[i]] - 1;
        ll new_a = (new_s + new_k - 1) / new_k;
        int curr_pos = g[i];
        int l = -1, h = m - 1;

        while (l < h){
            int mid = l + (h - l + 1) / 2;
            if (na[mid] <= new_a) l = mid;
            else h = mid - 1;
        }

        int new_pos;
        if (l == curr_pos || l == curr_pos - 1) new_pos = curr_pos;
        else if (l > curr_pos) new_pos = l;
        else new_pos = l + 1;

        // cout << "\n" << na[curr_pos] << " " << new_a << " " << curr_pos << " " << new_pos << "\n";

        auto rangeSum = [](int arr[N], int x, int y){
            if (x == 0) return arr[y];
            return arr[y] - arr[x - 1];
        };

        // cout << no_change
        int left_pos = min(curr_pos, new_pos), right_pos = max(curr_pos, new_pos);
        if (rangeSum(no_change, 0, m - 1) - rangeSum(no_change, left_pos, right_pos) > 0){
            cout << 0;
            continue;
        }
        
        if (a[new_pos] < new_a){
            cout << 0;
            continue;
        }

        if (new_pos == curr_pos){
            cout << 1;
        }

        else if (new_pos < curr_pos){
            if (rangeSum(backd, new_pos + 1, curr_pos) > 0) cout << 0;
            else cout << 1;
        }

        else{
            if (rangeSum(ford, curr_pos, new_pos - 1) > 0) cout << 0;
            else cout << 1;
        }
    }

    cout << "\n";
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
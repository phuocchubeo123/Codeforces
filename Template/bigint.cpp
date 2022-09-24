#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4, MOD = 998244353, BASE = 10;

struct bigInt{
    vt<short> val;
    bigInt(){
    }

    bigInt(vt<short> x){
        for0(i, x.size()){
            val.pb(x[i]);
        }
    }

    bigInt(string s){
        for0(i, s.length()){
            val.pb(s[i] - '0');
        }
    }

    friend istream &operator>>(istream &, bigInt &);
    friend ostream &operator<<(ostream &, bigInt &);

    bool operator==(const bigInt &other){
        int n = val.size(), m = other.val.size();
        if (n != m) return false;
        for0(i, n){
            if (val[i] != other.val[i]) return false;
        }
        return true;
    }

    bool operator<(const bigInt &other){
        int n = val.size(), m = other.val.size();
        if (n < m) return true;
        if (n > m) return false;
        for0(i, n){
            if (val[i] < other.val[i]) return true;
            if (val[i] > other.val[i]) return false;
        }
        return false;
    }


    friend bigInt operator+(const bigInt &, const bigInt &);
    friend bigInt operator-(const bigInt &, const bigInt &);   
    friend bigInt operator*(const bigInt &, const bigInt &);
};

istream &operator>>(istream &cin, bigInt &x){
    string s;
    cin >> s;
    for0(i, s.length()) x.val.pb(s[i] - '0');
    return cin;
}

ostream &operator<<(ostream& cout, bigInt &x){
    for0(i, x.val.size()) cout << x.val[i];
    return cout;
}

void insert_zeros(vt<short> &x, int new_size){
    while (x.size() < new_size) x.pb(0);
}

void remove_zeros(vt<short> &x){
    while (x.back() == 0) x.pop_back();
}

void remove_residual(vt<short> &x){
    int residual = 0;
    for0(i, x.size()){
        x[i] += residual;
        residual = (x[i] >= 0)? (x[i] / BASE): ((x[i] + 1) / BASE - 1);
        x[i] = (x[i] >= 0) ? (x[i] % BASE): (BASE + x[i] % BASE);
    }

    while (residual != 0){
        x.pb((residual >= 0)? (residual % BASE): (BASE - residual % BASE));
        residual = (residual >= 0)? (residual / BASE): ((residual + 1) / BASE - 1);
    }
}

bigInt operator+(const bigInt& a, const bigInt& b){
    vt<short> res, x = a.val, y = b.val;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int max_size = max(x.size(), y.size());

    insert_zeros(x, max_size); insert_zeros(y, max_size);

    for0(i, max_size){
        res.pb(x[i] + y[i]);
    }

    remove_residual(res);
    reverse(res.begin(), res.end());
    return bigInt(res);
}

bigInt operator-(const bigInt& a, const bigInt& b){
    // only works when a > b 
    vt<short> res, x = a.val, y = b.val;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int max_size = max(x.size(), y.size());

    insert_zeros(x, max_size); insert_zeros(y, max_size);

    for0(i, max_size){
        res.pb(x[i] - y[i]);
    }

    remove_residual(res);
    remove_zeros(res);
    reverse(res.begin(), res.end());
    return bigInt(res);
}

bigInt operator*(const bigInt& a, const bigInt& b){
    vt<short> x = a.val, y = b.val;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int n = x.size(), m = y.size();
    int max_size = n + m;
    vt<short> res(max_size, 0);

    for0(i, x.size()){
        for0(j, y.size()){
            res[i+j] += x[i] * y[j];
        }
    }

    remove_residual(res);
    remove_zeros(res);
    reverse(res.begin(), res.end());
    return bigInt(res);
}



int main(){
    bigInt x("15"), y("17");
    bigInt z = x+y, k = y - x, q = x * y;
    bool t = (x < y);
    cout << z << "\n";
    cout << t << "\n";
    cout << k << "\n";
    cout << q << "\n";
}
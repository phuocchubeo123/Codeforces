#include<bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxn = 2005;

double f[maxn];
double x[maxn], y[maxn];
bool flag;

double coss[maxn], sinn[maxn];

int u[maxn], v[maxn];

double PI = 3.14159265358979;

pair<int, int> merge(int x1, int y1, int x2, int y2){
    if (x1 > y2 || y1 < x2){
        flag = false;
        return {0, 0};
    }
    return {max(x1, x2), min(y1, y2)};
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> f[i];

    for (int i = 0; i < n; i++){
        coss[i] = cos(-2 * PI * (double) i / (double) n);
        sinn[i] = sin(-2 * PI * (double) i / (double) n);
    }


    for (int t = 0; t < n; t++){
        double Fr = 0, Fi = 0;
        for (int s = 0; s < n; s++){
            if (s == k) continue;
            Fr += f[s] * coss[(s * t) % n];
            Fi += f[s] * sinn[(s * t) % n];
        }

        double a = 2 * coss[(k * t) % n] * Fr;
        double b = 2 * sinn[(k * t) % n] * Fi;

        x[(int)t] = a + b;
        y[(int)t] = Fr * Fr + Fi * Fi;
    }

    // for (int t = 0; t < n; t++) cout << x[t] << " ";
    // cout << "\n";
    // for (int t = 0; t < n; t++) cout << y[t] << " ";
    // cout << "\n";

    double l = 0, r = 10e14;
    double m;

    while (r - l > 0.000000001){
        double m0 = (l + r) / 2;
        m = m0 * m0;
        // cout << l << " " << r << " " << m << "\n";
        flag = true;

        for (int t = 0; t < n; t++){
            if (m + (x[t] * x[t]) / 4 - y[t] < 0){
                flag = false;
                break;
            }
            u[t] = ceil(-sqrt(m + (x[t] * x[t]) / 4 - y[t]) - x[t] / 2);
            v[t] = floor(sqrt(m + (x[t] * x[t]) / 4 - y[t]) - x[t] / 2);
        }

        int x1 = u[0], y1 = v[0];

        for (int t = 1; t < n; t++){
            pair<int, int> p = merge(x1, y1, u[t], v[t]);
            if (!flag) break;
            x1 = p.first;
            y1 = p.second;
        }

        if (flag) r = m0;
        else l = m0;
    }

    cout << fixed << setprecision(10);
    cout << l << "\n";
}
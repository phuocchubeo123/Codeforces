#include<bits/stdc++.h>

#define ll long long

using namespace std;

struct pt{
    double x, y, z;

    pt(){}
    pt(double nx, double ny, double nz): x(nx), y(ny), z(nz){}

    bool operator==(const pt& a){
        return (x == a.x && y == a.y && z == a.z);
    }

    pt operator-(const pt& a){
        return pt(x-a.x, y-a.y, z-a.z);
    }

};

pt normalize(pt u){
    double dist = sqrt(u.x*u.x + u.y*u.y + u.z*u.z);
    if (u.x/dist < 0) return pt(-u.x/dist, -u.y/dist, -u.z/dist);
    return pt(u.x/dist, u.y/dist, u.z/dist);
}

pt cross_product(pt u, pt v){
    double x = u.y * v.z - u.z * v.y;
    double y = u.z * v.x - u.x * v.z;
    double z = u.x * v.y - u.y * v.x;
    return pt(x, y, z);
}

void solve(){
    int n; cin >> n;
    double x[n], y[n], z[n], a[n], b[n], c[n];
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i] >> a[i] >> b[i] >> c[i];

    vector<pt> ps;
    for (int i = 0; i < n; i++){
        ps.push_back(pt(x[i], y[i], z[i]));
        ps.push_back(pt(a[i], b[i], c[i]));
    }

    int m = 2*n;
    int ans = 0;
    for (int i = 0; i < m; i++){
        pt u = ps[i];
        for (int j = i+1; j < m; j++){
            pt v = ps[j];
            for (int k = j+1; k < m; k++){
                pt w = ps[k];
                if (u == v || v == w || w == u) continue;
                pt a1 = u - v;
                pt a2 = u - w;
                if (normalize(a1) == normalize(a2)) continue;
                pt cp = cross_product(a1, a2);

                int ans2 = 0;
                for (int _ = 0; _ < n; _++){
                    pt p1(x[_], y[_], z[_]), p2(a[_], b[_], c[_]);                  
                    if (p1 == u || p1 == v || p1 == w){ ans2++; continue;}
                    if (p2 == u || p2 == v || p2 == w){ ans2++; continue;}
                    // double np1;
                    // if (normalize(p1 - u) == normalize(cp)) np1 = (p1-u).x / cp.x;
                    // else{
                    // }
                    double np1 = cp.x * (p1.x - u.x) + cp.y * (p1.y - u.y) + cp.z * (p1.z - u.z);
                    double np2 = cp.x * (p2.x - u.x) + cp.y * (p2.y - u.y) + cp.z * (p2.z - u.z);

                    if (np1 * np2 <= 0) ans2++;
                }

                ans = max(ans, ans2);
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T a, T b){while(b){b^=a^=b^=a%=b;} return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;

struct point{
    double x, y;
    point(double _x, double _y) : x(_x), y(_y) {};
}

struct vec{
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {};
}

double cross(const vec& a, const vec& b){
    return (a.x * b.y - a.y * b.x);
}

vec toVec(const point& p, const point& q){
    return vec(q.x - p.x, q.y - p.y);
}

double dist(const point& a, const point& b){
    return hypot(b.x - a.x, b.y - a.y);
}

// check if left cross > 0
bool ccw(const point& p, const point& q, const point& r){
    return cross(toVec(p, q),toVec(p, r)) > 0;
}

double dot(vec a, vec b){
    return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v){
    return v.x * v.x + v.y * v.y;
}

double angle(const point& a, const point& o, const point& b){
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob)) / sqrt(norm_sq(oa) * norm_sq(ob));
}

// Premeter of a Polygon
double perimeter(const vector<point> &P) {
    double result = 0.0;
    for(int i = 0; i < (int)P.size() - 1; i++){
        result += dist(P[i], P[i+1]);
    }
    return result;
}

double area(const vector<ponint> &P){
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size() - 1; i++){
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}

bool isConvex(const vector<point> &P){
    int sz = (int)P.size();
    if(sz <= 3) return false;
    bool isleft = ccw(P[0], P[1], P[2]);
    for (int i = 1; i < sz - 1; i++){
        if(ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isleft){
            return false;
        }
    }
    return true;
}

// Checking if a Point is Inside a Polygon
bool inPolygon(const point& pt, const vector<point> &P){
    if((int)P.size() == 0) return false;
    double sum = 0;
    for (int i = 0; i < (int)P.size() - 1; ++i){
        if(ccw(pt, P[i], P[i+1])){
            sum += angle(P[i], pt, P[i+1]);
        } else {
            sum -= angle(P[i], pt, P[i+1]);
        }
    }
    return fabs(fabs(sum) - 2*PI) < EPS;
}

point pivot(0, 0);
bool angleCmp(const point &a, const point &b){
    if(collinear(pivot, a, b))
        return dist(pivot, a) < dist(pivot, b);
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return atan2(d1y, d1x) - atan(d2y, d2x) < 0;
}

vector<point> CH(vector<point> &P){
    int i, j, n = (int)P.size();
    if(n <= 3){
        if(!(P[0] == P[n-1])) P.push_back(P[0]);
        return P;
    }

    // First, find p = point with lowest Y and if tie: rightmost X
    int p = 0;
    for (int i = 1; i < n; i++){
        if(P[i].y < P[p].y || (P[i].y == P[p].y && P[i].x > P[p].x)){
            p = i;
        }
    }
    swap(P[p], P[0]);
    // second, sort points by angle w.r.t pivot PO
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    // This algorithm maintains a stack S of candidate points
    // Each point of P is pushed once on to S and points thtat 
    // are not going to be part of CH(P) will be eventually
    // popped from S. Gramha's Scan maintains this invariant 
    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
    i = 2;
    while (i < n){
        j = (int)S.size() - 1;
        // Check if can push P[i] or not, if not means that S[j] 
        // can not be in stack -> pop_back
        if(ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
        else S.pop_back();
    }
    return S;
}

void solve(){
    vector<point> Poly;
    P.push_back(point(1, 1)); // P0
    P.push_back(point(3, 3)); // P1
    P.push_back(point(9, 1)); // P2 
    P.push_back(point(12, 4)); // P3 
    P.push_back(point(9, 7)); // P4 
    P.push_back(point(1, 7)); // P5 
    P.push_back(P[0]); // important: loop back

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}


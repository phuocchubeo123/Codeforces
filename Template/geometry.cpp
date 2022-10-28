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

struct point {
    double x, y; 
    point() { x = y == 0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator <(const point& other) const {
        if(fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y
    }
    bool operator ==(const point& other) const {
        return ((fabs(x-other.x) < EPS) && (fabs(y-other.y) < EPS));
    }
};

double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

// Torate a point by angle \theta
point rotate(point p, double theta){
    double rad = DEG_to_RED(theta);
    return point(p*x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

struct line { double a, b, c; };

void pointsToLine(point p1, point p2, line &l){
    if(fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2){
    return (fabs(l1.a - l2.a) < EPS && (fabs(l1.b-l2.b) < EPS));
}

bool areSame(line l1, line l2) {
    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}


// returns true (+ intersection point) of two lines are intersect
bool areIntersect(line l1, line l2, point &p){
    if(areParallel(l1, l2)) return false;
    // solve system of 2 linear algebraic euqations with 2 unkowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // Special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS){
        p.y = -(l1.a * p.x + l1.c);
    } else {
        p.y = -(l2.a * p.x + l2.c);
    }
    return true;
}

struct vec {
    double x, y; 
    vec(double _x, double _y) : x(_x), y(_y) {}

    vec operator+(const vec& v) const {
        return vec(x + v.x, y + v.y);
    }

    vec operator-(const vec& v) const {
        return vec(x - v.x, y - v.y);
    }

    double cross(const vec& v){
        return x * v.y - y * v.x;
    }
};

vec toVec(const point& p){
    return vec(p.x, p.y);
}

vec toVec(const point& a, const point& b){
    return vec(b.x - a.x, b.y - a.y);
}

point translate(point p, vec v){
    return point(p.x + v.x, p.y + v.y);
}

bool ccw(point p, point q, point r){
    return cross(toVec(p, q), toVec(q, r)) > 0;
}

bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(q, r))) < EPS;
}

void solve(){
    // In order to test if double a == double b
    // We test fabs(a - b) < EPS, EPS = 1e9

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}


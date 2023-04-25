#include<bits/stdc++.h>
#include<limits.h>
 
#define f first
#define s second
# define M_PI           3.14159265358979323846
using namespace std;
using ll = long long;
 
struct tuple {ll x; ll y; ll z;};
 
ll inf = LONG_MAX;
 
ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}
 
ll power(ll base, ll powerRaised)
{
    if (powerRaised != 0)
        return (base*power(base, powerRaised-1));
    else
        return 1;
}
 
ll findTheStriclyLessPower(ll base, ll n){
    if(n == 1){
        return 0;
    }
    ll temp = log(n)/log(base);
    if(power(base, temp) == n){
        return temp - 1;
    } else {
        return temp;
    }
}
 
ll gcd(ll x, ll y){
    ll ans = x;
    ll temp = y;
    while(ans != temp){
        if(ans < temp){ 
            temp -= ans;
        } else{
            ans -= temp;
        }
    }
    return ans;
}
 
ll lcm(ll x, ll y){
    return x*y/gcd(x, y);
}
 
void solve(){
}

int n, p;
vector<pair<ll, ll>> points, points_without_max_x;
ll x, y;
pair<ll, ll> new_point;
pair<ll, ll> max_x = make_pair(0, 0);
ll double_total_area;

bool higher(pair<ll, ll> point_a, pair<ll, ll> point_b){
    if (point_a.first >= point_b.first) return true;

    return false;
}

float normalize_y(pair<ll, ll> point_a, pair<ll, ll> point_b){
    ll x_dif = point_a.first - point_b.first;
    ll y_dif = point_a.second - point_b.second;

    float length = (float) sqrt(x_dif * x_dif + y_dif * y_dif);
    return (float) y_dif / length;
}

bool lefter(pair<ll, ll> point_a, pair<ll, ll> point_b){
    return (normalize_y(point_a, max_x) < normalize_y(point_b, max_x));  
}

bool different(pair<ll, ll> point_a, pair<ll, ll> point_b){
    return (point_a.first != point_b.first || point_a.second != point_b.second);
}

ll shoelace(){
    ll double_area = 0;
    for (int i=0;i<p-1;i++){
        double_area += points[i].first * points[i+1].second;
    }

    for (int i=0;i<p-1;i++){
        double_area -= points[i].second * points[i+1].first;
    }

    double_area += points[p-1].first * points[0].second;
    double_area -= points[p-1].second * points[0].first;

    return abs(double_area);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int tt=0;tt<n;tt++){
        cin >> p;
        points.clear(); points_without_max_x.clear(); max_x = make_pair(0,0);
        for (int pp=0;pp<p;pp++){
            cin >> x >> y;
            new_point = make_pair(x, y);
            points.push_back(make_pair(x, y));

            if (higher(new_point, max_x)){
                max_x = new_point;
            }
        }

        for (pair<ll, ll> pt: points) if (different(pt, max_x)) points_without_max_x.push_back(pt);

        // sort(points_without_max_x.begin(), points_without_max_x.end(), lefter);

        points_without_max_x.push_back(max_x);

        // for (pair<ll, ll> pt:points_without_max_x) cout << pt.first << " " << pt.second << "\n";

        double_total_area += shoelace();
    }   

    cout << floor((float) double_total_area / 2);
}
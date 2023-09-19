#include<bits/stdc++.h>
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
typedef pair<ll,ll> pll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define fi first
#define se second
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))
//mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<ll> rnd(0,LLONG_MAX);
template<typename T>
inline T cei(T x, T y) {
	T t = (x+y-1)/y;
	return t;
}

template<typename T>
inline T power(T base, T powerRaised) {
	if (powerRaised != 0) return (base*power(base, powerRaised-1));
	else return 1;
}

template<typename T>
inline T gcd(T a, T b) {
	while(b) {
		b^=a^=b^=a%=b;
	}
	return a;
}

template<typename T>
inline T lcm(T x, T y ) {
	return x*y/gcd(x,y);
}
template<typename T>
inline T findLessPower(T base, T n) {
	if(n==1) {
		return 0;
	}
	T temp = log(n)/log(base);
	if(power(base, temp) == n) {
		return temp-1;
	} else {
		return temp;
	}
}
const ll mod1=1e9+7;
const ll mod2=1e9+9;
const ll INF=1e9+5;
const ll maxN=1e6+5;
const ll MAXLEN=1e6+5;
//ll gcdl(ll a,ll b) {
//	if(a==0||b==0) {
//		return abs(a+b);
//	}
//	return gcdl(b%a,a);
//}
//ll lcml(ll a,ll b) {
//	if(a>=INF||b>=INF) {
//		return INF;
//	}
//	ll ans=a*b/gcdl(a,b);
//	if(ans>=INF) {
//		return INF;
//	}
//	return ans;
//}
//ll mo(ll a,ll b,ll mod) {
//	if(b==0) {
//		return 1ll;
//	}
//	ll vmod;
//	vmod=mo(a,b/2,mod);
//	vmod=(vmod*vmod)%mod;
//	if(b%2==0) {
//		return vmod;
//	}
//	return (vmod*a)%mod;
//} 
void solve() {
	ll n,m,i,j,k;
	ll a[n+2][n+2];
	cin >> n;
	if(n==1){
		cout << ".\n";
		return;
	}
	char x[n+1][n+1];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			x[i][j]='.';
		}
	}
	if(n%6==0){
		// case7
		for(i=8;i<=n;i+=2){
			for(j=1;j<=n-3;j+=3){
				x[i][j]='#';
				x[i][j+1]='#';
			}
		}
		for(j=n-2;j<=n;j+=2){
			for(i=8;i<=n;i+=3){
				x[i][j]='#';
				x[i+1][j]='#';
			}
		}
		for(j=8;j<=n;j+=3){
			x[3][j]='#';
			x[3][j+1]='#';
			x[5][j]='#';
			x[5][j+1]='#';
		}
		for(j=8;j<=n;j+=2){
			x[1][j]='#';
			x[2][j]='#';
		}
		x[1][1]='#';x[1][2]='#';
		x[3][1]='#';x[3][2]='#';
		x[5][1]='#';x[6][1]='#';
		x[5][3]='#';x[6][3]='#';
		
		x[1][4]='#';x[2][4]='#';
		x[1][6]='#';x[2][6]='#';
		
		x[4][5]='#';x[4][6]='#';
		x[6][5]='#';x[6][6]='#';
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				cout << x[i][j];
			}
			cout << "\n";
		}
		return;
	}
	if(n%6==1){
		for(i=3;i<=n;i+=3){
			for(j=1;j<=n;j+=2){
				x[i][j]='#';
				x[i+1][j]='#';
			}
		}
		for(j=3;j<=n;j+=3){
			x[1][j]='#';
			x[1][j+1]='#';
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				cout << x[i][j];
			}
			cout << "\n";
		}
		return;
	}
	if(n%6==2){
		x[1][1]='#';
		x[2][1]='#';
		for(i=4;i<=n;i+=2){
			for(j=1;j<=n;j+=3){
				x[i][j]='#';
				x[i][j+1]='#';
			}
		}
		for(j=4;j<=n;j+=2){
			x[1][j]='#';
			x[2][j]='#';
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				cout << x[i][j];
			}
			cout << "\n";
		}
		return;
	}
	if(n%6==3){
		x[1][1]='#';
		x[2][1]='#';
		x[1][3]='#';
		x[2][3]='#';
		for(i=5;i<=n;i+=3){
			for(j=1;j<=n;j+=2){
				x[i][j]='#';
				x[i+1][j]='#';
			}
		}
		for(j=5;j<=n;j+=3){
			x[1][j]='#';
			x[1][j+1]='#';
			x[3][j]='#';
			x[3][j+1]='#';
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				cout << x[i][j];
			}
			cout << "\n";
		}
		return;
	}
	if(n%6==4){
		x[1][1]='#';x[2][1]='#';
		x[1][3]='#';x[1][4]='#';
		x[4][1]='#';x[4][2]='#';
		x[3][4]='#';x[4][4]='#';
		
		for(i=6;i<=n;i+=3){
			for(j=1;j<n-1;j+=2){
				x[i][j]='#';
				x[i+1][j]='#';
			}
		}
		for(i=6;i<=n;i+=2){
			x[i][n-1]='#';
			x[i][n]='#';
		}
		for(j=6;j<=n;j+=2){
			x[1][j]='#';x[2][j]='#';
		}
		for(j=6;j<=n;j+=3){
			x[4][j]='#';x[5][j]='#';
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				cout << x[i][j];
			}
			cout << "\n";
		}
		return;
	}
	if(n%6==5){
		for(i=1;i<=n;i+=2){
			for(j=1;j<=n;j+=3){
				x[i][j]='#';
				x[i][j+1]='#';
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				cout << x[i][j];
			}
			cout << "\n";
		}
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c,i,j;
	c=1;
	cin >> c;
    cout << 5 << "\n";
    return 0;
	while(c--) {
		solve();
	}
}
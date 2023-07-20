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

typedef int ll;
typedef vector<int> vi;
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

const ll maxn = 4e3 + 5;
const ll MOD = 1e9 + 7; // 998244353
//const ll INF = 1e9;
ll cnt[26],n,k;
bool check(ll prev,ll num){
	if(num>=k){
		return false;
	}
	if(prev!=-1){
		ll x=(cnt[prev]+num-1)/(k-1);
		x--;
		if(x+cnt[prev]>=n){
			return false;
		}
	}
	ll mx=0;
	for(ll i=0;i<26;i++){
		mx=max(cnt[i],mx);
	}
	ll x=(mx-1)/(k-1);
	x--;
	if(x+mx>=n){
		return false;
	}
	return true;
}
ll mi(ll prev,ll num){
	for(ll i=0;i<26;i++){
	    if(cnt[i]<=0){
	        continue;
	    }
	    cnt[i]--;
		if(i==prev&&check(prev,num+1)){
			cnt[i]++;
			return i;
		}
		if(i!=prev&&check(i,1)){
			cnt[i]++;
			return i;
		}
		cnt[i]++;
	}
	return 26;
}
void solve(){
   	ll i,j;
   	string s;
   	cin >> s;
   	n=s.size();
   	cin >> k;
   	for(j=0;j<26;j++){
		cnt[j]=0;
	}
   	for(i=0;i<n;i++){
		cnt[s[i]-'a']++;   
	}
	if(k==1){
		cout << "OH NO!\n";
		return;
	}
	if(!check(-1,0)){
		cout << "OH NO!\n";
		return;
	}
	ll prev,num;
	prev=-1;
	num=0;
	while(n>0){
		i=mi(prev,num);
		cout << char(i+'a');
		if(i==prev){
			num++;
		}
		else{
			prev=i;
			num=1;
		}
		n--;
		//cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << " "<< cnt[3] << "\n";
		cnt[i]--;
	}
	cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    string s;
    tc=1;
    cin >> tc;
	while(tc--){
        solve();
    }
}

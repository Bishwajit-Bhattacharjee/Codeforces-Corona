#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

double INF = 1e100;
double EPS = 1e-12;
typedef long long int ll;

typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define F first
#define S second


ostream& operator<<(ostream & os, PLL h){
	return os << "( " << h.F << ", " << h.S << " )" << endl;

}
PLL operator+ (PLL a, ll x)     {return {a.F + x, a.S + x} ;}
PLL operator- (PLL a, ll x)     {return {a.F - x, a.S - x} ;}
PLL operator* (PLL a, ll x)     {return {a.F * x, a.S * x} ;}
PLL operator+(PLL x, PLL y) { return {x.F + y.F,x.S + y.S} ;}
PLL operator-(PLL x,PLL y) { return {x.F - y.F, x.S - y.S} ;}
PLL operator*(PLL x,PLL y) { return {x.F * y.F , x.S * y.S} ;}
PLL operator%(PLL x,PLL y) { return {x.F % y.F, x.S % y.S} ;}


ll const MOD = 1e9 + 7;

ll bigmod(ll a, ll b){
	if(!b) return 1;
	ll x  = bigmod(a,b/2);

	x = (x * x)%MOD;
	if(b&1)
		x = (x * a) %MOD;
	return x;
}

vector < ll > primes;
vector < bool > marks;

void sieve(int n)
{
    marks.resize(n+10,0);
	marks[1] = 1;
	for(int i = 2; i < n; i++){
		if(!marks[i]){
			for(int j = 2*i; j < n; j += i){
				marks[j] = 1;
			}
			primes.push_back(i);
		}
	}
}
int const N = 5e5 + 10;
vector<int> g[N] ;
int giv[N];
int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	int n,m;
	cin >> n >> m ;
	memset(giv,-1,sizeof giv);

	for(int i = 0;i < m; i++){
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<PII> topic;

	vector<int> ord;

	for(int i = 0;i < n; i++){
		int tmp;
		cin >> tmp;
		topic.emplace_back(tmp,i+1);
	}
	sort(topic.begin(),topic.end());

	for(auto x : topic){
		int cur_t = x.F;
		int cur_node = x.S;

		set < int > s;

		for(auto v : g[cur_node]){

			if(giv[v] == cur_t){
				cout << "-1" << endl;
				return 0;
			}

			if(giv[v] != -1 and giv[v] < cur_t){
				s.insert(giv[v]);
			}
		}
		if(s.size() + 1 != cur_t){
			cout << "-1" << endl;
			return 0;
		}

		giv[cur_node] = cur_t;
		ord.push_back(cur_node);
	}

	assert(ord.size() == n);

	for(auto x : ord) cout << x << " ";
	cout << endl;
	
	return 0;
}
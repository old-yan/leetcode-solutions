#pragma once
#include "ListNode.h"
#include "TreeNode.h"
using namespace std;


typedef long long ll;
using vi = vector<int>;
using vvi = vector<vector<int>>;
template <class T1, class T2>
using mmap = multimap<T1, T2>;
template <class T>
using mset = multiset<T>;
template <class T>
using pq = priority_queue<T>;
//using Graph = vector<vector<ll>>;

#define EPS (1e-7)
#define INF (1e9)
#define INFLL (9223372036854775807LL)
#define PI (acos(-1))
#define MOD 1000000007LL


#define REP(i, n) for (size_t i = 0; i < n; i++)
#define REPR(i, n) for (size_t i = n; i >= 0; i--)
#define FOR(i, m, n) for (size_t i = m; i < n; i++)
#define FORR(i, m, n) for (size_t i = m; i >= n; i--)
#define DBG(a) cout << #a << " : " << a << "\n";
#define DBGV(a) cout << #a << " : ";for(auto b:a)cout << b << ' ';cout << endl;
#define DBGL(a) cout << #a;for(auto b=a;b;b=b->next)cout<<' '<<b->val;cout<<endl;
#define ALL(v) v.begin(), v.end()

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define FST first
#define SND second


//取最大取最小
template <class T>
bool chmax(T& a, const T& b)
{
	if (a < b)
	{
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
bool chmin(T& a, const T& b)
{
	if (b < a)
	{
		a = b;
		return 1;
	}
	return 0;
}
ListNode* makelistnode(vector<int>v) {
	if (v.empty())return nullptr;
	ListNode* p = new ListNode(-1);
	ListNode* q = p;
	for (int b : v) {
		q->next = new ListNode(b);
		q = q->next;
	}
	return p->next;
}

//图问题，二维矩阵问题
const int di[] = { 0,-1,0,1 };
const int dj[] = { 1,0,-1,0 };

// 数字转字符串
string i2s(ll x){
	if(!x)return "0";
	if(x<0)return "-"+i2s(-x);
	char c[20]={0};
	int idx=0;
	while(x){
		c[idx++]='0'+x%10;
		x/=10;
	}
	reverse(c,c+idx);
	return c;
}
string i2s(ll x,int radix){
	if(!x)return "0";
	if(x<0)return "-"+i2s(-x,radix);
	char c[64]={0};
	int idx=0;
	while(x){
		c[idx++]='0'+x%radix;
		x/=radix;
	}
	reverse(c,c+idx);
	return c;
}

// 字符串转数字
ll s2i(string s){
	int signal=1,idx=0;
	ll val=0;
	if(s[0]=='-'){
		signal=-1;
		idx++;
	}
	while(idx<s.size()){
		val=val*10+s[idx++]-'0';
	}
	return signal*val;
}
ll s2i(string s,int radix){
	int signal=1,idx=0;
	ll val=0;
	if(s[0]=='-'){
		signal=-1;
		idx++;
	}
	while(idx<s.size()){
		val=val*radix+s[idx++]-'0';
	}
	return signal*val;
}


//二分搜索
ll bs(vector<ll>& v)
{
	int low = 0;
	int high = v.size();
	while (low<high)
	{
		int mid = (high + low) / 2;
		if (true)
			high = mid;
		else
			low = mid+1;
	}
	return low;
}


//最大公约数
ll gcd(ll a, ll b)
{
	a = abs(a);
	b = abs(b);
	if (a < b)swap(a, b);
	while (b)
	{
		ll temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

//最小公倍数
ll lcm(ll a, ll b)
{
	ll _gcd = gcd(a, b);
	return a / _gcd * b;
}

//判质
bool isprime(ll n)
{
	if(n<2)return false;
	if(n==2)return true;
	if(n%2==0)return false;
	for(int i=3;i<=sqrt(n);i+=2)if(n%i==0)return false;
	return true;
}

//前缀和
vector<ll> presum(vector<ll>&a)
{
	vector<ll> v(a.size() + 1);
	v[0] = 0;
	REP(i, a.size())v[i + 1] = v[i] + a[i];
	return v;
}

//链表转数组
vector<ListNode*> listtoarr(ListNode* p) {
	vector<ListNode*>v;
	while (p) {
		v.pb(p);
		p = p->next;
	}
	return v;
}
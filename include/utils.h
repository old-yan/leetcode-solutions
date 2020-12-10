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


//图问题，二维矩阵问题
const int di[] = { 0,-1,0,1 };
const int dj[] = { 1,0,-1,0 };


//二分搜索
bool isOK(vector<ll>& v, int index, int key, bool flag)
{
	if (flag) {

		if (v[index] >= key)
			return true;
		else
			return false;
	}
	else {
		if (v[index] > key)
			return true;
		else
			return false;
	}
}

ll bs(vector<ll>& v, ll key, bool flag)
{
	int ng = -1;	//「index = 0」が条件を満たすこともあるので、初期値は -1
	int ok = v.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

	/* ok と ng のどちらが大きいかわからないことを考慮 */
	while (abs(ok - ng) > 1)
	{
		int mid = (ok + ng) / 2;

		if (isOK(v, mid, key, flag))
			ok = mid;
		else
			ng = mid;
	}
	return ok;
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
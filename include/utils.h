#pragma once
#include <iostream>
#include <memory.h>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
// 头文件太多会拖慢编译速度，平时没有必要都include进来，可以include常用的，或者在主文件再include
// #include "ListNode.h"
// #include "TreeNode.h"
// #include "NextNode.h"
// #include "Graph.h"
// #include "RandomNode.h"
// #include "Union.h"
// #include "Trie.h"
// #include "zkwTree.h"
// #include "NestedInteger.h"
// #include "QuadTree.h"
// #include "MultiTreeNode.h"
// #include "DuLinkList.h"
// # include "Fraction.h"
using namespace std;
#define LOCAL_DEBUG

typedef long long ll;
using vi = vector<int>;
using vvi = vector<vector<int>>;
//using Graph = vector<vector<ll>>;
#define EPS (1e-7)
#define PI (acos(-1))
#define MOD 1000000007LL
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#ifdef LOCAL_DEBUG
#define DBGVV(a) cout << #a << " : \n";for(ll i=0;i<a.size();i++){DBG(i)DBGV(a[i])};
#define DBGV(a) cout << #a << " : ";for(auto b:a)cout << b << ' ';cout << endl;
#define DBG(a) cout << #a << " : " << a << endl;
#define DBGL(a) cout << #a;for(auto b=a;b;b=b->next)cout<<' '<<b->val;cout<<endl;
#define DBGT(a) cout << #a << " : \n" << a << endl;
#define DBGN(a) cout << #a << " : \n" << a << endl;
#else
#define DBGVV(a)
#define DBGV(a)
#define DBG(a)
#define DBGL(a)
#define DBGT(a)
#define DBGN(a)
#endif
#define ALL(v) v.begin(), v.end()
#define pb push_back

// 取最大
template <class T>
bool chmax(T& a, const T& b){
	if (a < b){
		a = b;
		return 1;
	}
	else return 0;
}
// 取最小
template <class T>
bool chmin(T& a, const T& b){
	if (b < a){
		a = b;
		return 1;
	}
	else return 0;
}

// 从整数数组构造链表
#ifdef OLDYAN_LISTNODE
ListNode* makelistnode(const vi&v) {
	if (v.empty())return nullptr;
	ListNode* p = new ListNode(-1);
	ListNode* q = p;
	for (int b : v) {
		q->next = new ListNode(b);
		q = q->next;
	}
	return p->next;
}
#endif

// 从字符串构造整形嵌套列表
#ifdef OLDYAN_NESTEDINTEGER
NestedInteger makenestedinteger(const string&s){
	stack<vector<NestedInteger>*>S;
	bool hasnumber=false,minus=false;
	int val=0;
	vector<NestedInteger>*last=nullptr;
	for(char c:s){
		if(c=='['){
			S.push(new vector<NestedInteger>);
		}
		else if(c==','||c==']'){
			if(hasnumber){
				hasnumber=false;
				if(minus){
					minus=false;
					val*=-1;
				}
				S.top()->emplace_back(val);
				val=0;
			}
			else{
				if(last){
					auto p=NestedInteger();
					for(auto a:*last)p.add(a);
					S.top()->emplace_back(p);
					delete last;
					last=nullptr;
				}
			}
			if(c==']'){
				last=S.top();
				S.pop();
			}
		}
		else{
			hasnumber=true;
			if(c=='-')minus=true;
			else{
				val=val*10+(c-'0');
			}
		}
	}
	if(hasnumber)return NestedInteger(minus?-val:val);
	else{
		auto p=NestedInteger();
		if(last){
			for(auto a:*last)p.add(a);
			delete last;
		}
		return p;
	}
}
#endif

// 图问题，二维矩阵问题
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
// 数字转字符串，指定进制
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
ll s2i(const string&s){
	int signal=1,idx=0;
	ll val=0;
	if(s[0]=='-'){
		signal=-1;
		idx++;
	}
	while(idx<s.size())val=val*10+s[idx++]-'0';
	return signal*val;
}
// 字符串转数字，指定进制
ll s2i(const string&s,int radix){
	int signal=1,idx=0;
	ll val=0;
	if(s[0]=='-'){
		signal=-1;
		idx++;
	}
	while(idx<s.size())val=val*radix+s[idx++]-'0';
	return signal*val;
}


// 最大公约数
ll gcd(ll a, ll b){
	a = abs(a);b = abs(b);
	if (a < b)swap(a, b);
	while (b){
		ll temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

// 最小公倍数
ll lcm(ll a, ll b){
	ll _gcd=gcd(a,b);
	return a / _gcd * b;
}

// 阶乘
ll factorial(ll a){
	if(a>0)return factorial(a-1)*a;
	else return 1;
}

//求逆元
void extgcd(ll a,ll b,ll& x,ll& y){
	if(!a){x=0,y=1;}
	else{extgcd(b%a,a,y,x);x-=(b/a)*y;}
}
ll inv(ll a,ll mod=1000000007){
    ll x,y;
    extgcd(a,mod,x,y);
    return (x+mod)%mod;
}

//组合数
ll combination(ll m, ll n, ll mod=1000000007){
	if(m<=20){
		auto getf=[](){
			vector<ll>f(21);
			for(int i=0;i<=20;i++)f[i]=i?f[i-1]*i:1;
			return f;
		};
		static vector<ll>f=getf();
		return f[m]/f[n]/f[m-n];
	}
	else{
		auto getf=[&](){
			vector<ll>f(21,0);
			for(int i=1;i<=20;i++)f[i]=inv(i,mod);
			return f;
		};
		static vector<ll>f=getf();
		ll res=1;
		if(n>m/2)n=m-n;
		for(int i=0;i<n;i++)res=res*(m-i)%mod;
		for(int i=1;i<=n;i++)res=res*f[i]%mod;
		return res;
	}
}

//n较大时，排列组合打表
vvi combinationTable(int m,int n,int mod=1000000007){
	vvi table(m,vi(n,0));
	for(int j=1;j<n;j++){
		for(int i=1;i<m;i++){
			if(j==1)table[i][j]=i;
			else table[i][j]=(table[i-1][j]+table[i-1][j-1])%mod;
		}
	}
	return table;
}

// 判质
bool isprime(ll n){
	if(n<2)return false;
	if(n==2)return true;
	if(n%2==0)return false;
	for(int i=3;i<=sqrt(n);i+=2)if(n%i==0)return false;
	return true;
}

//质因数分解
vi getprime(int range){
	vi primes{2};
	bitset<200000>b;
	for(int i=3;i<=range;i+=2){
		if(!b[i]){
			primes.push_back(i);
			for(int j=i*3;j<=range;j+=i*2){
				b.set(j);
			}
		}
	}
	return primes;
}
vi getFactor(ll n,ll range=10000){
	static vector<int>primes=getprime(range);
	vector<int>ans;
	for(int a:primes){
		if(a*a>n)break;
		while(n%a==0){
			n/=a;
			ans.push_back(a);
		}
	}
	if(n>1)ans.push_back(n);
	return ans;
}

// 前缀和
vector<ll> presum(vi&a){
	vector<ll> v(a.size() + 1,0);
	REP(i, a.size())v[i + 1] = v[i] + a[i];
	return v;
}

// 下一个不同处
template<class T>
vi next_different(vector<T>&a){
	vi v(a.size());
	for(int i=0,j;i<a.size();){
		for(j=i+1;j<a.size()&&a[j]==a[i];j++);
		while(i<j)v[i++]=j;
	}
	return v;
}

// 上一个不同处
template<class T>
vi prev_different(vector<T>&a){
	vi v(a.size());
	for(int i=int(a.size())-1,j;i>=0;){
		for(j=i-1;j>=0&&a[j]==a[i];j--);
		while(i>j)v[i--]=j;
	}
	return v;
}

// 获取每个元素的排名(无并列)
template<class T>
vi getrank(vector<T>&a){
	int idx[a.size()];
	iota(idx,idx+a.size(),0);
	sort(idx,idx+a.size(),[&](int x,int y)->bool{return a[x]<a[y];});
	vi rnk(a.size());
	REP(i,a.size())rnk[idx[i]]=i;
	return rnk;
}

// 获取每个元素的排名(算并列)，离散化
template<class T>
vi getrank2(vector<T>&a){
	int idx[a.size()];
	iota(idx,idx+a.size(),0);
	sort(idx,idx+a.size(),[&](int x,int y)->bool{return a[x]<a[y];});
	vi rnk(a.size());
	for(int i=0,j,k=0;i<a.size();k++){
		for(j=i+1;j<a.size()&&a[idx[j]]==a[idx[i]];j++);
		while(i<j)rnk[idx[i++]]=k;
	}
	return rnk;
}

// 链表转结点数组
#ifdef OLDYAN_LISTNODE
vector<ListNode*> listtoarr(ListNode* p) {
	vector<ListNode*>v;
	while (p) {
		v.pb(p);
		p = p->next;
	}
	return v;
}
#endif

// 结点数组转链表
#ifdef OLDYAN_LISTNODE
ListNode* arrtolist(vector<ListNode*>&arr){
	if(arr.empty())return nullptr;
	REP(i,arr.size()){
		if(i+1<arr.size())arr[i]->next=arr[i+1];
		else arr[i]->next=nullptr;
	}
	return arr[0];
}
#endif

// 求KMP算法的next数组
vi getnext(const string&needle){
	vi next(needle.size());
	for(int i=0,j=-1;i<needle.size();i++){
		if(!i)next[i]=j;
		else{
			while(j>=0&&needle[i-1]!=needle[j])j=next[j];
			next[i]=++j>=0&&needle[i]==needle[j]?next[j]:j;
		}
	}
	return next;
}

// 求马拉车算法的臂长数组
vi getarm(const string&s){
	string s2="^#";
    for(char c:s){
		s2+=c;
		s2+="#";
	}
    s2+='$';
	int middle,maxright=0;
	vi arm(s2.size(),0);
	FOR(i,1,s2.size()-1){
		if(i<=maxright){
			int opp=middle*2-i;
			if(opp-arm[opp]==middle*2-maxright){
				int l=i-arm[opp],r=i+arm[opp];
				while(l>0&&r<s2.size()&&s2[l-1]==s2[r+1]){l--,r++;}
				arm[i]=r-i;
				if(chmax(maxright,r))middle=i;
			}
			else arm[i]=min(arm[opp],maxright-int(i));
		}
		else{
			int l=i,r=i;
			while(l>0&&r<s2.size()&&s2[l-1]==s2[r+1]){l--,r++;}
			arm[i]=r-i;
			if(chmax(maxright,r))middle=i;
		}
	}
	return arm;
}

//借助臂长数组查询对称情况
bool query_polindromic(vi&arm,int l,int r){
	return arm[l+r+2]>=r-l;
}

// 判断是否对称
template<class iterator>
bool isPolindromic(iterator begin,iterator end){
	while(begin<end){
		if(*begin++!=*--end)return false;
	}
	return true;
}

//判断从cur到next再到query的拐弯方向
//左拐返回2，右拐返回4，不变线的话前进返回1，后退小步返回-1，后退大步返回3
//对cur与next重合、query与cur重合、query与next重合的情况无定义
template<class T>
int getDirection(T*cur,T*next,T*query){
	T x1=*next-*cur;
	T y1=*(next+1)-*(cur+1);
	T x2=*query-*next;
	T y2=*(query+1)-*(next+1);
	T res=x1*y2-x2*y1;
	if(res>0)return 2;
	else if(res<0)return 4;
	res=x1*x2+y1*y2;
	if(res>0)return 1;
	else if(abs(x2)<abs(x1)||abs(y2)<abs(y1))return -1;
	else return 3;
}
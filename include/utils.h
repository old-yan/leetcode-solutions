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
#include <numeric>
#include <functional>
// 自己写的头文件太多会拖慢编译速度，平时没有必要都include进来，可以include常用的，或者在主文件再include
using namespace std;
#define LOCAL_DEBUG

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const double EPS=1e-8;
const double PI=acos(-1);
const ll MOD=1000000007;
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#ifdef LOCAL_DEBUG
#define DBGVV(a) cout << #a << " : \n";for(ll i=0;i<a.size();i++){DBGV(a[i])};
#define DBGV(a) cout << #a << " : ";for(auto b:a)cout << b << ' ';cout << endl;
#define DBG(a) cout << #a << " : " << a << endl;
#else
#define DBGVV(a)
#define DBGV(a)
#define DBG(a)
#endif
#define ALL(v) v.begin(), v.end()
#define ALLR(v) v.rbegin(), v.rend()
#define VALID (ii>=0&&ii<m&&jj>=0&&jj<n)
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
const int di[] = { 0,-1,0,1,0 };
const int dj[] = { 1,0,-1,0,0 };

// 数字转字符串，指定进制
string i2s(ll x,int radix=10){
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

// 字符串转数字，指定进制
ll s2i(const string&s,int radix=10){
	int signal=1,idx=0;
	ll val=0;
	if(s[0]=='-'){
		signal=-1;
		idx++;
	}
	while(idx<s.size())val=val*radix+s[idx++]-'0';
	return signal*val;
}

//字符串切割
vector<string> split(const string&s,char c=' '){
	vector<string>res;
	for(int i=s.find_first_not_of(c),j;i>=0&&i<s.size();i=s.find_first_not_of(c,j)){
		j=s.find_first_of(c,i);
		res.emplace_back(&s[i],j>=0?&s[j]:&s[s.size()]);
	}
	return res;
}

// 最大公约数
ll mygcd(ll a, ll b){
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
ll mylcm(ll a, ll b){
	ll _gcd=mygcd(a,b);
	return a / _gcd * b;
}

// 阶乘
ll factorial(ll a, ll mod=MOD){
	if(a>0)return factorial(a-1,mod)*a%mod;
	else return 1;
}

//阶乘表
vi factorialTable(ll m, ll mod=MOD){
	vi f(m+1);
	for(int i=0;i<=m;i++)f[i]=i?(ll)f[i-1]*i%MOD:1;
	return f;
}

//快速幂
ll fastPower(ll a,ll n,ll mod=1000000007){
	ll res=1;
	while(n){
		if(n&1)res=res*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return res;
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

//求逆元表
vi invTable(ll m, ll mod=1000000007){
	vi table(m+1,1);
	for(int i=2;i<=m;i++){
		table[i]=(mod-mod/i)*table[mod%i]%mod;
	}
	return table;
}

//组合数
ll combination(ll m, ll n, ll mod=1000000007){
	if(m<=20){
		static vector<ll>f=[](){
			vector<ll>f(21);
			for(int i=0;i<=20;i++)f[i]=i?f[i-1]*i:1;
			return f;
		}();
		return f[m]/f[n]/f[m-n];
	}
	else{
		static vector<ll>f=[&](){
			vector<ll>f(21,0);
			for(int i=1;i<=20;i++)f[i]=inv(i,mod);
			return f;
		}();
		ll res=1;
		if(n>m/2)n=m-n;
		for(int i=0;i<n;i++)res=res*(m-i)%mod;
		for(int i=1;i<=n;i++)res=res*f[i]%mod;
		return res;
	}
}

//n较大时，排列组合打表
vvi combinationTable(int m,int n,int mod=1000000007){
	vvi table(m+1,vi(n+1,0));
	table[0][0]=1;
	for(int i=1;i<=m;i++){
		table[i][0]=1;
		for(int j=1;j<=n;j++)table[i][j]=(table[i-1][j]+table[i-1][j-1])%mod;
	}
	return table;
}

// 前缀最大
vector<int> premax(vi&a){
	vector<int> v(a.size(),0);
	REP(i, a.size())v[i] =i? max(v[i-1],a[i]):a[i];
	return v;
}

// 前缀最小
vector<int> premin(vi&a){
	vector<int> v(a.size(),0);
	REP(i, a.size())v[i] =i? min(v[i-1],a[i]):a[i];
	return v;
}

// 后缀最大
vector<int> postmax(vi&a){
	vector<int> v(a.size(),0);
	REPR(i, a.size()-1)v[i] =i+1<a.size()? max(v[i+1],a[i]):a[i];
	return v;
}

// 后缀最小
vector<int> postmin(vi&a){
	vector<int> v(a.size(),0);
	REPR(i, a.size()-1)v[i] =i+1<a.size()? min(v[i+1],a[i]):a[i];
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
vi next_different(const string&a){
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
vi prev_different(const string&a){
	vi v(a.size());
	for(int i=int(a.size())-1,j;i>=0;){
		for(j=i-1;j>=0&&a[j]==a[i];j--);
		while(i>j)v[i--]=j;
	}
	return v;
}

// 获取一个数组内的所有可能的子序列和（升序放置）
vi getSubsequenceSum(vi&nums){
	int nonzero=0;
	for(int a:nums)if(a)nonzero++;
	vector<int>v(1<<min(20,nonzero),0);
	int size=1;
	for(int a:nums){
		if(!a)continue;
		int duplicate=0;
		for(int i=0,j=0;i<size&&j<size;){
			if(v[i]+a==v[j]){
				duplicate++,i++,j++;
			}
			else if(v[i]+a<v[j])i++;
			else j++;
		}
		int i=size-1,j=size-1;
		size=size*2-duplicate;
		int k=size-1;
		while(i>=0&&j>=0){
			if(v[i]==v[j]+a){
				v[k--]=v[i--];j--;
			}
			else if(v[i]>v[j]+a)v[k--]=v[i--];
			else v[k--]=v[j--]+a;
		}
		while(j>=0)v[k--]=v[j--]+a;
	}
	v.resize(size);
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
			next[i]=needle[i]==needle[++j]?next[j]:j;
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
bool isPalindromic(iterator begin,iterator end){
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

vvi makevvi(string s){
	s.erase(remove(ALL(s),' '),s.end());
	if(s[1]=='[')s=s.substr(1);
	if(s[s.size()-2]==']')s.pop_back();
	vvi res;
	for(int i=1,j;i<s.size()&&s[i]!=']';){
		res.pb(vi());
		while(s[i]!=']'){
			j=min(s.find_first_of(']',i),s.find_first_of(',',i));
			res.back().pb(s2i(s.substr(i,j-i)));
			if(s[j]==',')i=j+1;
			else i=j;
		}
		if(i==s.size()-1)break;
		else i+=3;
	}
	return res;
}
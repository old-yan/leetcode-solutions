#include "utils.h"

typedef long long ll;typedef vector<int> vi;typedef vector<vector<int>> vvi;
const double EPS=1e-7,PI=acos(-1);const ll MOD=1000000007;
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#ifdef LOCAL_DEBUG
#define DBGVV(a) cout << #a << " : \n";for(ll i=0;i<a.size();i++){DBG(i)DBGV(a[i])};
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
template <class T>bool chmax(T& a, const T& b){if (a < b){a = b;return 1;}return 0;}
template <class T>bool chmin(T& a, const T& b){if (b < a){a = b;return 1;}return 0;}
const int di[] = { 0,-1,0,1 };const int dj[] = { 1,0,-1,0 };

int pos[80000];
class BlackBox {
    struct loop{
        vi pts;
        set<int>opened;
        loop(vi&_pts):pts(_pts){
            REP(i,pts.size())pos[pts[i]]=i;
        }
        void open(int p){
            opened.insert(pos[p]);
        }
        void close(int p){
            opened.erase(pos[p]);
        }
        int next(int p){
            auto find=opened.upper_bound(pos[p]);
            if(find==opened.end())find=opened.begin();
            return pts[*find];
        }
    };
    int m,n,all;
    vi belong;
    vector<loop>ls;
    int Next(int cur){
        int index=cur/2;
        int dir=cur%2;
        if(dir)return (all+n*2-index)%all*2;
        else return (all-index)%all*2+1;
    }
public:
    BlackBox(int _m, int _n):m(_m),n(_n),all(m*2+n*2) {
        belong.resize(all*2,-1);
        REP(i,all*2)if(belong[i]<0){
            int cur=i;
            vi pts;
            while(true){
                pts.pb(cur);
                cur=Next(cur);
                if(cur==i)break;
            }
            for(auto p:pts)belong[p]=ls.size();
            ls.emplace_back(pts);
        }
    }
    int open(int index, int direction) {
        ls[belong[index*2]].open(index*2);
        ls[belong[index*2+1]].open(index*2+1);
        int cur=index*2+(direction>0?0:1);
        return ls[belong[cur]].next(cur)/2;
    }
    void close(int index) {
        ls[belong[index*2]].close(index*2);
        ls[belong[index*2+1]].close(index*2+1);
    }
};

int main()
{
    cout<<boolalpha;

	BlackBox*obj=new BlackBox(2,3);
	DBG(obj->open(6,-1));
	DBG(obj->open(4,-1));
	DBG(obj->open(0,-1));
	obj->close(6);
	DBG(obj->open(0,-1));

    system("pause");
    return 0;
}
/*
使用如下正则替换将leetcode测试用例转换为代码
首先将leetcode测试样例复制到代码正文中，把换行符删除，两行合并为一行;
将如下替换使用一次(也可以自己手打)：

\["(.+?)"(.*?)\]\[\[(.*?)\](.*)\]
\t$1*obj=new $1($3);\n[$2][$4]

将如下替换连续使用：

\[,"(.+?)"(.*?)\]\[,\[(.*?)\](.*)\]
\tobj->$1($3);\n[$2][$4]

*/
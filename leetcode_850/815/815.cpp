#include "utils.h"

typedef long long ll;
using vi = vector<int>;using vvi = vector<vector<int>>;
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
#define ALLR(v) v.rbegin(), v.rend()
#define VALID (ii>=0&&ii<m&&jj>=0&&jj<n)
#define pb push_back
template <class T>
bool chmax(T& a, const T& b){if (a < b){a = b;return 1;}return 0;}
template <class T>
bool chmin(T& a, const T& b){if (b < a){a = b;return 1;}return 0;}
const int di[] = { 0,-1,0,1 };const int dj[] = { 1,0,-1,0 };

class Solution {
    bool check(vector<int>&A,vector<int>&B){
        if(A[0]>B.back()||A.back()<B[0])return false;
        for(int i=0,j=0;i<A.size()&&j<B.size();){
            if(A[i]<B[j])i++;
            else if(A[i]>B[j])j++;
            else return true;
        }
        return false;
    }
    vi adj[500];
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        for(auto&route:routes)sort(ALL(route));
        queue<int>Q;
        bitset<500>visited;
        bitset<500>can;
        REP(i,routes.size()){
            if(binary_search(ALL(routes[i]),source)){
                Q.push(i);
                visited.set(i);
            }
            if(binary_search(ALL(routes[i]),target)){
                if(visited[i])return 1;
                can.set(i);
            }
            REP(j,i){
                if(check(routes[i],routes[j])){
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
            }
        }
        int len=2;
        while(int l=Q.size()){
            while(l--){
                auto p=Q.front();
                Q.pop();
                for(int a:adj[p]){
                    if(!visited[a]){
                        if(can[a])return len;
                        visited.set(a);
                        Q.push(a);
                    }
                }
            }
            len++;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi routes=makevvi("[[1,2,7],[3,6,7]]");
    int source=1;
    int target=6;
    auto ans=sol.numBusesToDestination(routes,source,target);
    DBG(ans);

    system("pause");
    return 0;
}

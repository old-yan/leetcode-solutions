#include "Union.h"
#include "utils.h"

Union u(1000);
class Solution {
public:
    //本题一看就是并查集
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        u.reset();
        // 使用 bitset 进行压位，增加效率
        // self[i] 记录 i 所在团伙的人
        // avoid[i] 记录 i 所在团伙的人要避开的人
        bitset<1000>self[n],avoid[n];
        for(auto&r:restrictions){
            int a=r[0],b=r[1];
            avoid[a].set(b);
            avoid[b].set(a);
        }
        for(int i=0;i<n;i++)
            self[i].set(i);
        vector<bool>ans;
        for(auto&r:requests){
            //直接找到 r[0] 和 r[1] 所在团伙的老大 a 和 b
            int a=u.Find(r[0]),b=u.Find(r[1]);
            //如果是一个团伙，那么肯定可以当朋友
            if(a==b){
                ans.push_back(true);
                continue;
            }
            //如果存在某个人，身处 a 团伙，却是 b 团伙不想见到的人，那么交朋友失败
            //(此处无需判断身处 b 团伙，却是 a 团伙不想见到的人的情况，因为情况都是对称存在的)
            if((self[a]&avoid[b]).count()){
                ans.push_back(false);
            }
            //否则，交朋友成功，两个团伙合并，不妨把 b 团伙的信息合并到 a
            else{
                u.find[b]=a;
                self[a]|=self[b];
                avoid[a]|=avoid[b];
                ans.push_back(true);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    vector<vector<int>>restrictions=makevvi("[[0,1],[1,2],[2,3]]");
    vector<vector<int>>requests=makevvi("[[0,4],[1,2],[3,1],[3,4]]");
    auto ans=sol.friendRequests(n,restrictions,requests);
    DBGV(ans);

    system("pause");
    return 0;
}
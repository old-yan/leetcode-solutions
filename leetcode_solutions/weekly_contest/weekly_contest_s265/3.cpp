#include "utils.h"

class Solution {
public:
    //本题为经典 BFS 模型
    int minimumOperations(vector<int>& nums, int start, int goal) {
        //为了防止[0,1000]重复入队，所以要加个vis数组
        //小于0 和 大于1000的数字根本不入队，所以不用管
        vector<int>vis(1001,INT_MAX);
        queue<int>Q;
        vis[start]=0;
        Q.push(start);
        while(Q.size()){
            //cur为队首元素
            auto cur=Q.front();
            Q.pop();
            // a 表示 nums 元素，变形的媒介
            for(int a:nums){
                // b 表示 cur 通过媒介变形的结果
                for(int b:{cur+a,cur-a,cur^a}){
                    // 当第一次遇到 goal，直接返回答案
                    if(b==goal)return vis[cur]+1;
                    //  如果 b不为goal且b在[0,1000]范围内且首次访问，将b入队
                    if(b>=0 and b<=1000 and vis[b]==INT_MAX){
                        vis[b]=vis[cur]+1;
                        Q.push(b);
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>nums{3,5,7};
    int start=0;
    int goal=-4;
    auto ans=sol.minimumOperations(nums,start,goal);
    DBG(ans);

    system("pause");
    return 0;
}
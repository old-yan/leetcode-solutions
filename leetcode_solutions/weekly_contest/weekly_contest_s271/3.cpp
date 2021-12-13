#include "utils.h"

class Solution {
public:
    //本题模拟即可
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int curA=capacityA,curB=capacityB;
        int n=plants.size();
        //写一个 deal 函数，输入现在水量、要浇的水、满水量，返回值为灌的次数
        auto deal=[](int&cur,int todeal,int full){
            //如果够用，直接浇水
            if(cur>=todeal){
                cur-=todeal;
                return 0;
            }
            //如果不够用，但是是满的，那么一开始省掉一次灌满
            else if(cur==full){
                // need 为总共需要接多少水
                int need=(todeal+full-1)/full*full;
                // cur 变为用剩下的
                cur=need-todeal;
                // 返回接的水次数减一
                return need/full-1;
            }
            //如果不够用，但是不是满的，那么一开始要灌满一次
            else{
                // need 为总共需要接多少水
                int need=(todeal+full-1)/full*full;
                // cur 变为用剩下的
                cur=need-todeal;
                // 返回接的水次数
                return need/full;
            }
        };
        int ans=0;
        for(int i=0;i<n/2;i++)ans+=deal(curA,plants[i],capacityA);
        for(int i=n-1;i>=(n+1)/2;i--)ans+=deal(curB,plants[i],capacityB);
        if(n%2){
            if(curA>=curB)ans+=deal(curA,plants[n/2],capacityA);
            else ans+=deal(curB,plants[n/2],capacityB);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>plants{1,2,4,4,5;
    int capacityA=6;
    int capacityB=5;
    auto ans=sol.minimumRefill(plants,capacityA,capacityB);
    DBG(ans);

    system("pause");
    return 0;
}
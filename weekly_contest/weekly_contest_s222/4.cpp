#include "utils.h"

class Solution {
public:
    //本题可以理解为求target和arr中出现的最长公共子序列长度
    int minOperations(vector<int>& target, vector<int>& arr) {
        //线段树是统计一个区间之内的最大值的有力工具
        SegTree<int> T(target.size(),0,[](int x,int y){return max(x,y);});
        //M记录每个数字对应的在target数组中的位置(target中元素不重复)
        unordered_map<int,int>M;
        for(int i=0;i<target.size();i++)M[target[i]]=i;
        int k=0;
        for(int i=0;i<arr.size();i++){
            //对arr中每个元素，统计以其为结尾的最长公共子序列长度
            int j=arr[i];
            if(M.count(j)){
                //T[i]表示target[i]及之前出现的最长公共子序列
                //比如当前元素j在target中下标为M[j]=5
                //利用线段树统计[0,4]间的最大值，即以下标0~4为结尾的最长公共子序列长度
                k=T(0,M[j]-1);
                //再加一，就是以下标5为结尾的最长公共子序列长度，记录到树中
                T.set(M[j],k+1);
            }
        }
        //统计出最长公共子序列，再把缺的补上即可
        return target.size()-T(0,target.size()-1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi target{6,4,8,1,3,2};
    vi arr{4,7,6,2,3,8,6,1};
    auto ans=sol.minOperations(target,arr);
    DBG(ans);

    system("pause");
    return 0;
}

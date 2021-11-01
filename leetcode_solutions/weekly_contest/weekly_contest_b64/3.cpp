#include "utils.h"

class Solution {
public:
    //对于每一个子区间，只要把区间两端的盘子去掉，剩下的盘子就是要找的盘子
    //可以预处理出每个位置向左/向右有多少个连续盘子
    //区间左端的盘子=从区间左端点，向右有多少个连续盘子
    //区间右端的盘子=从区间右端点，向左有多少个连续盘子
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        //前缀和
        vector<int>presum{0};
        for(int i=0;i<s.size();i++){
            if(s[i]=='*')presum.push_back(presum.back()+1);
            else presum.push_back(presum.back());
        }
        //每个位置向右，有多少个连续盘子
        vector<int>rightPlate(s.size());
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='*')rightPlate[i]=i==s.size()-1?1:rightPlate[i+1]+1;
            else rightPlate[i]=0;
        }
        //每个位置向左，有多少个连续盘子
        vector<int>leftPlate(s.size());
        for(int i=0;i<s.size();i++){
            if(s[i]=='*')leftPlate[i]=i==0?1:leftPlate[i-1]+1;
            else leftPlate[i]=0;
        }
        vector<int>ans;
        for(auto&q:queries){
            int l=q[0],r=q[1];
            int left=rightPlate[l];
            int right=leftPlate[r];
            //前缀和做差，获取盘子总数，再减去左端的盘子，再减去右端的盘子
            ans.push_back(max(0,presum[r+1]-presum[l]-left-right));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="***|**|*****|**||**|*";
    vector<vector<int>>queries=makevvi("[[1,17],[4,5],[14,17],[5,11],[15,16]]");
    auto ans=sol.platesBetweenCandles(s,queries);
    DBGV(ans);

    system("pause");
    return 0;
}